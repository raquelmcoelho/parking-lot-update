#ifndef UNTITLED_WORKER_H
#define UNTITLED_WORKER_H
#include "../util/utils.h"


worker createWorker(char* code, char* name, char* siape, char* cpf, char* birthday, char *rg, char *address, char *wage, type type);
bool createWorkerUI();
bool updateWorkerUI();
bool deleteWorkerUI();
bool readOneWorkerUI();





// DEPRACATED

// // Functions for Workers
// // - inserir novo servidor --
// bool insertNewServer();
// // - alterar um servidor existente —
// bool alterServer(int position);
// // - excluir um servidor —
// void deleteServer(int position);
// // - mostrar/imprimir dados de um servidor com base no código –
// void read();
// // - mostrar/imprimir todos os servidores -
// void readAll();
// // - mostrar/imprimir todos os servidores em ordem alfabética pelo nome -
// void readAllOrderByName();
// // - mostrar/imprimir todos os professores em ordem alfabética pelo nome -
// void teacherOrderByName();
// // - mostrar/imprimir todos os técnicos administrativos em ordem alfabética pelo nome -
// void technicianOrderByName();



// // Auxiliares
// // - checar se existe codigo, cpf, siape e retornar id da position-
// int checkExists(char value[], int columnNumber);
// // - checar campos obrigatórios e se estão preenchidas corretamente-
// // - as variáveis com "*" não podem estar vazios ou em branco para um funcionário.
// bool checkItsComplete(int data);
// // - print at position -
// void printAtPosition(int position);
// // Facade to initialize columns with null value
// void initializeWorkerColumns();
// // See all database
// void seeDatabase();
#endif //UNTITLED_WORKER_H
