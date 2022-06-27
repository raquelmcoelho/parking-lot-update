
#include "vehicle.h"

#ifdef DEBUG
#define DEBUG_PRINTF(...)             \
    do                                \
    {                                 \
        fprintf(stderr, __VA_ARGS__); \
    } while (false)
#else
#define DEBUG_PRINTF(...) \
    do                    \
    {                     \
    } while (false)
#endif

bool _verifyWorkerExistsOnDatabase(int code){
    bool workerExistisOnDatabase = false;
    FILE *file = _getFile(worker_filename);;
    WORKER worker;
    while (fread(&worker, sizeof(WORKER), 1, file) == 1)
    {
        if (code == worker.code && worker.status != deleted)
        {
            workerExistisOnDatabase = true;
            break;
        }
    }
    fclose(file);
    return workerExistisOnDatabase;
}


bool _verifyDescriptionExistisOnDatabase(char *description)
{
    bool descriptionExistisOnDatabase = false;
    FILE *file = _getFile(vehicle_filename);;
    VEHICLE vehicle;
    while (fread(&vehicle, sizeof(VEHICLE), 1, file) == 1)
    {
        if (strcmp(description, vehicle.description) == 0)
        {
            descriptionExistisOnDatabase = true;
            break;
        }
    }
    fclose(file);
    return descriptionExistisOnDatabase;
}

/* Lê os dados  de um registro intrduzidos pelo usuário*/
void _readVehicle(VEHICLE *vehicle)
{
    // vessels for user input
    char licensePlate[255];
    char description[255];
    char brand[255];
    char model[255];
    char workerCode[255];
    bool descriptionAlreadyExists;
    bool workerExists;

    // get license plate
    getMandatoryStringFieldFromUserInput(licensePlate, "(obrigatório) Digite a placa do veículo: ");
    strcpy(vehicle->licensePlate, licensePlate);

    do
    {
        // get description
        getMandatoryStringFieldFromUserInput(description, "(obrigatório) Digite a descrição do veículo: ");
        strcpy(vehicle->description, description);
        // description must be unique, so we assert that it is not on database
        descriptionAlreadyExists = _verifyDescriptionExistisOnDatabase(vehicle->description);

        if (descriptionAlreadyExists)
        {
            printf("Já existe um veículo com essa descrição.\n");
            printf("Por favor, insira outra descrição.\n");
        }
    } while (descriptionAlreadyExists);

    // get brand
    getMandatoryStringFieldFromUserInput(brand, "(obrigatório) Digite a marca do veículo: ");
    strcpy(vehicle->brand, brand);

    // get model
    getMandatoryStringFieldFromUserInput(model, "(obrigatório) Digite o modelo do veículo: ");
    strcpy(vehicle->model, model);

    // get worker code
    do{
        vehicle->workerCode = getWorkerCodeFromUserInput();
        workerExists = _verifyWorkerExistsOnDatabase(vehicle->workerCode);
        if(!workerExists){
            printf("O servidor não existe em nosso banco de dados.\n");
            printf("Por favor, insira outro código.\n");
        }
    } while(!workerExists);

    vehicle->status = active;
}



// pedir campos da struct
// checar uniquidade do campo inserido
// iterar arquivo e ve se há espaço vazio
// se não existir
//     append struct no file
// se existir
//     sobrescreve naquela posicao livre

// create a new vehicle
feedback createVehicle()
{

    VEHICLE vehicle;
    // read the vehicle data
    _readVehicle(&vehicle);
    // add the vehicle to the database
    _insertVehicleIntoDatabase(vehicle);

    return pass;
}

// pegar struct por codigo
// se nao existir
//     retorna false
// printa struct
// retorna true

// 0 -> 1
// 1 -> 2
// 2 -> 3
// --
// 1 -> 1
// 2 -> 2
// 3 -> 3

// read vehicle of certain position
feedback showVehicleByCode()
{
    VEHICLE vehicle;
    FILE *fp;
    int vehicleCode;
    char vehicleCodeVessel[255];
    vehicleCode = getMandatoryIntegerFieldFromUserInput(vehicleCodeVessel, "Digite o código do veículo: ");
    vehicleCode--; // to make it 0-indexed. 1->0->1
    fp = _getFile(vehicle_filename);
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return failed;
    }

    // fseek to the position of the vehicle
    if(fseek(fp, vehicleCode * sizeof(VEHICLE), SEEK_SET) != 0)
    {
        printf("Registro Inexistente ou Problemas no Posicionamento!!!");
        return failed;
    }
    // read the vehicle
    if (fread(&vehicle, sizeof(VEHICLE), 1, fp) != 1)
    {
        printf("Problemas na leitura do Registro!!!");
        return failed;
    }

    if (vehicle.status != deleted)
    {
        _showVehicle(vehicle);
        return success;
    } else {
        printf("O veículo não existe.\n");
        return failed;
    }
}

