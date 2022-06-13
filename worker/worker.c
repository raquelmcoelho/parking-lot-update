#include "worker.h"

// Crud
worker createWorker(char* code, char* name, char* siape, char* cpf, char* birthday, char *rg, char *address, char *wage, type type){
    worker w;
    strcpy(w.code, code),
    strcpy(w.name, name);
    strcpy(w.siape, siape);
    strcpy(w.cpf, cpf);
    strcpy(w.birthday, birthday);
    strcpy(w.rg, rg);
    strcpy(w.address, address);
    strcpy(w.wage, wage);
    w.type = type;
    w.status = 1;

    return w;
}

void readWorker(worker w){
    if(w.status){
        puts(w.code);
        puts(w.name);
        puts(w.siape);
        puts(w.cpf);
        puts(w.birthday);
        puts(w.rg);
        puts(w.address);
        puts(w.wage);
        switch(w.type){
            case 1:
                puts("Técnico Admnistrativo");
                break;
            case 2:
                puts("Professor");
                break;
            default:
                puts("Sem tipo");
                break;
        }
    }
}

// Ui
//obrigatórios
char * getCodeFromMandatoryUserInput(){
    char code[255];
    return getMandatoryStringFieldFromUserInput(code, "Digite o código do servidor: ");
}
char * getNameFromMandatoryUserInput(){
    char name[255];
    return getMandatoryStringFieldFromUserInput(name, "Digite o nome do servidor: ");
}
char * getSiapeFromMandatoryUserInput(){
    char siape[255];
    return getMandatoryStringFieldFromUserInput(siape, "Digite o siape do servidor: ");
}
char * getCpfFromMandatoryUserInput(){
    char cpf[255];
    return getMandatoryStringFieldFromUserInput(cpf, "Digite o cpf do servidor: ");
}
char * getBirthdayFromMandatoryUserInput(){
    char birthday[255];
    return getMandatoryStringFieldFromUserInput(birthday, "Digite o dia de nascimento do servidor: ");
}

// opcionais
char * getRgFromUserInput(){
    char rg[255];
    return getStringFieldFromUserInput(rg, "Digite o rg do servidor: ");
}

char * getAddressFromUserInput(){
    char address[255];
    return getStringFieldFromUserInput(address, "Digite o endereço do servidor: ");
}

char * getWageFromUserInput(){
    char wage[255];
    return getStringFieldFromUserInput(wage, "Digite o salário do servidor: ");
}

type getTypeFromUserInput(){
    int type_int = 0;
    char type_char[255];
    type_int = getIntegerFieldFromUserInput(type_char, "Digite o tipo do servidor:\n 1 - Técnico Administrativo \n 2 - Docente \n Entre com o número da opção: \n");

    switch(type_int){
        case 1:
            return administrative_technician;
            break;
        case 2:
            return teacher;
            break;
        default:
            return null_type;
            break;
    }
}





// Facade
bool createWorkerFacade(){

    // TODO: createWorker()
    return true;
}

bool updateWorkerFacade(){
    worker w;
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

bool deleteWorkerFacade(){
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

bool readOneWorkerFacade(){
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