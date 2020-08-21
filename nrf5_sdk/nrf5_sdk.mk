
NRF5SDK_DIR := $(TOP_DIR)/nrf5_sdk/nRF5_SDK_17.0.0_9d13099

SRC_FILES += \
	$(NRF5SDK_DIR)/modules/nrfx/mdk/gcc_startup_nrf52.S \
	$(NRF5SDK_DIR)/modules/nrfx/mdk/system_nrf52.c \
	$(NRF5SDK_DIR)/components/libraries/log/src/nrf_log_backend_rtt.c \
	$(NRF5SDK_DIR)/components/libraries/log/src/nrf_log_backend_serial.c \
	$(NRF5SDK_DIR)/components/libraries/log/src/nrf_log_default_backends.c \
	$(NRF5SDK_DIR)/components/libraries/log/src/nrf_log_frontend.c \
	$(NRF5SDK_DIR)/components/libraries/log/src/nrf_log_str_formatter.c \
	$(NRF5SDK_DIR)/components/libraries/util/app_error.c \
	$(NRF5SDK_DIR)/components/libraries/util/app_error_handler_gcc.c \
	$(NRF5SDK_DIR)/components/libraries/util/app_error_weak.c \
	$(NRF5SDK_DIR)/components/libraries/util/app_util_platform.c \
	$(NRF5SDK_DIR)/components/libraries/util/nrf_assert.c \
	$(NRF5SDK_DIR)/components/libraries/scheduler/app_scheduler.c \
	$(NRF5SDK_DIR)/components/libraries/timer/app_timer2.c \
	$(NRF5SDK_DIR)/components/libraries/timer/drv_rtc.c \
	$(NRF5SDK_DIR)/components/libraries/fifo/app_fifo.c \
	$(NRF5SDK_DIR)/components/libraries/uart/app_uart_fifo.c \
	$(NRF5SDK_DIR)/components/libraries/crc16/crc16.c \
	$(NRF5SDK_DIR)/components/libraries/fds/fds.c \
	$(NRF5SDK_DIR)/components/libraries/hardfault/hardfault_implementation.c \
	$(NRF5SDK_DIR)/components/libraries/atomic_fifo/nrf_atfifo.c \
	$(NRF5SDK_DIR)/components/libraries/atomic_flags/nrf_atflags.c \
	$(NRF5SDK_DIR)/components/libraries/atomic/nrf_atomic.c \
	$(NRF5SDK_DIR)/components/libraries/balloc/nrf_balloc.c \
	$(NRF5SDK_DIR)/components/libraries/fstorage/nrf_fstorage.c \
	$(NRF5SDK_DIR)/components/libraries/fstorage/nrf_fstorage_sd.c \
	$(NRF5SDK_DIR)/components/libraries/memobj/nrf_memobj.c \
	$(NRF5SDK_DIR)/components/libraries/pwr_mgmt/nrf_pwr_mgmt.c \
	$(NRF5SDK_DIR)/components/libraries/ringbuf/nrf_ringbuf.c \
	$(NRF5SDK_DIR)/components/libraries/experimental_section_vars/nrf_section_iter.c \
	$(NRF5SDK_DIR)/components/libraries/sortlist/nrf_sortlist.c \
	$(NRF5SDK_DIR)/components/libraries/strerror/nrf_strerror.c \
	$(NRF5SDK_DIR)/components/boards/boards.c \
	$(NRF5SDK_DIR)/components/ble/ble_advertising/ble_advertising.c \
	$(NRF5SDK_DIR)/components/ble/ble_link_ctx_manager/ble_link_ctx_manager.c \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_bas/ble_bas.c \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_dis/ble_dis.c \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_hids/ble_hids.c \
	$(NRF5SDK_DIR)/components/ble/nrf_ble_gatt/nrf_ble_gatt.c \
	$(NRF5SDK_DIR)/components/ble/nrf_ble_qwr/nrf_ble_qwr.c \
	$(NRF5SDK_DIR)/components/ble/common/ble_advdata.c \
	$(NRF5SDK_DIR)/components/ble/common/ble_conn_params.c \
	$(NRF5SDK_DIR)/components/ble/common/ble_conn_state.c \
	$(NRF5SDK_DIR)/components/ble/common/ble_srv_common.c \
	$(NRF5SDK_DIR)/components/ble/peer_manager/auth_status_tracker.c \
	$(NRF5SDK_DIR)/components/ble/peer_manager/gatt_cache_manager.c \
	$(NRF5SDK_DIR)/components/ble/peer_manager/gatts_cache_manager.c \
	$(NRF5SDK_DIR)/components/ble/peer_manager/id_manager.c \
	$(NRF5SDK_DIR)/components/ble/peer_manager/peer_data_storage.c \
	$(NRF5SDK_DIR)/components/ble/peer_manager/peer_database.c \
	$(NRF5SDK_DIR)/components/ble/peer_manager/peer_id.c \
	$(NRF5SDK_DIR)/components/ble/peer_manager/peer_manager.c \
	$(NRF5SDK_DIR)/components/ble/peer_manager/peer_manager_handler.c \
	$(NRF5SDK_DIR)/components/ble/peer_manager/pm_buffer.c \
	$(NRF5SDK_DIR)/components/ble/peer_manager/security_dispatcher.c \
	$(NRF5SDK_DIR)/components/ble/peer_manager/security_manager.c \
	$(NRF5SDK_DIR)/modules/nrfx/soc/nrfx_atomic.c \
	$(NRF5SDK_DIR)/modules/nrfx/drivers/src/nrfx_clock.c \
	$(NRF5SDK_DIR)/modules/nrfx/drivers/src/nrfx_gpiote.c \
	$(NRF5SDK_DIR)/modules/nrfx/drivers/src/nrfx_pwm.c \
	$(NRF5SDK_DIR)/modules/nrfx/drivers/src/nrfx_saadc.c \
	$(NRF5SDK_DIR)/modules/nrfx/drivers/src/nrfx_uart.c \
	$(NRF5SDK_DIR)/modules/nrfx/drivers/src/nrfx_uarte.c \
	$(NRF5SDK_DIR)/modules/nrfx/drivers/src/nrfx_twi.c \
	$(NRF5SDK_DIR)/modules/nrfx/drivers/src/prs/nrfx_prs.c \
	$(NRF5SDK_DIR)/integration/nrfx/legacy/nrf_drv_clock.c \
	$(NRF5SDK_DIR)/integration/nrfx/legacy/nrf_drv_uart.c \
	$(NRF5SDK_DIR)/external/utf_converter/utf.c \
	$(NRF5SDK_DIR)/external/fprintf/nrf_fprintf.c \
	$(NRF5SDK_DIR)/external/fprintf/nrf_fprintf_format.c \
	$(NRF5SDK_DIR)/external/segger_rtt/SEGGER_RTT.c \
	$(NRF5SDK_DIR)/external/segger_rtt/SEGGER_RTT_Syscalls_GCC.c \
	$(NRF5SDK_DIR)/external/segger_rtt/SEGGER_RTT_printf.c \
	$(NRF5SDK_DIR)/components/softdevice/common/nrf_sdh.c \
	$(NRF5SDK_DIR)/components/softdevice/common/nrf_sdh_ble.c \
	$(NRF5SDK_DIR)/components/softdevice/common/nrf_sdh_soc.c \

