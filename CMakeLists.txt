cmake_minimum_required(VERSION 3.13)

# initialize pico-sdk from submodule
# note: this must happen before project()
include(lib/pico-sdk/pico_sdk_init.cmake)

project(usb_cdc_example)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project

add_executable(usb_cdc_example
    src/main.c
    src/usb_descriptors.c
)

target_include_directories(usb_cdc_example PRIVATE 
    src
)

target_link_libraries(usb_cdc_example PRIVATE 
    pico_stdlib
    tinyusb_device
    tinyusb_board
)

pico_add_extra_outputs(usb_cdc_example)