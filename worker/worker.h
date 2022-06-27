#ifndef WORKER_H
#define WORKER_H
#endif //WORKER_H


#ifndef UTILS_H
#include "../util/utils.h"
#endif


feedback createWorker();
feedback updateWorker();
void _deleteVehiclesOfWorker(int workerIndex);
feedback deleteWorker();
int readOneWorker(bool returnPosition);