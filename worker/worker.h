#ifndef WORKER_H
#define WORKER_H
#endif //WORKER_H


#ifndef UTILS_H
#include "../util/utils.h"
#endif


bool createWorker();
bool updateWorker();
bool deleteWorker();
int readOneWorker(bool returnPosition);
bool readWorkers();
bool readWorkersAlphabetically();