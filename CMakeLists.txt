cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(shift_register_project)

pico_sdk_init()

add_executable(shift_register_demo
    main.c
    shift_register/shift_register.c
)

target_include_directories(shift_register_demo PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/shift_register
)

target_link_libraries(shift_register_demo pico_stdlib)

pico_add_extra_outputs(shift_register_demo)
