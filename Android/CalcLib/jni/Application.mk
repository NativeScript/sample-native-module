APP_ABI := armeabi-v7a x86 arm64-v8a

APP_PLATFORM := android-17
NDK_TOOLCHAIN_VERSION := 4.8
APP_OPTIM := debug

#The new ndks require this or build fails
APP_CFLAGS += -Wno-error=format-security
APP_CFLAGS += -g
