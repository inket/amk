
MCU = GD32E505
TINYUSB_ENABLE = yes
RGB_LINEAR_ENABLE = yes
VIAL_ENABLE = yes
EECONFIG_FLASH = yes
NKRO_ENABLE = yes
AMK_CUSTOM_MATRIX = yes

DEBOUNCE_TYPE = asym_eager_defer_pk

RTOS_ENABLE = yes
UF2_ENABLE = yes
UF2_FAMILY = GD32E5

SRCS += $(KEYBOARD_DIR)/rabbit60.c
SRCS += $(KEYBOARD_DIR)/custom_matrix.c

LINKER_PATH = $(KEYBOARD_DIR)

OPT += -Wno-cpp