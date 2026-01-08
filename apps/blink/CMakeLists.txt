cmake_minimum_required(VERSION 3.26)

project(blink LANGUAGES CXX C)

add_executable(blink
    blink.cpp
    ${CMAKE_SOURCE_DIR}/common/baremetal_stubs.c
)

target_link_libraries(blink PRIVATE st_f411_hal st_f411_support)

target_include_directories(blink PRIVATE
    ${CMAKE_SOURCE_DIR}/mcu_support/stm32/f4xx
    ${CMAKE_SOURCE_DIR}/mcu_support/stm32/f4xx/HAL
    ${CMAKE_SOURCE_DIR}/mcu_support/CMSIS/include
)