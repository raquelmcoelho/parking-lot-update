#include "util/utils.h"
#include "worker/worker.h"
#include "vehicle/vehicle.h"


int main(){
    setlocale(LC_ALL, "Portuguese");

    int choice = 0;
    bool success = false;

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
        printf("%s 13- Ler os veículos de um servidor                                        %s\n", green, normal);
        printf("%s 14- Ler os veículos de um servidor em ordem alfabética          %s\n", green, normal);
        printf("%s 100- sair                                                       %s\n", red, normal);
        printf("%s Entre com o número da sua opção:                                %s\n", cyan, normal);
//        printf("%d %d", variavel, variavel2);

        // TODO: getIntFromUser()
        scanf("%d", &choice);

        switch(choice){
            case create_worker:
                printf("você escolheu criar_servidor");
                success = createWorkerUI();
                break;
            case update_worker:
                printf("você escolheu editar_servidor");
                success = false;
                break;
            case delete_worker:
                printf("você escolheu deletar_servidor");
                success = false;
                break;
            case read_one_worker:
                printf("você escolheu ler_um_servidor");
                success = false;
                break;
            case read_workers:
                printf("você escolheu ler_servidores");
                success = false;
                break;
            case read_workers_alphabetically:
                printf("você escolheu ler_servidores_alfabetica");
                success = true;
                break;
            case read_technicians_alphabetically:
                printf("você escolheu ler_tecnicos_admnistrativos_alfabetica");
                success = true;
                break;
            case read_teachers_alphabetically:
                printf("você escolheu ler_professores_alfabetica");
                success = true;
                break;
            case create_vehicle:
                printf("você escolheu criar_veiculo");
                success = true;
                break;
            case update_vehicle:
                printf("você escolheu editar_veiculo");
                success = true;
                break;
            case delete_vehicle:
                printf("você escolheu deletar_veiculo");
                success = true;
                break;
            case read_one_vehicle:
                printf("você escolheu ler_um_veiculo");
                success = true;
                break;
            case read_vehicles_worker:
                printf("você escolheu ler_veiculos_servidor");
                success = true;
                break;
            case read_vehicles_worker_alphabetically:
                printf("você escolheu ler_veiculos_servidor_alfabetica:     ");
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

        if(success){
            printf("\n%sA operação foi bem sucedida%s\n", green, normal);
        } else {
            printf("\n%sA operação não foi concluída%s\n", red, normal);
        }

    } while (choice != exit_program);
}
