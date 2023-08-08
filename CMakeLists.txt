cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(stepper C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(stepper
	main.c
)

pico_enable_stdio_usb(stepper 1)
pico_enable_stdio_uart(stepper 1)

pico_add_extra_outputs(stepper)

target_link_libraries(stepper pico_stdlib)
