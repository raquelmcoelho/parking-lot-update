
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

bool _verifyDescriptionExistisOnDatabase(char *description)
{
    bool descriptionExistisOnDatabase = false;
    FILE *file = _getFile(vehicle_filename);;
    if (file != NULL)
    {
        VEHICLE vehicle;
        while (fread(&vehicle, sizeof(VEHICLE), 1, file) == 1)
        {
            if (strcmp(description, vehicle.description) == 0)
            {
                descriptionExistisOnDatabase = true;
                break;
            }
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

    // get license plate
    getMandatoryStringFieldFromUserInput(licensePlate, "Digite a placa do veículo: ");
    strcpy(vehicle->licensePlate, licensePlate);

    do
    {
        // get description
        getMandatoryStringFieldFromUserInput(description, "Digite a descrição do veículo: ");
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
    getMandatoryStringFieldFromUserInput(brand, "Digite a marca do veículo: ");
    strcpy(vehicle->brand, brand);

    // get model
    getMandatoryStringFieldFromUserInput(model, "Digite o modelo do veículo: ");
    strcpy(vehicle->model, model);

    // get worker code
    getMandatoryStringFieldFromUserInput(workerCode, "Digite o código do funcionário: ");
    vehicle->workerCode = atoi(workerCode);

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
void createVehicle()
{

    VEHICLE vehicle;
    // read the vehicle data
    _readVehicle(&vehicle);
    // add the vehicle to the database
    _insertVehicleIntoDatabase(vehicle);
}

// pegar struct por codigo
// se nao existir
//     retorna false
// printa struct
// retorna true

// read vehicle of certain position
void showVehicleByCode()
{
    VEHICLE vehicle;
    FILE *fp;
    int vehicleCode;
    char vehicleCodeVessel[255];
    vehicleCode = getMandatoryIntegerFieldFromUserInput(vehicleCodeVessel, "Digite o código do veículo: ");

    fp = _getFile(vehicle_filename);
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    // fseek to the position of the vehicle
    fseek(fp, vehicleCode * sizeof(VEHICLE), SEEK_SET);

    // read the vehicle
    fread(&vehicle, sizeof(VEHICLE), 1, fp);

    if (vehicle.status != deleted)
    {
        _showVehicle(vehicle);
        showBlockingMessage();
    }
}

// pegar struct por codigo
// se nao existir
//     retorna false
// setar flag ocupada pra 0
// printa struct
// sobrescreve struct alterada no arquivo na posicao achada
// retorna true
void deleteVehicle()
{
    VEHICLE vehicle;
    FILE *fp;
    long int n_reg;
    char resp;

    char vehicleCodeVessel[255];

    fp = _getFile(vehicle_filename);

    printf("Código do veículo a ser apagado: ");
    // scanf("%ld", &n_reg);
    n_reg = getMandatoryIntegerFieldFromUserInput(vehicleCodeVessel, "Digite o código do veículo: ");

    fflush(stdin);

    if (fseek(fp, (n_reg - 1) * sizeof(VEHICLE), SEEK_SET) != 0)
    {
        printf("Registro Inexistente ou Problemas no Posicionamento!!!");
        return;
    }
    if (fread(&vehicle, sizeof(VEHICLE), 1, fp) != 1)
    {
        printf("Problemas na leitura do Registro!!!");
        return;
    }
    if (vehicle.status == deleted)
    {
        printf("O registro já está apagado!!!\n\n");
        return;
    }

    printf("\n\nDados Atuais\n\n");
    _showVehicle(vehicle);

    printf("\n\nApagar o Registro (s/n)???: ");
    resp = getWillFromUserInput();
    fflush(stdin);
    if (toupper(resp) != 'S')
        return;

    vehicle.status = deleted;
    // Recuar um Registro no Arquivo
    fseek(fp, -(long)sizeof(VEHICLE), SEEK_CUR);
    // Reescrever o Registro;
    fwrite(&vehicle, sizeof(VEHICLE), 1, fp);
    fflush(fp); /*Despejar os Dados no Disco Rígido*/
}

// se não existir registro
//     avisa na tela
// itera arquivo inteiro
// pega struct na posicao
// printa struct
// retorna true;

// read all vehicles
void readAllVehicles()
{
    VEHICLE vehicle;
    FILE *fp;
    fp = _getFile(vehicle_filename);
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    while (1)
    {
        if (fread(&vehicle, sizeof(vehicle), 1, fp) != 1)
            break;
        if (vehicle.status == deleted)
            continue;
        printf("-----------------------------------------------------\n");
        _showVehicle(vehicle);
    }
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
void updateVehicle()
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
        return;
    }

    if (fread(&vehicle, sizeof(VEHICLE), 1, fp) != 1)
    {
        printf("Problemas na leitura do Registro!!!");
        return;
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
}

typedef struct ordering_alg_tuple
{
    int index;
    char description[255];
    int workerCode;
    int status : 1;
} tuple4;

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

void readVehiclesInAlphabeticalOrder(bool ofWorkerMode)
{
    VEHICLE vehicle;
    tuple4 v[_countStoredVehicleStructs()];
    FILE *fp;
    int i = 0;
    int workerCode = -1;
    char workerCodeVessel[255];

    fp = _getFile(vehicle_filename);
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    if (ofWorkerMode)
    {
        workerCode = getMandatoryIntegerFieldFromUserInput(workerCodeVessel, "Digite o código do funcionário: ");
        fflush(stdin);
    }

    for (int i = 0; i < _countStoredVehicleStructs(); i++)
    {

        if (fread(&vehicle, sizeof(vehicle), 1, fp) != 1)
            break;

        v[i].index = i;
        strcpy(v[i].description, vehicle.description);
        v[i].workerCode = vehicle.workerCode;
        v[i].status = vehicle.status;
    }

    // Bubble sort
    for (int i = 0; i < _countStoredVehicleStructs(); i++)
    {
        for (int j = 0; j < _countStoredVehicleStructs() - 1; j++)
        {

            if (strcmp(v[j].description, v[j + 1].description) > 0)
            {

                tuple4 aux = v[j];

                v[j] = v[j + 1];

                v[j + 1] = aux;
            }
        }
    }

    int numberOfShownVehicles = 0;

    // For each index in the list, show the i-th vehicle
    for (int i = 0; i < _countStoredVehicleStructs(); i++)
    {
        if (v[i].status == deleted || (ofWorkerMode && v[i].workerCode != workerCode))
            continue;
        printf("-----------------------------------------------------\n");
        printf("Código: %d\n", v[i].index + 1);
        _showVehicleByIndex(v[i].index);
        numberOfShownVehicles++;
    }

    if (numberOfShownVehicles == 0)
    {
        printf("Nenhum veículo encontrado\n");
    }
    showBlockingMessage();
}
