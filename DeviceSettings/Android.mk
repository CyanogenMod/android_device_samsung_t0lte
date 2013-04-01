LOCAL_PATH:= $(call my-dir)

ifeq ($(TARGET_DEVICE),t0lte)

include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional

LOCAL_STATIC_JAVA_LIBRARIES := android-support-v13

LOCAL_SRC_FILES := $(call all-java-files-under, src)

LOCAL_PACKAGE_NAME := GalaxyNote2Settings
LOCAL_CERTIFICATE := platform

include $(BUILD_PACKAGE)

include $(call all-makefiles-under,$(LOCAL_PATH))

endif
