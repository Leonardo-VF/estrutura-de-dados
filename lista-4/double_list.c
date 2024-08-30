//Diogo Macedo de Mello n# 13685725
//Leonardo Vaz Ferreira n# 13862330

#include <stdlib.h>
#include <stdio.h>
#include "double_list.h"


List *create(){
        List *vec;

        //Aloca memória para a fila
        vec = (List *)(malloc(sizeof(List)));

        //Inicializa os ponteiros inicial e final para "NULL" e size para 0
        vec->size = 0;
        vec->init = NULL;    
        vec->end = NULL;

    return vec;
}

void ordenate(Fila *fila){
    Node *tempnode, *new_node;
    char *prt_1, *prt_2;

    tempnode = fila->init;
    new_node = fila->init;

    while (tempnode != NULL){
        while (new_node != NULL){
            prt_1 = &tempnode;
            prt_2 = &new_node; 

            while(prt_1 != "\0" || prt_2 != "\0"){
                
            }

            new_node = new_node->next;
        }
        tempnode = tempnode->next;
    }
}

// retorna 1 se estiver vazia
// ou 0 se nao
int isEmpty(List *lista){
    if(lista->size==0)
        return 1;
    else return 0;

}

void insert(char *name, int pos, List *lista){
    //cria um no
    Node *tempnode;
    int size;
    size = lista->size;
    
    tempnode = (Node *)(malloc(sizeof(Node)));
    tempnode->data = name;

    // se a lista esta vazia, adiciona as
    //informaçoes de q o prox e o ant sao null
    //e q o elemento é o inicio e o fim
    if(isEmpty(lista)){
        lista->init = tempnode;
        lista->end = tempnode;
        tempnode->prev = NULL;
        tempnode->next = NULL;
    }

    else {

        // se colocar no comeco
        if(pos==1){
            //atualizacoes da cadeia
            lista->init->prev = tempnode;
            tempnode->next = lista->init;
            lista->init = tempnode;
            tempnode->prev = NULL;
        }
        // se colocar no final
        else if(pos>size){
            //atualizacoes da cadeia
            lista->end->next = tempnode;
            tempnode->prev = lista->end;
            lista->end = tempnode;
            tempnode->next = NULL;
        }
        //se colocar no meio
        else{
            Node *auxnodeprev, *auxnodenext;
            auxnodeprev = lista->init;
            // achar o elemento no qual o novo vai encaixar
            for(int i=2; i<pos; i++){
                auxnodeprev = auxnodeprev->next;
            }
            auxnodenext = auxnodeprev->next;

            //atualizacoes da cadeia
            auxnodeprev->next = tempnode;
            auxnodenext->prev = tempnode;
            tempnode->prev = auxnodeprev;
            tempnode->next = auxnodenext;

        }
    }
    // aumenta o tamanho
    lista->size++;
    return;
}

//remover no
void removenode(int pos, List *lista){

    int size;
    lista->size--;
    size=lista->size;

    //se era o unico elemento, remove
    if (lista->size==0){
        free(lista->init);
        lista->init = NULL;
        lista->end = NULL;
    }


    else{

        Node *auxnode;

        //ser era o ultimo elemento, remove
        if(pos>size){
            auxnode=lista->end;
            auxnode->prev->next = NULL;
            lista->end = auxnode->prev;
            //limpa memoria
            free(auxnode);

        }

        else{
            auxnode = lista->init;

            //remove se era o primeiro
            if(pos==1){
                auxnode->next->prev = NULL;
                lista->init = auxnode->next;
            }
            
            //remove se estava no meio
            else{
                Node *auxnodenext, *auxnodeprev;

                for(int i=2; i<=pos; i++){
                    auxnode = auxnode->next;
                }
                auxnodeprev = auxnode->prev;
                auxnodenext = auxnode->next;
                auxnodenext->prev = auxnode->prev;
                auxnodeprev->next = auxnode->next;
                
            }
            //limpa memoria
            free(auxnode);
        }
    }
    return;
}

//checa existencia de elemento na lista
// retorna 1 = true, 0 = false
int exist(char *name, List *lista){
    Node *aux;
    aux = lista->init;
    //varre a lista
    while(aux){
        if(aux->data==name)
            return 1;
        aux = aux->next;
    }
    return 0;
}

//printa a lista em ordem
void printAll(List *lista){
    Node *aux;
    aux = lista->init;
    //varre a lista, printando em ordem
    while(aux){
        printf("%s\n", aux);
        aux = aux->next;
    }
    return;
}

//printa a lista de tras pra frente
void printAllRev(List *lista){
    Node *aux;
    aux = lista->end;
    //varre a lista de tras pra frente, printando
    while(aux){
        printf("%s\n", aux);
        aux = aux->prev;
    }
    return;
}

//encerra
void exitprogram(List *lista){
    Node *aux;
    aux = lista->init;
    //varre a lista deletando os nos
    while(aux){
    lista->init = aux->next;
    free(aux);
    aux = lista->init;
    }
    //limpa a lista
    free(lista);
}