//Diogo Macedo de Mello n# 13685725
//Leonardo Vaz Ferreira n# 13862330

#include <stdlib.h>
#include <stdio.h>
#include "double_list.h"


void menu_1();
void menu_2();

int main(int argc, char *argv[]){
    int resp_1, resp_2 = 0, x;
    char *name;
    List *lista;

    //printa o menu 1 e le o comando
    menu_1();
    scanf("%d", &resp_1);

    if (resp_1 == 1){
        lista = create();
    
        //loop do menu 2
        while (resp_2 != 8){

            menu_2();
            scanf("%d", &resp_2);
            printf("----------------------------------\n");

            // func de adicionar um nome

            if(resp_2 == 1){
                printf("\nInsira um nome\n");

                scanf("%s", &name);
                printf("\nInsira a posicao desejada\n");
                scanf("%d", &x);
                insert(name, x, lista);
            }

            else if (resp_2 == 2){
                printf("\nLista ordenada!\n");
            }

            //func de remover um elemento
            else if (resp_2 ==  3){
                printf("\nInsira o indice do elemento que deseja remover\n");
                scanf("%d", &x);
                removenode(x, lista);
            }

            //buscar nome
            else if (resp_2 == 4){
                printf("\nInsira o nome que deseja procurar\n");
                scanf("%s", &name);
                if(exist(name, lista))
                    printf("O elemento esta na lista\n");
                else printf("O elemento nao esta na lista\n");

            }
            //printa a lista em ordem

            else if (resp_2 == 5){
                printAll(lista);
                printf("\n");
            }

            //printa a lista em ordem reversa
            else if (resp_2 == 6){
                printAllRev(lista);
                printf("\n");
            }

            //diz se a lista esta vazia ou nao
            else if (resp_2 == 7){
                if(isEmpty(lista))
                    printf("A lista esta vazia\n\n");
                else printf("A lista nao esta vazia\n\n");
            }
        }
        exitprogram(lista);
    }
    
    return 0;
}


//estrutura dos menus
void menu_1(){
    printf("1. Criar lista\n2.Sair\n");
}

void menu_2(){
    printf("------------------------------------------\n");
    printf("1. Inserir elemento e a posicao desejada\n");
    printf("2. Ordenar lista\n");
    printf("3. Remover elemento da lista\n");
    printf("4. Verificar existencia\n");
    printf("5. Exibir lista\n");
    printf("6. Exibir lista ordem reversa\n");
    printf("7. Verificar se esta vazia\n");
    printf("8. Sair\n");
}