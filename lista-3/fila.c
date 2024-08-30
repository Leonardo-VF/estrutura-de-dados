//Diogo Macedo de Mello n# 13685725
//Leonardo Vaz Ferreira n# 13862330

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila.h"

//Criação da fila
Fila *criar(){
        Fila *vec;

        //Aloca memória para a fila
        vec = (Fila *)(malloc(sizeof(Fila)));

        //Inicializa os ponteiros inicial e final para "NULL" e size para 0
        vec->size = 0;
        vec->init = NULL;    
        vec->end = NULL;
    
    return vec;
}

//Inserção de elementos
void insert(Fila *vec, int num){
    Node *aux_node;

    //Aloca memória para o nó da fila
    aux_node = (Node *)(malloc(sizeof(Node)));

    //Inicializa o ponteiro inicial da fila
    aux_node->data = num;
    aux_node->next = NULL;

    //Desloca os ponteiros da fila
    if (vec->size == 0){
        vec->init = aux_node;
        vec->end = aux_node;
    } else{
        vec->end->next = aux_node;
        vec->end = aux_node;
    }

    //Incrementa +1 no tamanho da fila a cada chamada da função
    vec->size++;
}

//Retorno do primeiro elemento da fila
void element(Fila *vec){
    Node *temp;

    //Verifica a existencia ou não da fila
    if (vec->size == 0){
        printf("\n\nA fila está vaiza\n");
    } else {
        //Retorna o primeiro elemento, desloca o ponteiro inicial e libera memória
        printf("\n\nO primeiro elemento da fila é: %d\n\n", *vec->init);
        temp = vec->init;
        vec->init = vec->init->next;
        vec->size--;
        free(temp);
    }
}

//Deleta um elemento da fila
void delet(Fila *vec, int num){
    Node *new_node = vec->init, *temp;
    int pos = 0;

    //Verifica o tamanho da fila
    if (vec->size == 0){
        printf("\n\nA fila está vazia\n");
    }
    else if (vec->size < num){
        printf("\n\nO índice informado é maior que o último índice\n");
    } 
    else {
            //Primeiramente encontra a posição a ser retirada
            while (pos != num){
            new_node = new_node->next;
            pos++;
        }

        for (int i = pos; i <= vec->size; i++){
            //Armazena a posição que será o final da fila
            if (new_node->next == vec->end){
                temp = new_node;
            }
            //Elimina e desloca os ponteiros seguintes da fila
            if (new_node != vec->end){
                new_node->data = new_node->next->data;
                new_node = new_node->next;
            }
        }
        
        //Libera memória e altera o final da fila 
        vec->end = temp;
        vec->end->next = NULL;
        free(vec->end->next);
        vec->size--;
    }
}

//Retorna o contador do tamanho da fila
void len(Fila *vec){
    printf("\n\nA fila tem %d elementos\n\n", vec->size);
}

//Verifica se o elemento está contido ou não na fila
int search(Fila *vec, int num){
    bool status = false;
    Node *new_node = vec->init;

    //Verifia a existencia da fila
    if (vec->size == 0){
        printf("\n\nA fila está vazia\n");
    } else {
        //Verifica elemento por elemento da fila para encontrar o elemento pedido
        while (new_node != NULL){
            if (new_node->data == num){
                status = true;
            }

            new_node = new_node->next;
        }
    }
    return status;
}

//Função aux para deslocar o ponterio da fila
void inverter_aux(Fila *vec){
    vec->init = vec->init->next;
    vec->size--;
}

//Inverte os elementos da fila
void inverter(Fila *vec){
    Node *new_node = vec->init;
    int aux[vec->size], pos = 0;

    //Armazena os elementos da fila em um vetor e exclui elemento por elemento deixando a memória alocada
    while (new_node != NULL){
            aux[pos] = new_node->data;
            inverter_aux(vec);
            new_node = new_node->next;
            pos++;
        }
        
        //Adiciona elemento por elemento do vetor na ordem invertida na memória já alocada
        while (pos != 0){
            insert(vec, aux[pos-1]);
            pos--;
        } 
}

//Procura um elemento da fila a partir do índice informado 
int ind(Fila *vec, int num){
    Node *new_node = vec->init;
    int count = 0;

    //Verifica a existencia da fila e o índice informado
    if (vec->size == 0){
        printf("\n\nA fila está vazia\n");
        new_node->data = -1;
    }
    else if (vec->size < num){
        printf("\n\nO índice informado é maior que o último índice");
        new_node->data = -1;
    } 
    else{
        //Encontra o elemento da fila a partir do índice
        while (count != num){
        new_node = new_node->next;
        count++;
        }
    }
    
    return new_node->data;
}

//Elimina a fila por completo
void eliminar(Fila *vec){
    Node *new_node = vec->init;
    Node *temp;

    //Desaloca nó por nó da fila
    while (new_node != NULL){
        temp  = new_node;
        new_node = new_node->next;
        free(temp);
    }

    //Desaloca a memória da própria fila
    free(vec);
}

//Printa elemento por elemento no terminal
void print(Fila *vec){
    Node *new_node = vec->init;
    int pos = 0;

    //Verifica a existencia da fila
    if (vec->size == 0){
        printf("\n\nA fila está vazia\n");
    } else{
        printf("\n\n");
        //Printa um por um na tela do usuário
        while (new_node != NULL){
            printf("Elemento da posição [%d]: %d\n", pos, new_node->data);
            new_node = new_node->next;
            pos++;
        }
    }
}