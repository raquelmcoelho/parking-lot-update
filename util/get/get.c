#include "get.h"


// get the vehicle description from the user
char* getVehicleDescriptionFromUserInput(){
  char description[255];
  return getMandatoryStringFieldFromUserInput(description, "(obrigatório) Digite a descrição do veículo: ");
}

// get the vehicle brand from the user
char* getVehicleBrandFromUserInput(){
  char brand[255];
  return getMandatoryStringFieldFromUserInput(brand, "(obrigatório) Digite a marca do veículo: ");
}

// get the vehicle license plate from the user
char* getVehicleLicensePlateFromUserInput(){
  char licensePlate[255];
  return getMandatoryStringFieldFromUserInput(licensePlate, "(obrigatório) Digite a placa do veículo: ");
}

char* getVehicleModelFromUserInput(){
  char model[255];
  return getMandatoryStringFieldFromUserInput(model, "(obrigatório) Digite o modelo do veículo: ");
}

int getPositionFromUserInput(){
  char position[255];
  return getMandatoryIntegerFieldFromUserInput(position, "(obrigatório) Digite a posição do veículo (apenas dígitos): ");
}

int getWorkerCodeFromUserInput(){
  char code[255];
  return getMandatoryIntegerFieldFromUserInput(code, "(obrigatório) Digite o código do servidor (apenas dígitos): ");
}

char * getWorkerNameFromUserInput(){
    char name[255];
    return getMandatoryStringFieldFromUserInput(name, "(obrigatório) Digite o nome do servidor: ");
}
char * getWorkerSiapeFromUserInput(){
    char siape[255];
    return getMandatoryStringFieldFromUserInput(siape, "(obrigatório) Digite o siape do servidor: ");
}
char * getWorkerCpfFromUserInput(){
    char cpf[255];
    return getMandatoryStringFieldFromUserInput(cpf, "(obrigatório) Digite o cpf do servidor: ");
}
char * getWorkerBirthdayFromUserInput(){
    char birthday[255];
    return getMandatoryStringFieldFromUserInput(birthday, "(obrigatório) Digite o dia de nascimento do servidor: ");
}

char * getWorkerRgFromUserInput(){
    char rg[255];
    return getStringFieldFromUserInput(rg, "(opcional) Digite o rg do servidor: ");
}

char * getWorkerAddressFromUserInput(){
    char address[255];
    return getStringFieldFromUserInput(address, "(opcional) Digite o endereço do servidor: ");
}

char * getWorkerWageFromUserInput(){
    char wage[255];
    return getStringFieldFromUserInput(wage, "(opcional) Digite o salário do servidor: ");
}

type getWorkerTypeFromUserInput(){
    int type_int = 0;
    char type_char[255];
    type_int = getIntegerFieldFromUserInput(type_char, "(opcional)Digite o tipo do servidor:\n 1 - Técnico Administrativo \n 2 - Docente \n Entre com o número da opção: \n");

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


bool getWillFromUserInput(){
    char will[255];
    return getMandatoryWillFieldFromUserInput(will);
}


bool getMandatoryWillFieldFromUserInput(){
  char will;
  do {
    will = getchar();
  } while (will != 's' && will != 'n');
  return (will == 's');
}

int getIntegerFieldFromUserInput(char* field, char msg[]){
    printf("\n%s\n", msg);
    fgets(field, 255, stdin);
    field[strlen(field) - 1] = '\0';
    return atoi(field);
}

bool checkStringIsNumber(char string[255]){
    if(strlen(string) == 0) return false;
    for(unsigned int i = 0; i < strlen(string); i++){
        if(isalpha(string[i]) || !isdigit(string[i])){
            return false;
        }
    }
    return true;
}


// removes trailling and leading spaces from a string
char* removeTrailingAndLeadingSpaces(char* string){
    char* newString = malloc(sizeof(char) * 255);
    int i = 0;
    while(string[i] == ' '){
        i++;
    }
    int j = 0;
    while(string[strlen(string) - 1 - j] == ' '){
        j++;
    }
    for(register unsigned int k = i; k < strlen(string) - j; k++){
        newString[k - i] = string[k];
    }
    newString[strlen(string) - j -1] = '\0';
    return newString;
}


char* getStringFieldFromUserInput(char* field, char msg[]){
    printf("\n%s\n", msg);
    fgets(field, 255, stdin);
    return removeTrailingAndLeadingSpaces(field);
}


char* getMandatoryStringFieldFromUserInput(char* field, char msg[]){
  char* sanitizedString;
  do {
    sanitizedString = getStringFieldFromUserInput(field, msg);
  } while (strcmp(sanitizedString,"") == 0);
  return sanitizedString;
}

int getMandatoryIntegerFieldFromUserInput(char* field, char msg[]){
  int integer;

  do
  {
    integer = getIntegerFieldFromUserInput(field, msg);
  } while (!checkStringIsNumber(field));

  return integer;
}


