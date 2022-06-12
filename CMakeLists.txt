cmake_minimum_required(VERSION 3.22)
project(parking_lot_update C)

set(CMAKE_C_STANDARD 99)

add_executable(
        parking_lot_update
        main.c 
        worker/worker.c 
        worker/worker.h 
        vehicle/vehicle.c 
        vehicle/vehicle.h 
        util/utils.c 
        util/utils.h 
        util/crud/create/create.c 
        util/crud/read/read.c 
        util/crud/read/read.h 
        util/file_handler/file_handler.c 
        util/file_handler/file_handler.h 
        util/read/read.c 
        util/read/read.h 
        util/ui/ui.c 
        util/ui/ui.h 
)
