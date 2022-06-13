#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h> /* Função toupper*/

#include "../util/ui/ui.h"

#include "../util/utils.h"

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

typedef enum status_enum
{
    deleted = 0,
    active = 1
} status;

// struct vehicle

typedef struct struct_vehicle
{
    char licensePlate[255];
    char description[255];
    char brand[255];
    char model[255];
    int workerCode;
    int status : 1;
} VEHICLE;

// read all the vehicles on the file vehicle_database.bin,
// put all of them on a list and return such list
VEHICLE **_getAllvehicles()
{
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

    // get license plate
    getMandatoryStringFieldFromUserInput(licensePlate, "Digite a placa do veículo: ");
    strcpy(vehicle->licensePlate, licensePlate);

    // get description
    getMandatoryStringFieldFromUserInput(description, "Digite a descrição do veículo: ");
    strcpy(vehicle->description, description);

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

void _showVehicle(VEHICLE vehicle)
{
    printf("Placa: %s\n", vehicle.licensePlate);
    printf("Descrição: %s\n", vehicle.description);
    printf("Marca: %s\n", vehicle.brand);
    printf("Modelo: %s\n", vehicle.model);
    printf("Código do Trabalhador: %d\n", vehicle.workerCode);
}

void _insertVehicleIntoDatabase(VEHICLE vehicle)
{
    FILE *fp;
    fp = fopen("vehicle_database.bin", "r+b");
    fseek(fp, 0L, SEEK_END);
    if (fwrite(&vehicle, sizeof(vehicle), 1, fp) != 1)
        printf("Falhou a escrita do registro");
    fclose(fp);
}

int _countStoredStructs()
{
    FILE *fp;
    fp = fopen("vehicle_database.bin", "r+b");
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    fclose(fp);
    return size / sizeof(VEHICLE);
}

void _showVehicleByIndex(int position)
{
    FILE *fp;
    VEHICLE vehicle;
    fp = fopen("vehicle_database.bin", "r+b");
    fseek(fp, position * sizeof(VEHICLE), SEEK_SET);
    fread(&vehicle, sizeof(VEHICLE), 1, fp);
    _showVehicle(vehicle);
    fclose(fp);
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

    fp = fopen("vehicle_database.bin", "r+b");

    printf("Código do veículo a ser apagado: ");
    // scanf("%ld", &n_reg);
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
    fp = fopen("vehicle_database.bin", "rb");
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

    fp = fopen("vehicle_database.bin", "r+b");

    printf("Código do Veículo a ser alterado: ");
    // scanf("%ld", &n_reg);
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
    tuple4 v[_countStoredStructs()];
    FILE *fp;
    int i = 0;
    int workerCode = -1;

    fp = fopen("vehicle_database.bin", "rb");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    if (ofWorkerMode)
    {
        printf("Digite o código do funcionário: ");
        // scanf("%d", &workerCode);
        fflush(stdin);
    }

    for (int i = 0; i < _countStoredStructs(); i++)
    {

        if (fread(&vehicle, sizeof(vehicle), 1, fp) != 1)
            break;

        v[i].index = i;
        stpcpy(v[i].description, vehicle.description);
        v[i].workerCode = vehicle.workerCode;
        v[i].status = vehicle.status;
    }

    // Bubble sort
    for (int i = 0; i < _countStoredStructs(); i++)
    {
        for (int j = 0; j < _countStoredStructs() - 1; j++)
        {

            if (strcmp(v[j].description, v[j + 1].description) > 0)
            {

                tuple4 aux = v[j];

                v[j] = v[j + 1];

                v[j + 1] = aux;
            }
        }
    }

    // For each index in the list, show the i-th vehicle
    for (int i = 0; i < _countStoredStructs(); i++)
    {
        if (v[i].status == deleted || v[i].workerCode != workerCode)
            continue;
        printf("-----------------------------------------------------\n");
        _showVehicleByIndex(v[i].index);
    }
}
