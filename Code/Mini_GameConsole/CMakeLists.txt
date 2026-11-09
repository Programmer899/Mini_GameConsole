# # Generated Cmake Pico project file

# cmake_minimum_required(VERSION 3.13)

# set(CMAKE_C_STANDARD 11)
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# # Initialise pico_sdk from installed location
# # (note this can come from environment, CMake cache etc)

# # == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
# if(WIN32)
#     set(USERHOME $ENV{USERPROFILE})
# else()
#     set(USERHOME $ENV{HOME})
# endif()
# set(sdkVersion 2.3.1)
# set(toolchainVersion 15_2_Rel1)
# set(picotoolVersion 2.3.1)
# set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
# if (EXISTS ${picoVscode})
#     include(${picoVscode})
# endif()
# # ====================================================================================
# set(PICO_BOARD pico CACHE STRING "Board type")

# # Pull in Raspberry Pi Pico SDK (must be before project)
# include(pico_sdk_import.cmake)

# project(Mini_GameConsole C CXX ASM)

# # Initialise the Raspberry Pi Pico SDK
# pico_sdk_init()

# # Add executable. Default name is the project name, version 0.1

# add_executable(Mini_GameConsole Mini_GameConsole.c )

# pico_set_program_name(Mini_GameConsole "Mini_GameConsole")
# pico_set_program_version(Mini_GameConsole "0.1")

# # no_flash means the target is to run from RAM
# pico_set_binary_type(Mini_GameConsole no_flash)

# # Modify the below lines to enable/disable output over UART/USB
# pico_enable_stdio_uart(Mini_GameConsole 0)
# pico_enable_stdio_usb(Mini_GameConsole 1)

# # Add the standard library to the build
# target_link_libraries(Mini_GameConsole
#         pico_stdlib)

# # Add the standard include files to the build
# target_include_directories(Mini_GameConsole PRIVATE
#         ${CMAKE_CURRENT_LIST_DIR}
# )

# # Add any user requested libraries
# target_link_libraries(Mini_GameConsole 
#         hardware_spi
#         hardware_i2c
#         )

# pico_add_extra_outputs(Mini_GameConsole)

cmake_minimum_required(VERSION 3.13)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(pico_sdk_import.cmake)

project(MiniConsole C CXX ASM)

set(CMAKE_C_STANDARD 11)

pico_sdk_init()

add_executable(MiniConsole
    main.c
    drivers/display.c
    drivers/input.c
    drivers/audio.c
)

target_include_directories(MiniConsole PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/drivers
)

target_link_libraries(MiniConsole
    pico_stdlib
    hardware_adc
    hardware_pwm
    hardware_spi
)

pico_add_extra_outputs(MiniConsole)