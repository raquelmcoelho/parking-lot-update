#ifndef VEHICLE_H
#define VEHICLE_H
#endif //VEHICLE_H

#ifndef UTILS_H
#include "../util/utils.h"
#endif


// struct vehicle


bool _verifyWorkerExistsOnDatabase(int code);
bool _verifyDescriptionExistisOnDatabase(char *description);


// pedir campos da struct
// checar uniquidade do campo inserido
// iterar arquivo e ve se há espaço vazio
// se não existir
//     append struct no file
// se existir
//     sobrescreve naquela posicao livre

// create a new vehicle
void createVehicle();

// pegar struct por codigo
// se nao existir 
//     retorna false
// printa struct
// retorna true

// read vehicle of certain position
void showVehicleByCode();



// pegar struct por codigo
// se nao existir 
//     retorna false
// setar flag ocupada pra 0
// printa struct
// sobrescreve struct alterada no arquivo na posicao achada
// retorna true
void deleteVehicle();


// se não existir registro
//     avisa na tela
// itera arquivo inteiro
// pega struct na posicao
// printa struct
// retorna true;

// read all vehicles
void readAllVehicles();

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
void updateVehicle();

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

void readVehiclesInAlphabeticalOrder(bool ofWorkerMode);
