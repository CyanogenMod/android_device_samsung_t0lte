#
# Copyright (C) 2013 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# This variable is set first, so it can be overridden
# by BoardConfigVendor.mk

LOCAL_PATH := device/samsung/t0lte

# Bluetooth
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := $(LOCAL_PATH)/bluetooth
BOARD_BLUEDROID_VENDOR_CONF := $(LOCAL_PATH)/bluetooth/vnd_t0lte.txt

# RIL
COMMON_GLOBAL_CFLAGS += -DPROPERTY_PERMS_APPEND='{ "ril.ks.status", AID_SYSTEM, 0 },'

# Camera
COMMON_GLOBAL_CFLAGS += -DCAMERA_WITH_CITYID_PARAM

# Kernel
TARGET_KERNEL_SOURCE := kernel/samsung/smdk4412
ifeq ($(TARGET_VOICE_TECH), cdma)
TARGET_KERNEL_CONFIG := cyanogenmod_t0ltecdma_defconfig
else
TARGET_KERNEL_CONFIG := cyanogenmod_t0lte_defconfig
endif

# Recovery
TARGET_RECOVERY_FSTAB := device/samsung/t0lte/rootdir/fstab.smdk4x12
RECOVERY_FSTAB_VERSION := 2

# assert
TARGET_OTA_ASSERT_DEVICE := t0lte,t0ltexx,GT-N7105,t0ltedv,GT-N7105T,t0lteatt,SGH-I317,t0ltetmo,SGH-T889,t0ltecan,t0ltevl,SGH-I317M

# Selinux
BOARD_SEPOLICY_DIRS += \
    device/samsung/t0lte/selinux

BOARD_SEPOLICY_UNION += \
    bluetooth.te \
    radio.te \
    file_contexts \
    te_macros \
    device.te \
    dhcp.te \
    domain.te \
    file.te \
    init.te \
    kickstart.te \
    mediaserver.te \
    netd.te \
    netmgrd.te \
    nfc.te \
    qmiproxy.te \
    qmuxd.te \
    rild.te \
    secril.te \
    servicemanager.te \
    sysinit.te \
    system.te \
    system_app.te \
    system_server.te \
    time_daemon.te \
    ueventd.te \
    vold.te \
    wpa.te \
    wpa_supplicant.te \
    zygote.te

