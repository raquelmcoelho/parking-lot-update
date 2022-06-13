#ifndef WORKER_H
#define WORKER_H
#endif //WORKER_H


#ifndef UTILS_H
#include "../util/utils.h"
#endif

typedef enum {
    field_code,
    field_name,
    field_siape,
    field_cpf,
    field_birthday,
    field_rg,
    field_address,
    field_wage,
    field_type
} field;


// Struct Functions
worker createWorker(char* code, char* name, char* siape, char* cpf, char* birthday, char *rg, char *address, char *wage, type type);
void readWorker(worker w);

// File
FILE* getFileWorkers();
int getPositionByField(field field);
void printStructAtPosition(int position);



// Ui
//obrigatórios
char* getCodeFromMandatoryUserInput();
char* getNameFromMandatoryUserInput();
char* getSiapeFromMandatoryUserInput();
char* getCpfFromMandatoryUserInput();
char* getBirthdayFromMandatoryUserInput();
// opcionais
char* getRgFromUserInput();
char* getAddressFromUserInput();
char* getWageFromUserInput();
type getTypeFromUserInput();


// Facade
bool createWorkerFacade();
bool updateWorkerFacade();
bool deleteWorkerFacade();
bool readOneWorkerFacade();
bool readWorkersFacade();
bool readWorkersAlphabeticallyFacade();