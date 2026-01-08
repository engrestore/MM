cmake_minimum_required(VERSION 3.26)

project(myapp
    LANGUAGES CXX C ASM
)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

include(cmake/build-util.cmake)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux" OR CMAKE_SYSTEM_NAME STREQUAL "Windows")
    # Native build: only add platform-independent code
    add_subdirectory(common)
else()
    # Embedded build: add all sources
    if(MCU_NAME MATCHES "^(STM32).*")
        message("Found STM32 Device!")
        add_compile_definitions(
            ${MCU_NAME}=TRUE
            ${MCU_FAMILY}=TRUE
            USE_HAL_DRIVER=TRUE
        )
    endif()

    if ("${TARGET_APP}" STREQUAL "")
        add_subdirectory(apps)
    else()
        add_subdirectory(apps/${TARGET_APP})
    endif()

    add_subdirectory(common)
    # add_subdirectory(external)
    add_subdirectory(mcu_support)
endif()
