FILE(GLOB SRC_FILES *.c)

add_library(st_f411_hal STATIC
    ${SRC_FILES}
)

target_link_libraries(st_f411_hal PUBLIC
    st_f411_support
)
target_include_directories(st_f411_hal PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/mcu_support/stm32/f4xx
    ${CMAKE_SOURCE_DIR}/mcu_support/stm32/f4xx/HAL
    ${CMAKE_SOURCE_DIR}/mcu_support/CMSIS/include
)