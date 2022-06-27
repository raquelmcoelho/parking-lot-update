#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H
#endif //FILE_HANDLER_H

#ifndef GENERAL_H
#include "../general/general.h"
#endif //GENERAL_H


int _getWorkerIndexBySearch(fieldPosition fieldOffset, value valueToSearch);
int _getFirstIndexFreeForWorker();

void _insertVehicleIntoDatabase(VEHICLE vehicle);
bool _insertWorkerIntoDatabase(WORKER worker);

void _showAllWorkers();

void _showVehicleByIndex(int position);
void _showWorkerByIndex(int position);

WORKER _getWorkerByIndex(int position);

void _showVehicle(VEHICLE vehicle);
void _showWorker(WORKER worker);

int _countStoredVehicleStructs();
int _countStoredWorkerStructs();

FILE* _getFile(char* filename);
int _getSizeFile(char *filename);
bool fileExists(char *fileName);