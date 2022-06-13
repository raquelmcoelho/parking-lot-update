#ifndef GENERAL_H
#define GENERAL_H
#endif //GENERAL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include <ctype.h> 

#define PRESS_ANY_KEY_TO_CONTINUE "Pressione qualquer tecla para continuar   .    .    ."

// Colors to use in terminal
#define red "\x1B[31m"
#define green "\x1B[32m"
#define yellow "\x1B[33m"
#define blue "\x1B[34m"
#define purple "\x1B[35m"
#define cyan "\x1B[36m"
#define white "\x1B[37m"
#define normal "\x1B[0m"

typedef enum {
    nothing,
    create_worker,
    update_worker,
    delete_worker,
    read_one_worker,
    read_workers,
    read_workers_alphabetically,
    read_technicians_alphabetically,
    read_teachers_alphabetically,
    create_vehicle,
    update_vehicle,
    delete_vehicle,
    read_one_vehicle,
    read_vehicles_worker,
    read_vehicles_worker_alphabetically,
    read_all_vehicles, // extra
    exit_program
} option;

typedef enum status_enum
{
    deleted = 0,
    active = 1
} status;


// Enum for Workers Type
typedef enum {
    null_type,
    administrative_technician,
    teacher
} type;

typedef struct {
    //obrigatórios
    char code[255];
    char name[255];
    char siape[255];
    char cpf[255];
    char birthday[255];
    // opcionais
    char rg[255];
    char address[255];
    char wage[255];
    type type;
    unsigned short int status : 1;
} worker;

typedef struct {
    char worker_code[255];
    //obrigatórios
    char vehicle_code[255];
    char description[255];
    char licence_plate[255];
    char brand[255];
    char model[255];
} vehicle;

typedef struct {
    union {
        worker w;
        vehicle v;
    };
    unsigned short int is_free: 1;
} node;
