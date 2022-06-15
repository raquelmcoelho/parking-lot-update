#include "file_handler.h"


void _showAllWorkers()
{
    FILE *fp;
    int position = 0;
    WORKER worker;
    fp = _getFile(worker_filename);
    fseek(fp, 0L, SEEK_SET);
    while(position < _countStoredWorkerStructs()){
        printf("position: %d\n", position);
        fread(&worker, sizeof(WORKER), 1, fp);
        _showWorker(worker);
        position++;
    }
    fclose(fp);
}

void _showAllVehicles()
{
    FILE *fp;
    int position = 0;
    VEHICLE vehicle;
    fp = fopen("vehicle_database.bin", "rb+");
    fseek(fp, 0L, SEEK_SET);
    while(position < _countStoredVehicleStructs()){
        printf("position: %d\n", position);
        fread(&vehicle, sizeof(VEHICLE), 1, fp);
        _showVehicle(vehicle);
        position++;
    }
    fclose(fp);
}

int _getWorkerIndexBySearch(fieldPosition fieldOffset, value valueToSearch){
    FILE *fp;
    WORKER worker;
    int position = 0;
    fp = _getFile(worker_filename);
    fseek(fp, 0L, SEEK_SET);

    while(position < _countStoredWorkerStructs()){
        fread(&worker, sizeof(WORKER), 1, fp);
        printf("\nposition: %d", position);
        if(fieldOffset != field_code){
            char* valueFinded = ((char*)&worker + (size_t)fieldOffset);
            printf("\nworker value to search: %s", valueToSearch.string);
            printf("\nworker valor achado no field: %s", valueFinded);
            if(strcmp(valueFinded, valueToSearch.string) == 0) return position;
        } else {
            int valueFinded = *(int*)((char*)&worker + (size_t)fieldOffset);
            printf("\nworker value to search: %d", valueToSearch.integer);
            printf("\nworker valor achado no field: %d\n", valueFinded);
            if(valueFinded == valueToSearch.integer) return position;
        }
        position++;
    }
    fclose(fp);
    return -1;
}

void _insertVehicleIntoDatabase(VEHICLE vehicle)
{
    FILE *fp;
    fp = fopen("vehicle_database.bin", "rb+");
    fseek(fp, 0L, SEEK_END);
    if (fwrite(&vehicle, sizeof(vehicle), 1, fp) != 1)
        printf("Falhou a escrita do registro");
    fclose(fp);
}

void _insertWorkerIntoDatabase(WORKER worker)
{
    // TODO: fluxo de achar posição com status 0 para sobreescrever
    FILE *fp;
    worker.code = _countStoredWorkerStructs();
    fp = _getFile(worker_filename);
    fseek(fp, 0L, SEEK_END);
    if (fwrite(&worker, sizeof(worker), 1, fp) != 1)
        printf("Falhou a escrita do registro");
    fclose(fp);
}

int _countStoredVehicleStructs()
{
    return _getSizeFile("vehicle_database.bin") / sizeof(VEHICLE);
}

int _countStoredWorkerStructs()
{
    return _getSizeFile(worker_filename) / sizeof(WORKER);
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
    if (file == NULL)
    {
    return false;
    }
    fclose(file);
    return true;
}


void _showVehicleByIndex(int position)
{
    FILE *fp;
    VEHICLE vehicle;
    fp = fopen("vehicle_database.bin", "rb+");
    fseek(fp, position * sizeof(VEHICLE), SEEK_SET);
    fread(&vehicle, sizeof(VEHICLE), 1, fp);
    _showVehicle(vehicle);
    fclose(fp);
}

void _showWorkerByIndex(int position)
{
    FILE *fp;
    WORKER worker;
    fp = _getFile(worker_filename);
    fseek(fp, position * sizeof(WORKER), SEEK_SET);
    fread(&worker, sizeof(WORKER), 1, fp);
    _showWorker(worker);
    fclose(fp);
}


void _showVehicle(VEHICLE vehicle)
{
    if(vehicle.status){
        printf("Placa: %s\n", vehicle.licensePlate);
        printf("Descrição: %s\n", vehicle.description);
        printf("Marca: %s\n", vehicle.brand);
        printf("Modelo: %s\n", vehicle.model);
        printf("Código do Trabalhador: %d\n", vehicle.workerCode);
    }
}

void _showWorker(WORKER worker){
    if(worker.status){
        printf("Código:  %d\n", worker.code);
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
    }
}

FILE* _getFile(char* filename){
    FILE* file;

    if(!(fileExists(filename))){
        file = fopen(filename, "wb+");
    }

    file = fopen(filename, "rb+");
    
    if (file == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    return file;
}
