cmake_minimum_required(VERSION 3.19.1)
project(propwd)

set(CMAKE_BUILD_TYPE Debug)

add_executable(
    propwd
    main.c
    c_interface.c
    helpers.c
    account.c
    obscure_str.c
    tester.c
)