INC_FOLDERS += \
	$(NRF5SDK_DIR)/components \
	$(NRF5SDK_DIR)/components/boards \
	$(NRF5SDK_DIR)/components/ble/common \
	$(NRF5SDK_DIR)/components/ble/ble_advertising \
	$(NRF5SDK_DIR)/components/ble/ble_dtm \
	$(NRF5SDK_DIR)/components/ble/ble_racp \
	$(NRF5SDK_DIR)/components/ble/ble_link_ctx_manager \
	$(NRF5SDK_DIR)/components/ble/nrf_ble_gatt \
	$(NRF5SDK_DIR)/components/ble/nrf_ble_qwr \
	$(NRF5SDK_DIR)/components/ble/peer_manager \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_ans_c \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_ancs_c \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_bas \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_bas_c \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_cscs \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_cts_c \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_dfu \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_dis \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_gls \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_hids \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_hts \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_hrs \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_hrs_c \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_ias \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_ias_c \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_lbs \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_lbs_c \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_lls \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_nus \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_nus_c \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_rscs \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_rscs_c \
	$(NRF5SDK_DIR)/components/ble/ble_services/ble_tps \
	$(NRF5SDK_DIR)/components/libraries/atomic \
	$(NRF5SDK_DIR)/components/libraries/atomic_fifo \
	$(NRF5SDK_DIR)/components/libraries/atomic_flags \
	$(NRF5SDK_DIR)/components/libraries/balloc \
	$(NRF5SDK_DIR)/components/libraries/bsp \
	$(NRF5SDK_DIR)/components/libraries/button \
	$(NRF5SDK_DIR)/components/libraries/bootloader/ble_dfu \
	$(NRF5SDK_DIR)/components/libraries/cli \
	$(NRF5SDK_DIR)/components/libraries/crc16 \
	$(NRF5SDK_DIR)/components/libraries/crc32 \
	$(NRF5SDK_DIR)/components/libraries/crypto \
	$(NRF5SDK_DIR)/components/libraries/csense \
	$(NRF5SDK_DIR)/components/libraries/csense_drv \
	$(NRF5SDK_DIR)/components/libraries/delay \
	$(NRF5SDK_DIR)/components/libraries/ecc \
	$(NRF5SDK_DIR)/components/libraries/experimental_section_vars \
	$(NRF5SDK_DIR)/components/libraries/experimental_task_manager \
	$(NRF5SDK_DIR)/components/libraries/fifo \
	$(NRF5SDK_DIR)/components/libraries/fds \
	$(NRF5SDK_DIR)/components/libraries/fstorage \
	$(NRF5SDK_DIR)/components/libraries/gfx \
	$(NRF5SDK_DIR)/components/libraries/gpiote \
	$(NRF5SDK_DIR)/components/libraries/hardfault \
	$(NRF5SDK_DIR)/components/libraries/hci \
	$(NRF5SDK_DIR)/components/libraries/led_softblink \
	$(NRF5SDK_DIR)/components/libraries/log \
	$(NRF5SDK_DIR)/components/libraries/log/src \
	$(NRF5SDK_DIR)/components/libraries/low_power_pwm \
	$(NRF5SDK_DIR)/components/libraries/memobj \
	$(NRF5SDK_DIR)/components/libraries/mem_manager \
	$(NRF5SDK_DIR)/components/libraries/mpu \
	$(NRF5SDK_DIR)/components/libraries/mutex \
	$(NRF5SDK_DIR)/components/libraries/pwr_mgmt \
	$(NRF5SDK_DIR)/components/libraries/pwm \
	$(NRF5SDK_DIR)/components/libraries/queue \
	$(NRF5SDK_DIR)/components/libraries/ringbuf \
	$(NRF5SDK_DIR)/components/libraries/scheduler \
	$(NRF5SDK_DIR)/components/libraries/sdcard \
	$(NRF5SDK_DIR)/components/libraries/slip \
	$(NRF5SDK_DIR)/components/libraries/sortlist \
	$(NRF5SDK_DIR)/components/libraries/spi_mngr \
	$(NRF5SDK_DIR)/components/libraries/strerror \
	$(NRF5SDK_DIR)/components/libraries/stack_guard \
	$(NRF5SDK_DIR)/components/libraries/svc \
	$(NRF5SDK_DIR)/components/libraries/timer \
	$(NRF5SDK_DIR)/components/libraries/twi_mngr \
	$(NRF5SDK_DIR)/components/libraries/twi_sensor \
	$(NRF5SDK_DIR)/components/libraries/util \
	$(NRF5SDK_DIR)/components/libraries/uart \
	$(NRF5SDK_DIR)/components/libraries/usbd \
	$(NRF5SDK_DIR)/components/libraries/usbd/class/audio \
	$(NRF5SDK_DIR)/components/libraries/usbd/class/cdc \
	$(NRF5SDK_DIR)/components/libraries/usbd/class/cdc/acm \
	$(NRF5SDK_DIR)/components/libraries/usbd/class/hid \
	$(NRF5SDK_DIR)/components/libraries/usbd/class/hid/generic \
	$(NRF5SDK_DIR)/components/libraries/usbd/class/hid/kbd \
	$(NRF5SDK_DIR)/components/libraries/usbd/class/hid/mouse \
	$(NRF5SDK_DIR)/components/libraries/usbd/class/msc \
	$(NRF5SDK_DIR)/components/softdevice/common \
	$(NRF5SDK_DIR)/components/softdevice/s132/headers \
	$(NRF5SDK_DIR)/components/softdevice/s132/headers/nrf52 \
	$(NRF5SDK_DIR)/components/toolchain/cmsis/include \
	$(NRF5SDK_DIR)/integration/nrfx/legacy \
	$(NRF5SDK_DIR)/integration/nrfx \
	$(NRF5SDK_DIR)/modules/nrfx \
	$(NRF5SDK_DIR)/modules/nrfx/mdk \
	$(NRF5SDK_DIR)/modules/nrfx/hal \
	$(NRF5SDK_DIR)/modules/nrfx/drivers/include \
	$(NRF5SDK_DIR)/external/fprintf \
	$(NRF5SDK_DIR)/external/segger_rtt \
	$(NRF5SDK_DIR)/external/utf_converter \
	$(NRF5SDK_DIR)/.. \

