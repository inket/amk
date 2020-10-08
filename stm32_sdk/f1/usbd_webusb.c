/**
 * @file usbd_webusb.c
 */

#include "usbd_webusb.h"
#include "usbd_ctlreq.h"
#include "usb_descriptors.h"
#include "rtt.h"

static uint8_t  USBD_WEBUSB_Setup(USBD_HandleTypeDef *pdev, USBD_SetupReqTypedef *req, void* user); 
static uint8_t  USBD_WEBUSB_DataIn(USBD_HandleTypeDef *pdev, uint8_t epnum, void* user);
static uint8_t  USBD_WEBUSB_DataOut(USBD_HandleTypeDef *pdev, uint8_t epnum, void* user);
static uint8_t  USBD_WEBUSB_Write(USBD_HandleTypeDef *pdev, uint8_t epnum, uint8_t* data, uint16_t size, void* user);

usbd_class_interface_t USBD_WEBUSB = {
    USBD_WEBUSB_Setup,
    USBD_WEBUSB_DataIn,
    USBD_WEBUSB_DataOut,
    USBD_WEBUSB_Write,
};

static uint8_t  USBD_WEBUSB_Setup(USBD_HandleTypeDef *pdev, USBD_SetupReqTypedef *req, void* user)
{
    uint16_t len = 0U;
    uint8_t *pbuf = NULL;
    USBD_StatusTypeDef ret = USBD_OK;

    if ((req->bmRequest&USB_REQ_TYPE_MASK) == USB_REQ_TYPE_VENDOR) {
        switch (req->bRequest) {
        case VENDOR_REQUEST_WEBUSB: {
            len = tud_descriptor_url_size();
            pbuf = tud_descriptor_url_cb();
            rtt_printf("WEBUSB Setup: size=%d\n", len);
        } break;
        case VENDOR_REQUEST_MICROSOFT: {
            if ( req->wIndex == 7 ) {
                len = tud_descriptor_msos20_size();
                pbuf = tud_descriptor_msos20_cb();
                rtt_printf("Microsoft Setup: size=%d\n", len);
            }
        } break;
        default:
            break;
        }
    }

    if (len > 0) {
        ret = USBD_CtlSendData(pdev, pbuf, len);
    }

    return ret;
}

static uint8_t  USBD_WEBUSB_DataIn(USBD_HandleTypeDef *pdev, uint8_t epnum, void* user)
{
    USBD_WEBUSB_HandleTypeDef* hwusb = (USBD_WEBUSB_HandleTypeDef*)user;
    hwusb->state = WEBUSB_IDLE;
    return USBD_OK;
}

static uint8_t  USBD_WEBUSB_DataOut(USBD_HandleTypeDef *pdev, uint8_t epnum, void* user)
{
    USBD_WEBUSB_HandleTypeDef* hwusb = (USBD_WEBUSB_HandleTypeDef*)user;
    rtt_printf("WEBUSB DataOut: epnum=%d status=%d, is_used=%d total_length=%d, rem_length=%d\n",
            epnum,
            pdev->ep_out[epnum].status,
            pdev->ep_out[epnum].is_used,
            pdev->ep_out[epnum].total_length,
            pdev->ep_out[epnum].rem_length);

    // just write back
    USBD_WEBUSB_Write(pdev, epnum, hwusb->recv_buffer, WEBUSB_PACKET_SIZE, user);

    USBD_LL_PrepareReceive(pdev, epnum, hwusb->recv_buffer, WEBUSB_PACKET_SIZE);
    return USBD_OK;
}

static uint8_t  USBD_WEBUSB_Write(USBD_HandleTypeDef *pdev, uint8_t epnum, uint8_t* data, uint16_t size, void* user)
{
    USBD_WEBUSB_HandleTypeDef* hwusb = (USBD_WEBUSB_HandleTypeDef*)user;
    if (hwusb->state == WEBUSB_IDLE) {
        hwusb->state = WEBUSB_BUSY;
        memcpy(hwusb->send_buffer, data, size);
        return USBD_LL_Transmit(pdev, epnum, hwusb->send_buffer, size);
    } else {
        return USBD_BUSY;
    }
}