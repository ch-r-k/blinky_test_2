# add_library(stm32 OBJECT)

# set(INCLUDE_DIRS_STM
#     cmsis_device_stm_l4/Include
#     cmsis_5/CMSIS/Core/Include
#     stm32l4xx_hal_driver/Inc
# )

# set(SOURCE_STM
#     stm32l4xx_hal_driver/Src/stm32l4xx_hal.c
#     stm32l4xx_hal_driver/Src/stm32l4xx_hal_cortex.c
#     stm32l4xx_hal_driver/Src/stm32l4xx_hal_gpio.c
# )

# target_include_directories(stm32 PUBLIC ${INCLUDE_DIRS_STM})
# target_sources(stm32 PRIVATE ${SOURCE_STM})

# PICO
add_library(pico OBJECT)

set(INCLUDE_DIRS_PICO
    pico_sdk/src/boards/include
    pico_sdk/src/common/boot_picoboot_headers/include
    pico_sdk/src/common/boot_picobin_headers/include
    pico_sdk/src/common/hardware_claim/include
    pico_sdk/src/common/pico_base_headers/include
    pico_sdk/src/common/pico_binary_info/include
    pico_sdk/src/common/pico_bit_ops_headers/include
    pico_sdk/src/common/pico_divider_headers/include
    pico_sdk/src/common/pico_stdlib_headers/include
    pico_sdk/src/common/pico_sync/include
    pico_sdk/src/common/pico_time/include
    pico_sdk/src/common/pico_util/include
    pico_sdk/src/rp2_common/boot_bootrom_headers/include
    pico_sdk/src/rp2_common/hardware_base/include
    pico_sdk/src/rp2_common/hardware_boot_lock/include
    pico_sdk/src/rp2_common/hardware_clocks/include
    pico_sdk/src/rp2_common/hardware_divider/include
    pico_sdk/src/rp2_common/hardware_gpio/include
    pico_sdk/src/rp2_common/hardware_irq/include
    pico_sdk/src/rp2_common/hardware_pll/include
    pico_sdk/src/rp2_common/hardware_resets/include
    pico_sdk/src/rp2_common/hardware_sync/include
    pico_sdk/src/rp2_common/hardware_sync_spin_lock/include
    pico_sdk/src/rp2_common/hardware_ticks/include
    pico_sdk/src/rp2_common/hardware_timer/include
    pico_sdk/src/rp2_common/hardware_uart/include
    pico_sdk/src/rp2_common/hardware_vreg/include
    pico_sdk/src/rp2_common/hardware_watchdog/include
    pico_sdk/src/rp2_common/hardware_xosc/include
    pico_sdk/src/rp2_common/pico_atomic/include
    pico_sdk/src/rp2_common/pico_double/include
    pico_sdk/src/rp2_common/pico_flash/include
    pico_sdk/src/rp2_common/pico_float/include
    pico_sdk/src/rp2_common/pico_int64_ops/include
    pico_sdk/src/rp2_common/pico_malloc/include
    pico_sdk/src/rp2_common/pico_mem_ops/include
    pico_sdk/src/rp2_common/pico_platform_compiler/include
    pico_sdk/src/rp2_common/pico_platform_panic/include
    pico_sdk/src/rp2_common/pico_platform_sections/include
    pico_sdk/src/rp2_common/pico_printf/include
    pico_sdk/src/rp2_common/pico_runtime/include
    pico_sdk/src/rp2_common/pico_runtime_init/include
    pico_sdk/src/rp2_common/pico_stdlib/include
    pico_sdk/src/rp2_common/pico_stdio/include
    pico_sdk/src/rp2_common/pico_stdio_uart/include
    pico_sdk/src/rp2_common/pico_sync/include
    pico_sdk/src/rp2_common/pico_time_adapter/include
    pico_sdk/src/rp2_common/pico_util/include
    pico_sdk/src/rp2040/boot_stage2/include
    pico_sdk/src/rp2040/hardware_regs/include
    pico_sdk/src/rp2040/hardware_structs/include
    pico_sdk/src/rp2040/pico_platform/include
    pico_sdk/src/rp2_common/cmsis/stub/CMSIS/Core/Include
)

set(SOURCE_PICO
    pico_sdk/src/rp2_common/pico_stdlib/stdlib.c
    pico_sdk/src/rp2_common/pico_platform_panic/panic.c
    pico_sdk/src/rp2_common/hardware_gpio/gpio.c
    pico_sdk/src/rp2_common/hardware_sync/sync.c
    pico_sdk/src/rp2040/pico_platform/platform.c
    pico_sdk/src/common/hardware_claim/claim.c
)

set(DEFINITIONS_PICO
    LIB_BOOT_STAGE2_HEADERS=0
    LIB_PICO_ATOMIC=1
    LIB_PICO_BIT_OPS=1
    LIB_PICO_BIT_OPS_PICO=1
    LIB_PICO_CLIB_INTERFACE=1
    LIB_PICO_CRT0=1
    LIB_PICO_CXX_OPTIONS=1
    LIB_PICO_DIVIDER=1
    LIB_PICO_DIVIDER_HARDWARE=1
    LIB_PICO_DOUBLE=1
    LIB_PICO_DOUBLE_PICO=1
    LIB_PICO_FLASH=1
    LIB_PICO_FLOAT=1
    LIB_PICO_FLOAT_PICO=1
    LIB_PICO_INT64_OPS=1
    LIB_PICO_INT64_OPS_PICO=1
    LIB_PICO_MALLOC=1
    LIB_PICO_MEM_OPS=1
    LIB_PICO_MEM_OPS_PICO=1
    LIB_PICO_NEWLIB_INTERFACE=1
    LIB_PICO_PLATFORM=1
    LIB_PICO_PLATFORM_COMPILER=1
    LIB_PICO_PLATFORM_PANIC=1
    LIB_PICO_PLATFORM_SECTIONS=1
    LIB_PICO_PRINTF=1
    LIB_PICO_PRINTF_PICO=1
    LIB_PICO_RUNTIME=1
    LIB_PICO_RUNTIME_INIT=1
    LIB_PICO_STANDARD_BINARY_INFO=1
    LIB_PICO_STANDARD_LINK=1
    LIB_PICO_STDIO=1
    LIB_PICO_STDIO_UART=1
    LIB_PICO_STDLIB=1
    LIB_PICO_SYNC=1
    LIB_PICO_SYNC_CRITICAL_SECTION=1
    LIB_PICO_SYNC_MUTEX=1
    LIB_PICO_SYNC_SEM=1
    LIB_PICO_TIME=1
    LIB_PICO_TIME_ADAPTER=1
    LIB_PICO_UTIL=1
    PICO_32BIT=1
    PICO_BOARD="pico"
    PICO_BUILD=1
    PICO_CMAKE_BUILD_TYPE="Debug"
    PICO_COPY_TO_RAM=0
    PICO_CXX_ENABLE_EXCEPTIONS=0
    PICO_NO_FLASH=0
    PICO_NO_HARDWARE=0
    PICO_ON_DEVICE=1
    PICO_RP2040=1
    PICO_TARGET_NAME="blink"
    PICO_USE_BLOCKED_RAM=0
)

target_include_directories(pico PUBLIC ${INCLUDE_DIRS_PICO})
target_sources(pico PRIVATE ${SOURCE_PICO})
target_compile_definitions(pico PUBLIC ${DEFINITIONS_PICO})