APP_DEFS += \
	-DAPP_UART \
	-DAPP_TIMER_V2 \
	-DAPP_TIMER_V2_RTC1_ENABLED \
	-DBOARD_CUSTOM \
	-DCONFIG_NFCT_PINS_AS_GPIOS \
	-DFLOAT_ABI_HARD \
	-DNRF52 \
	-DNRF_SD_BLE_API_VERSION=7 \
	-DSOFTDEVICE_PRESENT \
	-D__HEAP_SIZE=8192 \
	-D__STACK_SIZE=8192 \
	-DGPIO_NRF5X \
	#-DCONFIG_GPIO_AS_PINRESET \

ifeq (NRF52832, $(strip $(MCU)))
	APP_DEFS += -DNRF52832_XXAA
	APP_DEFS += -DNRF52_PAN_74
	APP_DEFS += -DS132
	LINKER_SCRIPT := $(TOP_DIR)/nrf5_sdk/nrf52832.ld
endif

ifeq (NRF52840, $(strip $(MCU)))
	SRC_FILES += $(NRF5SDK_DIR)/components/libraries/usbd/app_usbd.c
	SRC_FILES += $(NRF5SDK_DIR)/components/libraries/usbd/app_usbd_core.c
	SRC_FILES += $(NRF5SDK_DIR)/components/libraries/usbd/class/hid/app_usbd_hid.c
	SRC_FILES += $(NRF5SDK_DIR)/components/libraries/usbd/class/hid/generic/app_usbd_hid_generic.c
	SRC_FILES += $(NRF5SDK_DIR)/components/libraries/usbd/app_usbd_string_desc.c
	INC_FOLDERS += $(NRF5SDK_DIR)/components/libraries/usbd
	INC_FOLDERS += $(NRF5SDK_DIR)/components/libraries/usbd/class/hid/generic
	INC_FOLDERS += $(NRF5SDK_DIR)/components/libraries/usbd/class/hid
	APP_DEFS += -DNRF52840_XXAA
	APP_DEFS += -DS140
	LINKER_SCRIPT := $(TOP_DIR)/nrf5_sdk/nrf52840.ld
endif

LINKER_PATH := $(NRF5SDK_DIR)/modules/nrfx/mdk