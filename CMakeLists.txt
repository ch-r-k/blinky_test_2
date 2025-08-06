###########################################################################

cmake_minimum_required (VERSION 3.17)

set(TOOLCHAIN ARM_GCC)
set(TARGET_DEVICE RP2040)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/arm_setup/cmake")

if("${TARGET_DEVICE}" STREQUAL "X86")
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/src/hardware_x86/platform")
elseif("${TARGET_DEVICE}" STREQUAL "RP2040")
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/src/hardware_rp2040/platform")
else()
    message(FATAL_ERROR "unsupported target: ${TARGET_DEVICE}")
endif()

if("${TOOLCHAIN}" STREQUAL "X86_GCC")
    set(CMAKE_TOOLCHAIN_FILE ./arm_setup/cmake/x86-gcc-toolchain.cmake)  # ← use specific file!
elseif("${TOOLCHAIN}" STREQUAL "ARM_GCC")
    set(CMAKE_TOOLCHAIN_FILE ./arm_setup/cmake/arm-gcc-toolchain.cmake)
else()
    message(FATAL_ERROR "unsupported toolchain: ${TOOLCHAIN}")
endif()


set(PROJECT blinky)

include(device)
include(utils)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(${PROJECT} LANGUAGES C CXX ASM)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "")
endif ()

if(CMAKE_BUILD_TYPE STREQUAL "Release" OR CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)
endif()

add_subdirectory(3d_party EXCLUDE_FROM_ALL)

set(INCLUDE_DIRS
    src
    src/_common
)

## Application source files
# C++ source files
## Application source files (device-independent)
set(APP_CPP_SRCS
    src/system_manager.cpp
    src/main.cpp
    src/_common/io_functions.cpp
    src/_common/common.cpp
    src/application/application_manager.cpp
    src/application/blinky/blinky.cpp
    src/device/device_manager.cpp
    src/device/user_indication/user_indication.cpp
    src/device/software_timer/software_timer.cpp
)

# Device-specific source files
if("${TARGET_DEVICE}" STREQUAL "X86")
    list(APPEND APP_CPP_SRCS
        src/hardware_manager/hardware_manager_x86.cpp
        src/hardware_x86/gpio_pin/gpio_pin.cpp
    )

    add_compile_definitions(PLATFORM_X86)

elseif("${TARGET_DEVICE}" STREQUAL "RP2040")
    list(APPEND APP_CPP_SRCS
        src/hardware_manager/hardware_manager_rp2040.cpp
        src/hardware_rp2040/gpio_pin/gpio_pin.cpp
        src/hardware_rp2040/timer/timer.cpp
        src/hardware_rp2040/interrupt_dispatcher/interrupt_dispatcher.cpp
        src/hardware_rp2040/interrupt_dispatcher/interrupt_trampolines.cpp
    )

    add_compile_definitions(PLATFORM_RP2040)

else()
    message(FATAL_ERROR "unsupported target: ${TARGET_DEVICE}")
endif()


include_directories(${INCLUDE_DIRS})

add_executable( ${PROJECT} 
                ${APP_CPP_SRCS})
# set linker options
if("${TARGET_DEVICE}" STREQUAL "X86")
   # do nothing
elseif("${TARGET_DEVICE}" STREQUAL "RP2040")
    target_link_libraries(${PROJECT} PRIVATE pico)

    target_link_options(${PROJECT} PRIVATE "-L${CMAKE_CURRENT_LIST_DIR}/src/hardware_rp2040/linker")
    
    target_linker_script(${PROJECT} 
        "${CMAKE_CURRENT_LIST_DIR}/src/hardware_rp2040/linker/linker.ld"
    )

else()
    message(FATAL_ERROR "unsupported target: ${TARGET_DEVICE}")
endif()

target_include_directories(${PROJECT} PRIVATE include)

set(WARNINGS
    all
    extra
    maybe-uninitialized
    strict-overflow=2
    switch
    write-strings
)

list(TRANSFORM WARNINGS PREPEND "-W")
list(TRANSFORM DISABLE_WARNINGS PREPEND "-Wno-")
target_compile_options(${PROJECT} PRIVATE "${WARNINGS}" "${DISABLE_WARNINGS}")
if (FATAL_ERRORS)
    target_compile_options(${PROJECT} PRIVATE "-Wfatal-errors")
endif ()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-volatile")

set (JLINK_IP_FILE "${CMAKE_CURRENT_LIST_DIR}/jlink_ip.cmake")
if (EXISTS "${JLINK_IP_FILE}")
    include("${JLINK_IP_FILE}")
endif ()

set(LAUNCH_FILE_INTERMEDIATE "${CMAKE_CURRENT_BINARY_DIR}/launch.json.in")
configure_file("${CMAKE_CURRENT_LIST_DIR}/arm_setup/cmake/launch.json.in" ${LAUNCH_FILE_INTERMEDIATE} @ONLY)

file(GENERATE
    OUTPUT "${CMAKE_CURRENT_LIST_DIR}/.vscode/launch.json"
    INPUT ${LAUNCH_FILE_INTERMEDIATE}
)
