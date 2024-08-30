#include <stdlib.h>
#include <stdio.h>

//declaração das funções
float media(float vet[], int num);
void ler_notas(float vet[], int num);


int main (int argc, char *argv[]){
    int num_notas, i, teste;
    float *notas;
    char resp;

    //informa a quantidade de notas
    printf("Insira a quantidade de notas:\n");
    scanf("%d", &num_notas);

    //alocação de memória
    notas = (float *)(malloc(num_notas * sizeof(float)));

    printf("Insira as notas:\n");

    //guarda as notas
    for (i = 0; i < num_notas; i++){
        scanf("%f", &notas[i]);
    }

    //interface de escolha do usuário
    printf("\nDigite\n");
    printf("1. Média das notas\n2. Mostrar as notas\n");
    //foi necessário colocar o num_notas em outra variael para execução da função
    teste = num_notas;
    scanf("%d", &resp);

    

    if (resp == 1){
        printf("A média das notas foi: %.2f\n", media(notas, teste));
    } else if (resp == 2){
        ler_notas(notas, teste);
    }

    free(notas);

    return(0);
}

float media(float vet[], int num){
    float sum = 0.0;
    int j;

    //calculo da média
    for (j = 0; j < num; j++){
        sum += vet[j];
    }

    return (sum/num);
}

void ler_notas(float vet[], int num){
    int j;

    //printa nota por nota no terminal
    for (j = 0; j < num; j++){
        printf("nota %i = %.2f\n", j+1, vet[j]);
    }
}