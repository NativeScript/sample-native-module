LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := NativeScript
ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
    LOCAL_SRC_FILES := libs/arm/libNativeScript.so
else ifeq ($(TARGET_ARCH_ABI),arm64-v8a)
    LOCAL_SRC_FILES := libs/arm64/libNativeScript.so
else ifeq ($(TARGET_ARCH_ABI),x86)
    LOCAL_SRC_FILES := libs/x86/libNativeScript.so
endif
include $(PREBUILT_SHARED_LIBRARY)


include $(CLEAR_VARS)
LOCAL_MODULE    := Calc
LOCAL_SRC_FILES := Calc.cpp
LOCAL_SHARED_LIBRARIES := NativeScript
include $(BUILD_SHARED_LIBRARY)
