#ifndef UTILS_H
#define UTILS_H
#endif //UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

#include "crud/create/create.c"
#include "crud/read/read.c"
#include "file_handler/file_handler.h"
#include "read/read.h"
#include "ui/ui.h"

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


bool fileExists(char *fileName);

// DEPRACATED

// initializes an array of size n with the value false
void initializeBoolArray(bool array[], int n);
void initializeIntArray(int *array, int n);
void initializeStringArray(char array[][255], int n);


// beautifully prints an array of size n
void printBoolArray(bool array[], int n);
void printStringArray(char array[][255], int n);
void printIntArray(int array[], int n);

// orders an array of size n alphabetically
void orderArrayAlphabetically(char array[][255], int n);
void orderPositionsAlphabetically(int indexes[], char array[][255], int n);

// generates a random uuid
char* generateUUID();

// removes trailling and leading spaces from a string
char* removeTrailingAndLeadingSpaces(char* string);

// Returns the index of the first space it finds, if it doesn't find it returns -1
int findSpace(bool array[], int n);

// Find something in a array and return the position
int findStringInArray(char array[][255], int n, char string[]);

// Shows a message at screen and wait the user to press some key to continue
void showCustomBlockingMessage(char *msg);
void showBlockingMessage();

// get a mandatory (or not) string, integer or float field from the user
char* getMandatoryStringFieldFromUserInput(char* field, char msg[]);
int getMandatoryIntegerFieldFromUserInput(char* field, char msg[]);
char* getStringFieldFromUserInput(char* field, char msg[]);
int getIntegerFieldFromUserInput(char* field, char msg[]);
char getMandatoryWillFieldFromUserInput();
bool checkStringIsNumber(char string[255]);

// get the first vacant position in an array
int getFirstVacantPosition(bool array[], int n);

// sanitizes a string
char* sanitizeString(char* string);

// Find something in a array and return the position
int findStringInArray(char array[][255], int n, char string[]);

// get the first vacant position in an array
int getFirstVacantIndex(bool array[], int n);

char* getDivider();





