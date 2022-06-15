#include "file_handler.h"

void _showAllWorkersAlphabetically(type filter){
    WORKER worker;
    FILE* fp = _getFile(worker_filename);
    int sizeFile = _countStoredWorkerStructs();
    tuple_order_worker v[sizeFile];

    // populating tuples
    for(int count = 0; count < sizeFile; count++){
        if (fread(&worker, sizeof(WORKER), 1, fp) != 1)
            break;

        v[count].index = count;
        strcpy(v[count].name, worker.name);
        v[count].type = worker.type;
        v[count].status = worker.status;
    }

    // bubble sort
    for (int i = 0; i < _countStoredVehicleStructs(); i++)
    {
        for (int j = 0; j < _countStoredVehicleStructs() - 1; j++)
        {

            if (strcmp(v[j].name, v[j + 1].name) > 0)
            {

                tuple_order_worker aux = v[j];

                v[j] = v[j + 1];

                v[j + 1] = aux;
            }
        }
    }

    // show all filtered and ordered
    for(int index; index < sizeFile; index++){
        if(filter == v[index].type || filter == 0){
            if(v[index].status != deleted){
                _showWorkerByIndex(v[index].index);
            }
        }
    }

    fclose(fp);

}

int _getWorkerIndexBySearch(fieldPosition fieldOffset, value valueToSearch){
    FILE *fp;
    WORKER worker;
    int position = 0;
    fp = _getFile(worker_filename);
    fseek(fp, 0L, SEEK_SET);

    while(fread(&worker, sizeof(WORKER), 1, fp) == 1){
        if(worker.status != deleted){
            char* valueFinded = ((char*)&worker + (size_t)fieldOffset);
            printf("\nPesquisando: valueFinded = %s, valueToSearch = %s, é igual? %d\n", valueFinded, valueToSearch.string, (strcmp(valueFinded, valueToSearch.string) == 0));

            if(fieldOffset != field_code){
                if(strcmp(valueFinded, valueToSearch.string) == 0) return position;
                printf(" é igual? %d\n ", strcmp(valueFinded, valueToSearch.string) == 0);
            } else {
                printf("entrando no inteiro");
                printf("\nPesquisando: valueFinded = %d  valueToSearch = %d ", *(int*)valueFinded, valueToSearch.integer);
                printf(" é igual? %d\n ", valueFinded == valueToSearch.integer);
                if(*(int*)valueFinded == valueToSearch.integer) return position;
            }
        }
        position++;
    }
    fclose(fp);
    return -1;
}

int _getFirstIndexFreeForWorker(){
    FILE *fp;
    WORKER worker;
    int position = 0;
    fp = _getFile(worker_filename);
    fseek(fp, 0L, SEEK_SET);

    while(fread(&worker, sizeof(WORKER), 1, fp) == 1){
        if(worker.status == deleted) return position;
        position++;
    }

    fclose(fp);
    return position;
}

// TODO: igualar ambas
void _insertVehicleIntoDatabase(VEHICLE vehicle)
{
    FILE *fp;
    fp = _getFile(vehicle_filename);
    fseek(fp, 0L, SEEK_END);
    if(fwrite(&vehicle, sizeof(vehicle), 1, fp) != 1)
        printf("Falhou a escrita do registro");
    fclose(fp);
}

bool _insertWorkerIntoDatabase(WORKER worker)
{
    FILE *fp;
    fp = _getFile(worker_filename);
    fseek(fp, (long)worker.code * sizeof(WORKER), SEEK_SET);
    if(fwrite(&worker, sizeof(worker), 1, fp) != 1){
        printf("Falhou a escrita do registro");
        return false;
    }
    fclose(fp);
    return true;
}


void _showAllVehicles()
{
    FILE *fp;
    VEHICLE vehicle;
    fp = _getFile(vehicle_filename);
    fseek(fp, 0L, SEEK_SET);
    while(fread(&vehicle, sizeof(VEHICLE), 1, fp) == 1){
        if(vehicle.status != deleted){
            _showVehicle(vehicle);
        }
    }
    fclose(fp);
}

void _showAllWorkers()
{
    FILE *fp;
    WORKER worker;
    fp = _getFile(worker_filename);
    fseek(fp, 0L, SEEK_SET);
    while(fread(&worker, sizeof(WORKER), 1, fp) == 1){
        if(worker.status != deleted){
            _showWorker(worker);
        }
    }
    fclose(fp);
}


void _showVehicleByIndex(int position)
{
    _showVehicle(_getVehicleByIndex(position));
}

void _showWorkerByIndex(int position)
{
    _showWorker(_getWorkerByIndex(position));
}


WORKER _getWorkerByIndex(int position)
{
    WORKER workerReturned, workerTested;
    if(position <= _countStoredWorkerStructs() && position >= 0){
        FILE *fp;
        fp = _getFile(worker_filename);
        fseek(fp, position * sizeof(WORKER), SEEK_SET);
        if(fread(&workerTested, sizeof(WORKER), 1, fp) == 1){
            workerReturned = workerTested;
        }
        fclose(fp);
    }
    return workerReturned;
}

VEHICLE _getVehicleByIndex(int position)
{
    VEHICLE vehicleReturned, vehicleTested;
    if(position <= _countStoredVehicleStructs() && position >= 0){
        FILE *fp;
        fp = _getFile(vehicle_filename);
        fseek(fp, position * sizeof(VEHICLE), SEEK_SET);
        if(fread(&vehicleTested, sizeof(VEHICLE), 1, fp) == 1){
            vehicleReturned = vehicleTested;
        }
        fclose(fp);
    }
    return vehicleReturned;
}


void _showVehicle(VEHICLE vehicle)
{
    printf("Placa: %s\n", vehicle.licensePlate);
    printf("Descrição: %s\n", vehicle.description);
    printf("Marca: %s\n", vehicle.brand);
    printf("Modelo: %s\n", vehicle.model);
    printf("Código do Trabalhador: %d\n", vehicle.workerCode);
}

void _showWorker(WORKER worker){
    printf(getDivider());
    printf("\nCódigo:  %d\n", worker.code);
    printf("Nome: %s\n", worker.name);
    printf("SIAPE: %s\n", worker.siape);
    printf("Cpf: %s\n", worker.cpf);
    printf("Data de nascimento: %s\n", worker.birthday);
    printf("RG: %s\n", worker.rg);
    printf("Endereço: %s\n", worker.address);    
    printf("Salário: %s\n", worker.wage);
    switch(worker.type){
        case 1:
            printf("Tipo: %s\n", "Técnico Admnistrativo");
            break;
        case 2:
            printf("Tipo: %s\n", "Professor");
            break;
        default:
            printf("Tipo: %s\n", "Sem tipo");
            break;
    }
    printf(getDivider());
}


int _countStoredVehicleStructs()
{
    return _getSizeFile(vehicle_filename) / sizeof(VEHICLE);
}

int _countStoredWorkerStructs()
{
    return _getSizeFile(worker_filename) / sizeof(WORKER);
}


FILE* _getFile(char* filename){
    FILE* file;

    if(!(fileExists(filename))){
        file = fopen(filename, "wb+");
    }

    file = fopen(filename, "rb+");
    
    if(file == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    return file;
}

int _getSizeFile(char *filename){
    FILE *fp;
    fp = _getFile(filename);
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    fclose(fp);
    return size;
}

bool fileExists(char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if(file == NULL)
    {
    return false;
    }
    fclose(file);
    return true;
}

