cmake_minimum_required(VERSION 3.4.1)

if ( ANDROID_ABI MATCHES "arm64" )
    set(ARCH_INCLUDE_DIR "aarch64-linux-android")
else()
    set(ARCH_INCLUDE_DIR "arm-linux-androideabi")
endif()

include_directories(
    ${PROJECT_SOURCE_DIR}/src/main/cpp/include/
    ${ANDROID_NDK_ROOT}/sysroot/usr/include/${ARCH_INCLUDE_DIR}/
)

set(CMAKE_CXX_FLAGS "-std=c++11 -fexceptions")

add_library( # Sets the name of the library. When it's built you can find it with lib prefix libCalc.so
        calc

        # Sets the library as a shared library.
        SHARED

        src/main/cpp/Calc.cpp
)

target_link_libraries( calc ${PROJECT_SOURCE_DIR}/src/main/libs/${ANDROID_ABI}/libv8_base.a )
target_link_libraries( calc ${PROJECT_SOURCE_DIR}/src/main/libs/${ANDROID_ABI}/libv8_init.a )
target_link_libraries( calc ${PROJECT_SOURCE_DIR}/src/main/libs/${ANDROID_ABI}/libv8_initializers.a )
target_link_libraries( calc ${PROJECT_SOURCE_DIR}/src/main/libs/${ANDROID_ABI}/libv8_libplatform.a )
target_link_libraries( calc ${PROJECT_SOURCE_DIR}/src/main/libs/${ANDROID_ABI}/libv8_libsampler.a )
target_link_libraries( calc ${PROJECT_SOURCE_DIR}/src/main/libs/${ANDROID_ABI}/libv8_libbase.a )
target_link_libraries( calc ${PROJECT_SOURCE_DIR}/src/main/libs/${ANDROID_ABI}/libv8_snapshot.a )
