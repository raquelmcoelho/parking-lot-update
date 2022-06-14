#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H
#endif //FILE_HANDLER_H

#ifndef GENERAL_H
#include "../general/general.h"
#endif //GENERAL_H

void _showAllWorkers();
void _showAllVehicles();
int _getWorkerBySearch(fieldPosition field, value value, bool searchWithString);

void _insertVehicleIntoDatabase(VEHICLE vehicle);
void _insertWorkerIntoDatabase(WORKER worker);
int _countStoredVehicleStructs();
int _countStoredWorkerStructs();
int _getSizeFile(char *filename);
bool fileExists(char *fileName);
void _showVehicleByIndex(int position);
void _showWorkerByIndex(int position);
void _showVehicle(VEHICLE vehicle);
void _showWorker(WORKER worker);


// achar espaço em branco
// sobrescrever
// achar posicao por campo 