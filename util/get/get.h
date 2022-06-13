#ifndef GET_H
#define GET_H
#endif //GET_H

#ifndef GENERAL_H
#include "../general/general.h"
#endif //GENERAL_H

// // get the vehicle description from the user
// char* getVehicleDescriptionFromUserInput();

// // get the vehicle brand from the user
// char* getVehicleBrandFromUserInput();

// // get the vehicle license plate from the user
// char* getVehicleLicensePlateFromUserInput();

// char* getVehicleModelFromUserInput();

// int getPositionFromUserInput();

// char getWillFromUserInput();



// get the vehicle description from the user
char* getVehicleDescriptionFromUserInput();

// get the vehicle brand from the user
char* getVehicleBrandFromUserInput();

// get the vehicle license plate from the user
char* getVehicleLicensePlateFromUserInput();

char* getVehicleModelFromUserInput();
char* getWorkerCodeFromUserInput();

int getPositionFromUserInput();
//

char getWillFromUserInput();


int getIntegerFieldFromUserInput(char* field, char msg[]);
bool checkStringIsNumber(char string[255]);

// removes trailling and leading spaces from a string
char* removeTrailingAndLeadingSpaces(char* string);

// get a string field from the user
char* getStringFieldFromUserInput(char* field, char msg[]);


// get a mandatory string field from the user
char* getMandatoryStringFieldFromUserInput(char* field, char msg[]);

char getMandatoryWillFieldFromUserInput();
// get a mandatory integer field from the user
int getMandatoryIntegerFieldFromUserInput(char* field, char msg[]);

