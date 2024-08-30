//Diogo Macedo de Mello n# 13685725
//Leonardo Vaz Ferreira n# 13862330

#include <stdlib.h>
#include <stdio.h>
#include "fila.h"


void menu();

int main(int argc, char *argv[]){
    int resp, num, resp_menu = 0;
    Fila *vec;

    //Menu para entrar no programa
    printf("1. Criar fila\n2. Sair\n");
    scanf("%d", &resp);

    if (resp == 1){
        //Criação da fila em questão
        vec = criar();

        while (resp_menu != 9){
            //Interação do usuário com o menu
            menu();
            scanf("%d", &resp_menu);

            //Resposta do terminal para o usuário
            if (resp_menu == 1){
                printf("\n\nInsira um elemento\n");
                scanf("%d", &num);

                insert(vec, num);
            }
            else if (resp_menu == 2){
                element(vec);
            }
            else if (resp_menu == 3){
                printf("\n\nInsira a posição que deseja deletar\n");
                scanf("%d", &num);

                delet(vec, num);
            }
            else if (resp_menu == 4){
                len(vec);
            }
            else if (resp_menu == 5){
                printf("\n\nInsira o elemento que deseja procurar\n");
                scanf("%d", &num);

                if (search(vec, num)){
                    printf("\n\nO elemento está contido da fila\n");
                } else {
                    printf("\n\nO elemento não está contido na fila\n");
                }                    
            }
            else if (resp_menu == 6){
                inverter(vec);
                printf("\n\nFila invertida com sucesso\n");
            }
            else if (resp_menu == 7){
                printf("\n\nInsira o indicie para retornar\n");
                scanf("%d", &num);
                
                if (ind(vec, num) != -1)
                    printf("\n\nO elemento na posição [%d] é: %d\n", num, ind(vec, num));
            }
            else if (resp_menu == 8){
                print(vec);
            }
            else{
                resp_menu = 9;
                eliminar(vec);
            }
        }  
    }

    return 0;
}

void menu(){
    //Menu de interação
    printf("\n\nOperações\n");
    printf("1. Inserir elemento\n");
    printf("2. Obter elemento\n");
    printf("3. Eliminar elemento\n");
    printf("4. Tamanho atual da fila\n");
    printf("5. Verificar ocorrência\n");
    printf("6. Inverter a fila\n");
    printf("7. Retornar n-ésimo elemento\n");
    printf("8. Imprimir fila\n");
    printf("9. Sair\n");
}