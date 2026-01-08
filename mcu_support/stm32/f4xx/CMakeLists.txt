add_library(st_f411_support STATIC
    system_stm32f411xx.c
    ${CMAKE_SOURCE_DIR}/common/baremetal_stubs.c
)

target_include_directories(st_f411_support PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/mcu_support/stm32/f4xx
    ${CMAKE_SOURCE_DIR}/mcu_support/stm32/f4xx/HAL
    ${CMAKE_SOURCE_DIR}/mcu_support/CMSIS/include
)
target_link_libraries(st_f411_support PUBLIC
    cmsis
    st_f411_hal
)

add_subdirectory(HAL)