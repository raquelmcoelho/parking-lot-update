#include "worker.h"

feedback createWorker()
{
    WORKER worker;
    value searchQuery;
    int positionFindBySearch = -1;

    strcpy(worker.name, getWorkerNameFromUserInput());

    do{
        strcpy(worker.siape, getWorkerSiapeFromUserInput());
        strcpy(searchQuery.string, worker.siape);
        positionFindBySearch = _getWorkerIndexBySearch(field_siape, searchQuery);
        if(positionFindBySearch != -1){
            printf("\nEste SIAPE já está em nosso banco de dados!\n");
        }
    } while (positionFindBySearch != -1);

    do{
        strcpy(worker.cpf, getWorkerCpfFromUserInput());
        strcpy(searchQuery.string, worker.cpf);
        positionFindBySearch = _getWorkerIndexBySearch(field_cpf, searchQuery);
        if(positionFindBySearch != -1){
            printf("\nEste CPF já está em nosso banco de dados!\n");
        }
    } while (positionFindBySearch != -1);

    strcpy(worker.birthday, getWorkerBirthdayFromUserInput());
    strcpy(worker.rg, getWorkerRgFromUserInput());
    strcpy(worker.address, getWorkerAddressFromUserInput());
    strcpy(worker.wage, getWorkerWageFromUserInput());
    worker.type = getWorkerTypeFromUserInput();
    worker.status = active;
    worker.code = _getFirstIndexFreeForWorker();
    printf("\nPrimeiro código livre achado: %d", worker.code);

    if (_insertWorkerIntoDatabase(worker))
    {
        printf("\nOs dados inseridos foram:\n");
        _showWorker(worker);
        return success;
    }
    else
    {
        return failed;
    }
}

feedback updateWorker()
{
    WORKER worker;
    value searchQuery;
    int positionFindBySearch = -1;
    int position = readOneWorker(true);
    if (position == -1)
        return failed;

    worker = _getWorkerByIndex(position);
    if (worker.status == deleted)   // it means that get worker by index failed, because the status was already filtered  at search function
        return failed;


    printf("\nDeseja alterar o nome?(s/n) \n");
    if (getMandatoryWillFieldFromUserInput())
    {
        strcpy(worker.name, getWorkerNameFromUserInput());
    }

    printf("Deseja alterar o siape?(s/n) \n");
    if (getMandatoryWillFieldFromUserInput())
    {
        do
        {
            strcpy(worker.siape, getWorkerSiapeFromUserInput());
            strcpy(searchQuery.string, worker.siape);
            positionFindBySearch = _getWorkerIndexBySearch(field_siape, searchQuery);
            if (positionFindBySearch != -1 && positionFindBySearch != worker.code)
            {
                printf("\nEste SIAPE já está em nosso banco de dados!\n");
            }
        } while (positionFindBySearch != -1 && positionFindBySearch != worker.code);
    }

    printf("Deseja alterar o cpf?(s/n) \n");
    if (getMandatoryWillFieldFromUserInput())
    {
        do
        {
            strcpy(worker.cpf, getWorkerCpfFromUserInput());
            strcpy(searchQuery.string, worker.cpf);
            positionFindBySearch = _getWorkerIndexBySearch(field_cpf, searchQuery);
            if (positionFindBySearch != -1 && positionFindBySearch != worker.code)
            {
                printf("\nEste CPF já está em nosso banco de dados!\n");
            }
        } while (positionFindBySearch != -1 && positionFindBySearch != worker.code);
    }

    printf("Deseja alterar a data de nascimento?(s/n) \n");
    if (getMandatoryWillFieldFromUserInput())
    {
        strcpy(worker.birthday, getWorkerBirthdayFromUserInput());
    }
    printf("Deseja alterar o rg?(s/n) \n");
    if (getMandatoryWillFieldFromUserInput())
    {
        strcpy(worker.rg, getWorkerRgFromUserInput());
    }
    printf("Deseja alterar o endereço?(s/n) \n");
    if (getMandatoryWillFieldFromUserInput())
    {
        strcpy(worker.address, getWorkerAddressFromUserInput());
    }
    printf("Deseja alterar o salário?(s/n) \n");
    if (getMandatoryWillFieldFromUserInput())
    {
        strcpy(worker.wage, getWorkerWageFromUserInput());
    }
    printf("Deseja alterar o tipo?(s/n) \n");
    if (getMandatoryWillFieldFromUserInput())
    {
        worker.type = getWorkerTypeFromUserInput();
    }

    if (_insertWorkerIntoDatabase(worker))
    {
        printf("\nOs dados agora estão assim:\n");
        _showWorker(worker);
        return success;
    }
    else
    {
        return failed;
    }
}

// Cascade delete of vehicles
void _deleteVehiclesOfWorker(int workerIndex)
{
    VEHICLE vehicle;
    FILE *fp;
    int i = 0;

    // Get the vehicle file
    fp = _getFile(vehicle_filename);
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    // Iterate over the file
    // Search for vehicles referencing the workerIndex
    // Update the status of the vehicle to deleted in memory
    // Update the vehicle on the file
    while (true)
    {

        // Read the vehicle from the file, break if it's the end of the file
        if (fread(&vehicle, sizeof(vehicle), 1, fp) != 1)
            break;

        // If the vehicle references the workerIndex, update the status to deleted
        if (vehicle.workerCode == workerIndex && vehicle.status != deleted)
        {
            // Update the status of the vehicle to deleted in memory
            vehicle.status = deleted;
            // Update the vehicle on the file
            fseek(fp, -sizeof(vehicle), SEEK_CUR);
            fwrite(&vehicle, sizeof(vehicle), 1, fp);
        }

        i++;
    }
    fflush(fp);
}

feedback deleteWorker()
{
    WORKER worker;

    int position = readOneWorker(true);
    if (position == -1)
        return failed;

    worker = _getWorkerByIndex(position);
    if (worker.status == deleted)   // it means that get worker by index failed, because the status was already filtered  at search function
        return failed;

    worker.status = deleted;

    printf("\nDeletando funcionário de código %d\n", worker.code);

    _deleteVehiclesOfWorker(worker.code);

    return _insertWorkerIntoDatabase(worker) ? success : failed;
}

int readOneWorker(bool returnPosition)
{
    WORKER worker;
    value searchQuery;
    int positionFindBySearch = -1;

    printf("\nInsira o codigo do servidor que deseja:\n");
    searchQuery.integer = getWorkerCodeFromUserInput(); 
    positionFindBySearch = _getWorkerIndexBySearch(field_code, searchQuery); // only searches in active workers

    if (positionFindBySearch == -1)
    {
        printf("\nNão há servidor com este código em nossos registros\n");
        return returnPosition ? -1 : 0;
    }

    worker = _getWorkerByIndex(positionFindBySearch);
    if (worker.status == deleted)   // it means that get worker by index failed, because the status was already filtered  at search function
        return returnPosition? -1 : 0;

    printf("\nUm registro foi encontrado:\n");
    _showWorker(worker);
    return returnPosition ? worker.code : 1;
}
