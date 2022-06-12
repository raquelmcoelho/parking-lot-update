#include "worker.h"

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

    return w;
}

bool createWorkerUI(){
    printf("\n(obrigatório) insira o nome:              (ex: João da Silva)\n");
    // TODO: getMandatoryStringField()
    printf("\n(obrigatório) insira o siape:             (ex: 12345)\n");
    // TODO: getMandatoryStringField()
    printf("\n(obrigatório) insira o cpf:               (ex: 123.456.789-10)\n");
    // TODO: getMandatoryStringField()
    printf("\n(obrigatório) insira o dia de nascimento: (ex: 01/01/2001)\n");
    // TODO: getMandatoryStringField()

    printf("\n(opcional) insira o rg:                   (ex: 12345678-9)\n");
    // TODO: getStringField()
    printf("\n(opcional) insira o endereço:             (ex: 01/01/2001)\n");
    // TODO: getStringField()
    printf("\n(opcional) insira o salário:              (ex: R$ 15.000)\n");
    // TODO: getStringField()
    printf("\n(opcional) insira o tipo de servidor:)\n");
    printf("\n 1 - Técnico Administrativo \n");
    printf("\n 2 - Docente \n");
    printf("\n Entre com o número da opção: \n");
    // TODO: getIntField()

    // TODO: createWorker()
    return true;
}

bool updateWorkerUI(){
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

    printf("Deseja alterar o nome?(s/n) \n", w.name);
    // TODO: getMandatoryWill()
    printf("Deseja alterar o siape?(s/n) \n", w.siape);
    // TODO: getMandatoryWill()
    printf("Deseja alterar o cpf?(s/n) \n", w.cpf);
    // TODO: getMandatoryWill()
    printf("Deseja alterar a data de nascimento?(s/n) \n", w.birthday);
    // TODO: getMandatoryWill()
    printf("Deseja alterar o rg?(s/n) \n", w.rg);
    // TODO: getMandatoryWill()
    printf("Deseja alterar o endereço?(s/n) \n", w.address);
    // TODO: getMandatoryWill()
    printf("Deseja alterar o salário?(s/n) \n", w.wage);
    // TODO: getMandatoryWill()
    printf("Deseja alterar o tipo?(s/n) \n", w.type);
    // TODO: getTypeLabel()
    // TODO: getMandatoryWill()
    return true;
}