// pegar struct por codigo
// se nao existir
//     retorna false
// setar flag ocupada pra 0
// printa struct
// sobrescreve struct alterada no arquivo na posicao achada
// retorna true
feedback deleteVehicle()
{
    VEHICLE vehicle;
    FILE *fp;
    long int n_reg;
    bool resp;

    char vehicleCodeVessel[255];

    fp = _getFile(vehicle_filename);

    printf("Código do veículo a ser apagado: ");
    // scanf("%ld", &n_reg);
    n_reg = getMandatoryIntegerFieldFromUserInput(vehicleCodeVessel, "Digite o código do veículo: ");

    if (fseek(fp, (n_reg - 1) * sizeof(VEHICLE), SEEK_SET) != 0)
    {
        printf("Registro Inexistente ou Problemas no Posicionamento!!!");
        return failed;
    }
    if (fread(&vehicle, sizeof(VEHICLE), 1, fp) != 1)
    {
        printf("Problemas na leitura do Registro!!!");
        return failed;
    }
    if (vehicle.status == deleted)
    {
        printf("O registro já está apagado!!!\n\n");
        return failed;
    }

    printf("\n\nDados Atuais\n\n");
    _showVehicle(vehicle);

    printf("\n\nApagar o Registro (s/n)???: ");
    resp = getMandatoryWillFieldFromUserInput();
    DEBUG_PRINTF("resp: %d\n", resp);
    
    if (!resp)
        return pass;

    vehicle.status = deleted;
    // Recuar um Registro no Arquivo
    fseek(fp, -(long)sizeof(VEHICLE), SEEK_CUR);
    // Reescrever o Registro;
    fwrite(&vehicle, sizeof(VEHICLE), 1, fp);
    fflush(fp); /*Despejar os Dados no Disco Rígido*/

    return success;
}

// se não existir registro
//     avisa na tela
// itera arquivo inteiro
// pega struct na posicao
// printa struct
// retorna true;

// read all vehicles
feedback readAllVehicles()
{
    VEHICLE vehicle;
    FILE *fp;
    fp = _getFile(vehicle_filename);
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return failed;
    }

    while (1)
    {
        if (fread(&vehicle, sizeof(vehicle), 1, fp) != 1)
            break;
        if (vehicle.status == deleted)
            continue;
        _showVehicle(vehicle);
    }
    return success;
}

// pegar struct por codigo
// se nao existir
//     retorna false
// printa struct
// perguntar campo a campo se va querer editar ou não
// se quiser
//     edita campo
//     se for campo unico
//         checar uniquidade do campo inserido
// sobrescreve struct alterada no arquivo na posicao achada
// update an existing vehicle
feedback updateVehicle()
{
    VEHICLE vehicle;
    FILE *fp;
    long int n_reg;

    char vehicleCodeVessel[255];

    fp = _getFile(vehicle_filename);

    printf("Código do Veículo a ser alterado: ");
    n_reg = getMandatoryIntegerFieldFromUserInput(vehicleCodeVessel, "Digite o código do veículo: ");

    fflush(stdin);
    if (fseek(fp, (n_reg - 1) * sizeof(VEHICLE), SEEK_SET) != 0)
    {
        printf("Registro Inexistente ou Problemas no Posicionamento!!!");
        return failed;
    }

    if (fread(&vehicle, sizeof(VEHICLE), 1, fp) != 1)
    {
        printf("Problemas na leitura do Registro!!!");
        return failed;
    }

    printf("\n\nDados Atuais\n\n");
    _showVehicle(vehicle);
    printf("\n\nNovos Dados\n\n");
    _readVehicle(&vehicle);

    // Recuar um Registro no Arquivo
    fseek(fp, -(long)sizeof(VEHICLE), SEEK_CUR);
    // Reescrever o Registro;
    fwrite(&vehicle, sizeof(VEHICLE), 1, fp);
    fflush(fp); /*Despejar os Dados no Disco Rígido*/

    return success;
}


//     itera arquivo inteiro
//     pega struct na posicao
//     tranforma em tupla com o campo a ser ordenado (nome/descricao)
//     ordena tuplas
//     itera tuplas
//         pega struct na posicao da tupla
//         filtro não existir || filtro for satisfeito
//             printa struct na posicao do tupla
//     fechar arquivo

// Read the i-th vehicle
// Make a tuple-3 of i, the i-th description and the status
// Add the tuple-3 to a list
// Sort the list by the second element of the tuple-3
// Map the list to the first element of the tuple-3
// Such list is the indexes ordered by the description alphabetically
// For each index in the list, show the i-th vehicle

feedback readVehiclesInAlphabeticalOrder(bool ofWorkerMode)
{
    VEHICLE vehicle;
    const int sizeFile = _countStoredVehicleStructs();
    tuple_order_vehicle v[sizeFile];
    FILE *fp;
    int i = 0;
    int workerCode = -1;
    char workerCodeVessel[255];

    fp = _getFile(vehicle_filename);
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return failed;
    }

    if (ofWorkerMode)
    {
        workerCode = getMandatoryIntegerFieldFromUserInput(workerCodeVessel, "Digite o código do funcionário: ");
        fflush(stdin);
    }

    for (int i = 0; i < sizeFile; i++)
    {

        if (fread(&vehicle, sizeof(vehicle), 1, fp) != 1)
            break;

        v[i].index = i;
        strcpy(v[i].description, vehicle.description);
        v[i].workerCode = vehicle.workerCode;
        v[i].status = vehicle.status;
    }

    // Bubble sort
    for (int i = 0; i < sizeFile; i++)
    {
        for (int j = 0; j < sizeFile - 1; j++)
        {

            if (strcmp(v[j].description, v[j + 1].description) > 0)
            {

                tuple_order_vehicle aux = v[j];

                v[j] = v[j + 1];

                v[j + 1] = aux;
            }
        }
    }

    int numberOfShownVehicles = 0;

    // For each index in the list, show the i-th vehicle
    for (int i = 0; i < sizeFile; i++)
    {
        if (v[i].status == deleted || (ofWorkerMode && v[i].workerCode != workerCode))
            continue;
        printf("Código do Veículo: %d\n", v[i].index + 1);
        _showVehicleByIndex(v[i].index);
        numberOfShownVehicles++;
    }

    if (numberOfShownVehicles == 0)
    {
        printf("Nenhum veículo encontrado\n");
        return pass;
    }

    return success;
}
