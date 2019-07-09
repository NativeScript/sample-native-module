cmake_minimum_required(VERSION 3.4.1)

include_directories(
    ${PROJECT_SOURCE_DIR}/src/main/cpp/include
    ${PROJECT_SOURCE_DIR}/src/main/cpp/include/libc++
)

set(CMAKE_CXX_FLAGS "-std=c++11 -fexceptions -D_LIBCPP_ABI_VERSION=Cr -DCR_LIBCXX_REVISION=349080 -DCR_LIBCXXABI_REVISION=347903 -D_LIBCPP_ENABLE_NODISCARD -D_LIBCPP_ABI_UNSTABLE")

add_library( # Sets the name of the library. When it's built you can find it with lib prefix libCalc.so
        calc

        # Sets the library as a shared library.
        SHARED

        src/main/cpp/Calc.cpp
)

target_link_libraries( calc ${PROJECT_SOURCE_DIR}/src/main/libs/${ANDROID_ABI}/libv8.a )

if("${ANDROID_ABI}" MATCHES "armeabi-v7a" OR "${ANDROID_ABI}" MATCHES "x86")
    # On API Level 19 and lower we need to link with android_support
    # because it contains some implementation of functions such as "strtoll" and "strtoul"
    target_link_libraries(calc ${ANDROID_NDK_ROOT}/sources/cxx-stl/llvm-libc++/libs/${ANDROID_ABI}/libandroid_support.a)
endif()

find_library(system-log log)
target_link_libraries(calc ${system-log})