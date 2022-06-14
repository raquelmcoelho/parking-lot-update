#include "worker.h"


bool createWorker(){
    // TODO: checar uniquidade do Codigo, cpf e siape
    WORKER worker;
    strcpy(worker.name, getWorkerNameFromUserInput());
    strcpy(worker.siape, getWorkerSiapeFromUserInput());
    strcpy(worker.cpf, getWorkerCpfFromUserInput());
    strcpy(worker.birthday, getWorkerBirthdayFromUserInput());
    strcpy(worker.rg, getWorkerRgFromUserInput());
    strcpy(worker.address, getWorkerAddressFromUserInput());
    strcpy(worker.wage, getWorkerWageFromUserInput());
    worker.type = getWorkerTypeFromUserInput();
    worker.status = 1;

    _insertWorkerIntoDatabase(worker);
    return true;
}

bool updateWorker(){
    WORKER w;
    bool exists = false;

    printf("insira o codigo do servidor que deseja editar:\n");
    // TODO: getMandtoryStringField()
    // TODO: searchWorker()

    if(exists){
        printf("um registro foi encontrado:\n");
        // TODO: readOneWorker()
    } else {
        printf("não há servidor com este código em nossos registros");
        return false;
    }

    printf("Deseja alterar o nome?(s/n) \n");
    // TODO: getMandatoryWill()
    printf("Deseja alterar o siape?(s/n) \n");
    // TODO: getMandatoryWill()
    printf("Deseja alterar o cpf?(s/n) \n");
    // TODO: getMandatoryWill()
    printf("Deseja alterar a data de nascimento?(s/n) \n");
    // TODO: getMandatoryWill()
    printf("Deseja alterar o rg?(s/n) \n");
    // TODO: getMandatoryWill()
    printf("Deseja alterar o endereço?(s/n) \n");
    // TODO: getMandatoryWill()
    printf("Deseja alterar o salário?(s/n) \n");
    // TODO: getMandatoryWill()
    printf("Deseja alterar o tipo?(s/n) \n");
    // TODO: getTypeLabel()
    // TODO: getMandatoryWill()
    return true;
}

bool deleteWorker(){
    bool exists = false;
    printf("insira o codigo do servidor que deseja excluir:\n");
    // TODO: getMandatoryStringField()
    // TODO: searchWorker()

    if(exists){
        printf("um registro foi encontrado:\n");
        // TODO: readOneWorker()
        // TODO: deleteWorker()
        return true;
    } else {
        printf("não há servidor com este código em nossos registros");
        return false;
    }
}

bool readOneWorker(){
    bool exists = false;
    printf("insira o codigo do servidor que deseja ler:\n");
    // TODO: getMandatoryStringField()
    // TODO: searchWorker()

    if(exists){
        printf("um registro foi encontrado:\n");
        // TODO: readOneWorker()
        return true;
    } else {
        printf("não há servidor com este código em nossos registros");
        return false;
    }
}