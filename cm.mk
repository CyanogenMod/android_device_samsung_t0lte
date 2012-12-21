## Specify phone tech before including full_phone
$(call inherit-product, vendor/cm/config/gsm.mk)

# Release name
PRODUCT_RELEASE_NAME := t0lte

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

# Inherit device configuration
$(call inherit-product, device/samsung/t0lte/device_t0lte.mk)

## Device identifier. This must come after all inclusions
PRODUCT_DEVICE := t0lte
PRODUCT_NAME := cm_t0lte
PRODUCT_BRAND := samsung
PRODUCT_MODEL := t0lte
PRODUCT_MANUFACTURER := samsung
