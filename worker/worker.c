#include "worker.h"


bool createWorker(){
    WORKER worker;
    value searchQuery;
    int positionFindBySearch = -1;
    
    strcpy(worker.name, getWorkerNameFromUserInput());

    do{
        if(positionFindBySearch != -1){
            printf("\nEste SIAPE já está em nosso banco de dados!\n");
        }
        strcpy(worker.siape, getWorkerSiapeFromUserInput());
        strcpy(searchQuery.string, worker.siape);
        positionFindBySearch = _getWorkerIndexBySearch(field_siape, searchQuery);
    } while (positionFindBySearch != -1);

    do{
        if(positionFindBySearch != -1){
            printf("\nEste CPF já está em nosso banco de dados!\n");
        }
        strcpy(worker.cpf, getWorkerCpfFromUserInput());
        strcpy(searchQuery.string, worker.cpf);
        positionFindBySearch = _getWorkerIndexBySearch(field_cpf, searchQuery);
    } while (positionFindBySearch != -1);

    strcpy(worker.birthday, getWorkerBirthdayFromUserInput());
    strcpy(worker.rg, getWorkerRgFromUserInput());
    strcpy(worker.address, getWorkerAddressFromUserInput());
    strcpy(worker.wage, getWorkerWageFromUserInput());
    worker.type = getWorkerTypeFromUserInput();
    worker.status = active;
    worker.code = _getFirstIndexFreeForWorker();
    printf("Primeiro índice livre achado: %d", worker.code);

    
    if(_insertWorkerIntoDatabase(worker)){
        printf("\nOs dados inseridos foram:\n");
        _showWorker(worker);
        return true;
    } else {
        return false;
    }
}

bool updateWorker(){
    WORKER worker;
    value searchQuery;
    int positionFindBySearch = -1;
    int position = readOneWorker(true);
    if(position == -1) return false;

    worker = _getWorkerByIndex(position);

    printf("\nDeseja alterar o nome?(s/n) \n");
    if(getWillFromUserInput()){
        strcpy(worker.name, getWorkerNameFromUserInput());
    }

    printf("Deseja alterar o siape?(s/n) \n");
    if(getWillFromUserInput()){
        do{
            if(positionFindBySearch != -1 && positionFindBySearch != worker.code){
                printf("\nEste SIAPE já está em nosso banco de dados!\n");
            }
            strcpy(worker.siape, getWorkerSiapeFromUserInput());
            strcpy(searchQuery.string, worker.siape);
            positionFindBySearch = _getWorkerIndexBySearch(field_siape, searchQuery);
        } while (positionFindBySearch != -1 && positionFindBySearch != worker.code);
    }


    printf("Deseja alterar o cpf?(s/n) \n");
    if(getWillFromUserInput()){
        do{
            if(positionFindBySearch != -1 && positionFindBySearch != worker.code){
                printf("\nEste CPF já está em nosso banco de dados!\n");
            }
            strcpy(worker.cpf, getWorkerCpfFromUserInput());
            strcpy(searchQuery.string, worker.cpf);
            positionFindBySearch = _getWorkerIndexBySearch(field_cpf, searchQuery);
        } while (positionFindBySearch != -1 && positionFindBySearch != worker.code);
    }


    printf("Deseja alterar a data de nascimento?(s/n) \n");
    if(getWillFromUserInput()){
        strcpy(worker.birthday, getWorkerBirthdayFromUserInput());
    }
    printf("Deseja alterar o rg?(s/n) \n");
    if(getWillFromUserInput()){
        strcpy(worker.rg, getWorkerRgFromUserInput());
    }
    printf("Deseja alterar o endereço?(s/n) \n");
    if(getWillFromUserInput()){
        strcpy(worker.address, getWorkerAddressFromUserInput());
    }
    printf("Deseja alterar o salário?(s/n) \n");
    if(getWillFromUserInput()){
        strcpy(worker.wage, getWorkerWageFromUserInput());
    }
    printf("Deseja alterar o tipo?(s/n) \n");
    if(getWillFromUserInput()){
        worker.type = getWorkerTypeFromUserInput();
    }    
    
    if(_insertWorkerIntoDatabase(worker)){
        printf("\nOs dados agora estão assim:\n");
        _showWorker(worker);
        return true;
    } else {
        return false;
    }
    
}

bool deleteWorker(){
    WORKER worker;

    int position = readOneWorker(true);
    if(position == -1) return false;

    worker = _getWorkerByIndex(position);
    worker.status = deleted;

    return _insertWorkerIntoDatabase(worker);
}

int readOneWorker(bool returnPosition){
    WORKER worker;
    value searchQuery;
    int positionFindBySearch = -1;

    printf("Insira o codigo do servidor que deseja:\n");
    searchQuery.integer = getWorkerCodeFromUserInput();
    positionFindBySearch = _getWorkerIndexBySearch(field_code, searchQuery);

    if(positionFindBySearch == -1){
        printf("\nNão há servidor com este código em nossos registros\n");
        return returnPosition? -1 : 0;
    }

    worker = _getWorkerByIndex(positionFindBySearch);

    if(worker.status == deleted){
        printf("\nNão há servidor ativo com este código em nossos registros\n");
        return returnPosition? -1 : 0;
    }

    printf("Um registro foi encontrado:\n");
    _showWorker(worker);
    return returnPosition? worker.code : 1;
}
