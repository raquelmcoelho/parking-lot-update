#ifndef GET_H
#define GET_H
#endif //GET_H

#ifndef GENERAL_H
#include "../general/general.h"
#endif //GENERAL_H


char* getVehicleDescriptionFromUserInput();
char* getVehicleBrandFromUserInput();
char* getVehicleLicensePlateFromUserInput();
char* getVehicleModelFromUserInput();
int getPositionFromUserInput();
int getWorkerCodeFromUserInput();
char* getWorkerNameFromUserInput();
char* getWorkerSiapeFromUserInput();
char* getWorkerCpfFromUserInput();
char* getWorkerBirthdayFromUserInput();
char* getWorkerRgFromUserInput();
char* getWorkerAddressFromUserInput();
char* getWorkerWageFromUserInput();
type getWorkerTypeFromUserInput();


bool getMandatoryWillFieldFromUserInput();
int getMandatoryIntegerFieldFromUserInput(char* field, char msg[]);
char* getMandatoryStringFieldFromUserInput(char* field, char msg[]);

int getIntegerFieldFromUserInput(char* field, char msg[]);
char* getStringFieldFromUserInput(char* field, char msg[]);

bool checkStringIsNumber(char string[255]);
char* removeTrailingAndLeadingSpaces(char* string);

