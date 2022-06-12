cmake_minimum_required(VERSION 3.22)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c worker/worker.c vehicle/vehicle.c vehicle/vehicle.h worker/worker.h util/utils.c util/utils.h vehicle/user_input/user_input.c vehicle/user_input/user_input.h vehicle/read/read.c vehicle/read/read.h)
