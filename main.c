#include "worker/worker.c"
#include "vehicle/vehicle.c"



int main(){
    setlocale(LC_ALL, "Portuguese");

    int choice = 0;
    char choiceVessel[4];
    feedback feedback = false;


    do{
        printf("\n\nMENU\n");
        printf("%s  01 -  Adicionar servidor                                           %s\n", cyan,  normal);
        printf("%s  02 -  Alterar servidor                                             %s\n", cyan,  normal);
        printf("%s  03 -  Deletar servidor                                             %s\n", cyan,  normal);
        printf("%s  04 -  Ler servidor                                                 %s\n", cyan,  normal);
        printf("%s  05 -  Ler todos servidores                                         %s\n", cyan,  normal);
        printf("%s  06 -  Ler todos servidores por ordem alfabética                    %s\n", cyan,  normal);
        printf("%s  07 -  Ler todos técnicos admnistrativos por ordem alfabética       %s\n", cyan,  normal);
        printf("%s  08 -  Ler todos professores por ordem alfabética                   %s\n", cyan,  normal);
        printf("%s  09 -  Adicionar veículo                                            %s\n", green, normal);
        printf("%s  10 -  Alterar veículo                                              %s\n", green, normal);
        printf("%s  11 -  Deletar veículo                                              %s\n", green, normal);
        printf("%s  12 -  Ler veículo                                                  %s\n", green, normal);
        printf("%s  13 -  Ler os veículos de um servidor                               %s\n", green, normal);
        printf("%s  14 -  Ler os veículos de um servidor em ordem alfabética           %s\n", green, normal);
        printf("%s 100 -  Sair                                                         %s\n", red,   normal);

        choice = getMandatoryIntegerFieldFromUserInput(choiceVessel, "(obrigatório) Entre com o número da sua opção:  ");

        switch(choice){
            case create_worker:
                feedback = createWorker() ? success : failed;
                break;
            case update_worker:
                feedback = updateWorker() ? success : failed;
                break;
            case delete_worker:
                feedback = deleteWorker() ? success : failed;
                break;
            case read_one_worker:
                feedback = (bool) readOneWorker(false) ? success : failed;
                break;
            case read_workers:
                _showAllWorkers();
                feedback = pass;
                break;
            case read_workers_alphabetically:
                _showAllWorkersAlphabetically(null_type);
                feedback = pass;
                break;
            case read_technicians_alphabetically:
                _showAllWorkersAlphabetically(administrative_technician);
                feedback = pass;
                break;
            case read_teachers_alphabetically:
                _showAllWorkersAlphabetically(teacher);
                feedback = pass;
                break;
            case create_vehicle:
                createVehicle();
                feedback = pass;
                break;
            case update_vehicle:
                updateVehicle();
                feedback = pass;
                break;
            case delete_vehicle:
                deleteVehicle();
                feedback = pass;
                break;
            case read_one_vehicle:
                showVehicleByCode();
                feedback = pass;
                break;
            case read_vehicles_worker:
                readVehiclesInAlphabeticalOrder(1);
                feedback = pass;
                break;
            case read_vehicles_worker_alphabetically:
                readVehiclesInAlphabeticalOrder(1);
                feedback = pass;
                break;
            case read_all_vehicles:
                readVehiclesInAlphabeticalOrder(0);
                feedback = pass;
                break;
            case exit_program:
                // exit
                printf("\n%sAté a próxima ☻♥%s\n", yellow, normal);
                feedback = pass;
                exit(1); 
                break;
            default:
                printf("Entrada inválida\n");
                break;
        }

        fflush(stdin);

        if(feedback == success){
            printf("\n%sA operação foi bem sucedida%s\n\n", green, normal);
        } else if (feedback == failed){
            printf("\n%sA operação não foi concluída%s\n\n", red, normal);
        }

        showBlockingMessage();

    } while (choice != exit_program);
}
