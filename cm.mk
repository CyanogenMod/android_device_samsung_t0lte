# Specify phone tech before including full_phone
$(call inherit-product, vendor/cm/config/gsm.mk)

# Release name
PRODUCT_RELEASE_NAME := t0lte

# Boot animation
TARGET_SCREEN_HEIGHT := 1280
TARGET_SCREEN_WIDTH := 720

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

# Inherit device configuration
$(call inherit-product, device/samsung/t0lte/full_t0lte.mk)

# Device identifier. This must come after all inclusions
PRODUCT_NAME := cm_t0lte
PRODUCT_BRAND := samsung
PRODUCT_MODEL := GT-N7105
PRODUCT_MANUFACTURER := samsung
