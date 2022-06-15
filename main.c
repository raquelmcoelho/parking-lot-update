#include "worker/worker.c"
#include "vehicle/vehicle.c"



int main(){
    setlocale(LC_ALL, "Portuguese");

    int choice = 0;
    char choiceVessel[4];
    bool success = false;

    value v;
    v.integer = 3;
    _getWorkerIndexBySearch(field_code, v);

    do{
        printf("\n\nMENU\n");
        printf("%s 1 - Adicionar servidor                                           %s\n", cyan, normal);
        printf("%s 2 - Alterar servidor                                             %s\n", cyan, normal);
        printf("%s 3 - Deletar servidor                                             %s\n", cyan, normal);
        printf("%s 4 - Ler servidor                                                 %s\n", cyan, normal);
        printf("%s 5 - Ler todos servidores                                         %s\n", cyan, normal);
        printf("%s 6 - Ler todos servidores por ordem alfabética                    %s\n", cyan, normal);
        printf("%s 7 - Ler todos professores por ordem alfabética                   %s\n", cyan, normal);
        printf("%s 8 - Ler todos técnicos admnistrativos por ordem alfabética       %s\n", cyan, normal);
        printf("%s 9 - Adicionar veículo                                           %s\n", green, normal);
        printf("%s 10- Alterar veículo                                             %s\n", green, normal);
        printf("%s 11- Deletar veículo                                             %s\n", green, normal);
        printf("%s 12- Ler veículo                                                 %s\n", green, normal);
        printf("%s 13- Ler os veículos de um servidor                              %s\n", green, normal);
        printf("%s 14- Ler os veículos de um servidor em ordem alfabética          %s\n", green, normal);
        printf("%s 100- sair                                                       %s\n", red, normal);

        choice = getMandatoryIntegerFieldFromUserInput(choiceVessel, "Entre com o número da sua opção:  ");

        switch(choice){
            case create_worker:
                success = createWorker();
                break;
            case update_worker:
                success = updateWorker();
                break;
            case delete_worker:
                success = deleteWorker();
                break;
            case read_one_worker:
                success = (bool) readOneWorker(false);
                break;
            case read_workers:
                _showAllWorkers();
                success = true;
                break;
            case read_workers_alphabetically:
                _showAllWorkersAlphabetically(null_type);
                success = true;
                break;
            case read_technicians_alphabetically:
                _showAllWorkersAlphabetically(administrative_technician);
                success = true;
                break;
            case read_teachers_alphabetically:
                _showAllWorkersAlphabetically(teacher);
                success = true;
                break;
            case create_vehicle:
                createVehicle();
                success = true;
                break;
            case update_vehicle:
                updateVehicle();
                success = true;
                break;
            case delete_vehicle:
                deleteVehicle();
                success = true;
                break;
            case read_one_vehicle:
                showVehicleByCode();
                success = true;
                break;
            case read_vehicles_worker:
                readVehiclesInAlphabeticalOrder(1);
                success = true;
                break;
            case read_vehicles_worker_alphabetically:
                readVehiclesInAlphabeticalOrder(1);
                success = true;
                break;
            case read_all_vehicles:
                readVehiclesInAlphabeticalOrder(0);
                success = true;
                break;
            case exit_program:
                // exit
                printf("\n%sAté a próxima ☻♥%s\n", yellow, normal);
                success = true;
                exit(1);
                break;
            default:
                printf("Entrada inválida\n");
                break;
        }

        fflush(stdin);

        if(success){
            printf("\n%sA operação foi bem sucedida%s\n\n", green, normal);
        } else {
            printf("\n%sA operação não foi concluída%s\n\n", red, normal);
        }

        showBlockingMessage();

    } while (choice != exit_program);
}
