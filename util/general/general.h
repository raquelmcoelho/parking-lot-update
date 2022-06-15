#ifndef GENERAL_H
#define GENERAL_H
#endif //GENERAL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <stddef.h>

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

#define worker_filename "worker_database.bin"
#define vehicle_filename "vehicle_database.bin"

                                        
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
    exit_program = 100
} option;

typedef enum status_enum
{
    deleted = 0,
    active = 1
} status_enum;


// Enum for Workers Type
typedef enum {
    null_type,
    administrative_technician,
    teacher
} type;

typedef struct {
    //obrigatórios
    int code;
    char siape[255];
    char cpf[255];
    char rg[255];
    char name[255];
    char birthday[255];
    char address[255];
    char wage[255];
    type type;
    int status : 1;
} WORKER;

typedef struct struct_vehicle
{
    char licensePlate[255];
    char description[255];
    char brand[255];
    char model[255];
    int workerCode;
    int status : 1;
} VEHICLE;
    
typedef enum {
    field_code = offsetof(WORKER, code),
    field_siape = offsetof(WORKER, siape),
    field_cpf = offsetof(WORKER, cpf),
    field_rg = offsetof(WORKER, rg)
} fieldPosition;


typedef union {
    int integer;
    char string[255];
} value;

typedef struct 
{
    int index;
    char name[255];
    type type;
    int status : 1;
} tuple_order_worker;

typedef struct
{
    int index;
    char description[255];
    int workerCode;
    int status : 1;
} tuple_order_vehicle;

char* getDivider()
{
    char* _line = malloc(sizeof(char) * 255);
    for(register int i = 0; i < 150; i++){
        _line[i] = '-';
    }
    _line[255] = '\0';
    return _line;
}

void showCustomBlockingMessage(char *msg)
{
    printf("%s\n", msg);
    fflush(stdin);
    getchar();
    fflush(stdin);
    getchar();
    fflush(stdin);
}

void showBlockingMessage()
{
    printf("%s", PRESS_ANY_KEY_TO_CONTINUE);
    fflush(stdin);
    getchar();
    fflush(stdin);
    getchar();
    fflush(stdin);
}
