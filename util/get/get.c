#include "get.h"


// get the vehicle description from the user
char* getVehicleDescriptionFromUserInput(){
 char description[255];
 return getMandatoryStringFieldFromUserInput(description, "Digite a descrição do veículo: ");
}

// get the vehicle brand from the user
char* getVehicleBrandFromUserInput(){
 char brand[255];
 return getMandatoryStringFieldFromUserInput(brand, "Digite a marca do veículo: ");
}

// get the vehicle license plate from the user
char* getVehicleLicensePlateFromUserInput(){
 char licensePlate[255];
 return getMandatoryStringFieldFromUserInput(licensePlate, "Digite a placa do veículo: ");
}

char* getVehicleModelFromUserInput(){
 char model[255];
 return getMandatoryStringFieldFromUserInput(model, "Digite o modelo do veículo: ");
}

char* getWorkerCodeFromUserInput(){
 char code[255];
 return getMandatoryStringFieldFromUserInput(code, "Digite o código do trabalhador: ");
}

int getPositionFromUserInput(){
 char position[255];
 return getMandatoryIntegerFieldFromUserInput(position, "Digite a posição do veículo: ");
}
//

char getWillFromUserInput(){
    char will[255];
    return getMandatoryWillFieldFromUserInput(will);
}



int getIntegerFieldFromUserInput(char* field, char msg[]){
    printf("\n%s\n", msg);
    fgets(field, 255, stdin);
    return atoi(field);
}

bool checkStringIsNumber(char string[255]){
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


// get a string field from the user
char* getStringFieldFromUserInput(char* field, char msg[]){
    printf("\n%s\n", msg);
    fgets(field, 255, stdin);
    return removeTrailingAndLeadingSpaces(field);
}


// get a mandatory string field from the user
char* getMandatoryStringFieldFromUserInput(char* field, char msg[]){
  char* sanitizedString;
  do {
    sanitizedString = getStringFieldFromUserInput(field, msg);
  } while (strcmp(sanitizedString,"") == 0);
  return sanitizedString;
}

char getMandatoryWillFieldFromUserInput(){
  char will;
  do {
    will = getchar();
  } while (will != 's' && will != 'n');
  return will;
}

// get a mandatory integer field from the user
int getMandatoryIntegerFieldFromUserInput(char* field, char msg[]){
  int integer;

  do
  {
    integer = getIntegerFieldFromUserInput(field, msg);
  } while (integer == 0);

  return integer;
}