bool deleteWorkerUI(){
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

bool readOneWorkerUI(){
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







// DEPRACATED




// // - inserir novo servidor --
// bool insertNewServer(){
//     int spaceIndex = getFirstVacantIndex(spaceWorkers, MAX_WORKERS);

//     if(spaceIndex == -1){
//         printf("\nNão há espaço disponível!\n");
//         return false;
//     } else {
//         if(alterServer(spaceIndex)){
//             return true;
//         } else {
//             return false;
//         }
//     }
// }

// // - alterar um servidor existente —
// bool alterServer(int position){
//     // get Mandatory User Data
//     char newWorkerRegistrationNumber[255] ;
//     char newSiape[255];
//     char newCpf[255];
//     char newName[255];
//     char newBirthday[255];

//     // get Opcional User Data
//     char newRg[255];
//     char newAddress[255];
//     char newWage[255];
//     TypeWorker newType;

//     strcpy(newWorkerRegistrationNumber, generateUUID());
//     char myVar[255];
//     strcpy(myVar, "");
//     strcpy(newSiape, getMandatoryStringFieldFromUserInput(myVar, "Insira número SIAPE:"));
//     strcpy(newCpf, getMandatoryStringFieldFromUserInput(myVar, "Insira seu número de CPF:"));
//     strcpy(newName, getMandatoryStringFieldFromUserInput(myVar, "Insira seu Nome:"));
//     strcpy(newBirthday, getMandatoryStringFieldFromUserInput(myVar, "Insira sua data de aniversário"));
//     strcpy(newRg, getStringFieldFromUserInput(myVar, "(opcional) Insira seu número de RG"));
//     strcpy(newAddress, getStringFieldFromUserInput(myVar, "(opcional) Insira seu endereço"));
//     strcpy(newWage, getMandatoryStringFieldFromUserInput(myVar, "(opcional) Insira seu salário"));

//     int typeChoosen = 0;
//     typeChoosen = getIntegerFieldFromUserInput(myVar, "(opcional) Insira seu tipo: \n 0 - Nada\n 1- Docente\n 2- Técnico Admnistrativo\nResposta:");
//     switch(typeChoosen){
//         case 0:
//             newType = 0;
//             break;
//         case 1:
//             newType = 1;
//             break;
//         case 2:
//             newType = 2;
//             break;
//         default:
//             newType = 0;
//             break;
//     }

//     // Check if already exists registration number, cpf and siape
//     if((checkExists(newWorkerRegistrationNumber, 1) == -1) && (checkExists(newSiape, 2) == -1) && (checkExists(newCpf, 3) == -1)){ //} && (checkExists(newRg, 4) == -1)){
//         if(position == -1){
//             char positionChar[255];
//             do {
//                 position = getMandatoryIntegerFieldFromUserInput(positionChar, "Insira a posição desejada para armazenar os dados [1 a 20]:") - 1;
//             } while (!(position < MAX_WORKERS && position >= 0));
//         }

//         strcpy(workerRegistrationNumber[position], newWorkerRegistrationNumber);
//         strcpy(siape[position], newSiape);
//         strcpy(cpf[position], newCpf);
//         strcpy(name[position], newName);
//         strcpy(birthday[position], newBirthday);
//         strcpy(rg[position], newRg);
//         strcpy(address[position], newAddress);
//         strcpy(wage[position], newWage);
//         type[position] = newType;

//         spaceWorkers[position] = 1;
//         return true;
//     } else {
//         printf("\nFALHA: Código Gerado, SIAPE ou CPF repetido\n");
//         return false;
//     }
// }

// // - excluir um servidor —
// void deleteServer(int position){
//     if(position == -1){
//         char positionChar[255];
//         do {
//             position = getMandatoryIntegerFieldFromUserInput(positionChar, "Insira a posição desejada para deletar os dados [1 a 20]:") - 1;
//             printf("%d", position);
//         } while (!(position < MAX_WORKERS && position >= 0));
//     }

//     strcpy(workerRegistrationNumber[position], "vazio");
//     strcpy(siape[position], "vazio");
//     strcpy(cpf[position], "vazio");
//     strcpy(name[position], "vazio");
//     strcpy(birthday[position], "vazio");
//     strcpy(rg[position], "vazio");
//     strcpy(address[position], "vazio");
//     strcpy(wage[position], "vazio");
//     type[position] = 0;

//     spaceWorkers[position] = 0;
// }

// // - mostrar/imprimir dados de um servidor com base no código –
// void read(){
//     char registrationNumber[255];
//     strcpy(registrationNumber, getMandatoryStringFieldFromUserInput(registrationNumber, "Insira o código do servidor a ser lido"));

//     printf("\nServidor de código: {%s}\n", registrationNumber);
//     int idWorker = checkExists(registrationNumber, 1);

//     if(idWorker == -1){
//         printf("\nNão há esse código em nossos dados\n");
//     } else {
//         printAtPosition(idWorker);
//     }
// }
// // - mostrar/imprimir todos os servidores -
// void readAll(){
//     for(register int i = 0; i < MAX_WORKERS; i++){
//         printAtPosition(i);
//     }
// }

// // // - mostrar/imprimir todos os servidores em ordem alfabética pelo nome -
// void readAllOrderByName(){
//     int indexes[MAX_WORKERS];
//     orderPositionsAlphabetically(indexes, name, MAX_WORKERS);

//     for(register int i = 0; i < MAX_WORKERS; i ++){
//         printAtPosition(indexes[i]);
//     }
// }
// // - mostrar/imprimir todos os professores em ordem alfabética pelo nome -
// void teacherOrderByName(){
//     int indexes[MAX_WORKERS];
//     orderPositionsAlphabetically(indexes, name, MAX_WORKERS);

//     for(register int i = 0; i < MAX_WORKERS; i ++){
//         if(type[indexes[i]] == 2){
//             printAtPosition(indexes[i]);
//         }
//     }
// }
// // - mostrar/imprimir todos os técnicos administrativos em ordem alfabética pelo nome -
// void technicianOrderByName(){
//     int indexes[MAX_WORKERS];
//     orderPositionsAlphabetically(indexes, name, MAX_WORKERS);

//     for(register int i = 0; i < MAX_WORKERS; i ++){
//         if(type[indexes[i]] == 1){
//             printAtPosition(indexes[i]);
//         }
//     }
// }





// // Auxiliares
// // - checar se existe codidgo, cpf, siape e retornar id da position-
// int checkExists(char value[], int columnNumber){
//     switch(columnNumber){
//         //workerRegistrationNumber
//         case 1:
//             return findStringInArray(workerRegistrationNumber, MAX_WORKERS, value);
//             break;
//         //siape
//         case 2:
//             return findStringInArray(siape, MAX_WORKERS, value);
//             break;
//         //cpf
//         case 3:
//             return findStringInArray(cpf, MAX_WORKERS, value);
//             break;
//         //rg
//         case 4:
//             return findStringInArray(rg, MAX_WORKERS, value);
//             break;
//     }
// }


// // - print at position -
// void printAtPosition(int position){
//     if(spaceWorkers[position] == 1){
//         printf("\n%s\n", getDivider());

//         printf("\nPosição %d\n", position + 1);

//         printf("%-20s %s\n",   "Código do servidor:", workerRegistrationNumber[position]);
//         printf("%-20s %s\n",   "SIAPE:", siape[position]);
//         printf("%-20s %s\n",   "CPF:", cpf[position]);
//         printf("%-20s %s\n",   "Nome:", name[position]);
//         printf("%-20s %s\n",   "Data de Nascimento:", birthday[position]);
//         printf("%-20s %s\n",   "RG:", rg[position]);
//         printf("%-20s %s\n",   "Endereço:", address[position]);
//         printf("%-20s %s\n",   "Salário:", wage[position]);

//         switch(type[position]){
//             case 0:
//                 printf("%-20s Vazio", "Tipo:");
//                 break;
//             case 1:
//                 printf("%-20s Técnico Admnistrativo", "Tipo:");
//                 break;
//             case 2:
//                 printf("%-20s Docente", "Tipo:");
//                 break;
//         }

//         printf("\n%s\n", getDivider());
//     } else {
//         printf("\nNão há nada na posição %d\n", position + 1);
//     }
// }


// // Facade to initialize columns with null value
// void initializeWorkerColumns(){
//     for(register int i = 0; i < MAX_WORKERS; i++){
//         deleteServer(i);
//     }
// }

// void seeDatabase(){
//     printf("\nworkerRegistrationNumber:\n");
//     printStringArray(workerRegistrationNumber, MAX_WORKERS);
//     printf("\nsiape:\n");
//     printStringArray(siape, MAX_WORKERS);
//     printf("\ncpf:\n");
//     printStringArray(cpf, MAX_WORKERS);
//     printf("\nname:\n");
//     printStringArray(name, MAX_WORKERS);
//     printf("\nbirthday:\n");
//     printStringArray(birthday, MAX_WORKERS);
//     printf("\nrg:\n");
//     printStringArray(rg, MAX_WORKERS);
//     printf("\naddress:\n");
//     printStringArray(address, MAX_WORKERS);
//     printf("\nwage:\n");
//     printStringArray(wage, MAX_WORKERS);
//     printf("\ntype:\n");
//     printIntArray(type, MAX_WORKERS);
//     printf("\nspaceWorkers:\n");
//     printBoolArray(spaceWorkers, MAX_WORKERS);
// }