#include <stdio.h>
#include <stdlib.h>
#include "matrizes.h"

//funçao para pegar facilmente um elemento da matriz
#define elemento(mat, linha, coluna) \
    mat->data[(linha) * mat->linhas + (coluna)]


// funçao para criar uma matriz vazia dada suas dimensoes
matrix * criar(int linhas, int colunas) {
    matrix * mat = (matrix *) malloc(sizeof(matrix));

    mat->linhas = linhas;
    mat->colunas = colunas;

    mat->data = (float *) malloc(linhas*colunas*sizeof(float));

    int i;
    for (i = 0; i < linhas*colunas; i++)
        mat->data[i] = 0.0;

  return mat;
}

//limpa a memoria alocada para as matrizes

int deletar(matrix * mat) {
    free(mat->data);
    free(mat);
    return 0;
}

// lê do terminal todos os elementos da matriz em ordem
// a ordem sendo linha por linha, ou seja:
// 1 2 3  
// 4 5 6

matrix * ler(matrix * mat) {
    float temp;

    for (int i = 0; i < mat->colunas * mat->linhas; i++){
        scanf("%f", &temp);
        mat->data[i] = temp;
  }
}
  
//printa a matriz no terminal
matrix * escrever(matrix * mat){
    int linhas, colunas;
    for (linhas = 0; linhas < mat->linhas; linhas++){
        for (colunas = 0; colunas < mat->colunas; colunas++){
            printf("% f", elemento(mat, linhas, colunas));
    }
    printf("\n");
  }
  return 0;
}

//soma duas matrizes
matrix * soma(matrix * a, matrix * b){
    matrix *c;

    c = criar(a->linhas, a->colunas);

    for(int i = 0; i < a->linhas*a->colunas; i++)
        c->data[i]=a->data[i]+b->data[i];
    return c;
}

//subtrai as duas matrizes (mesmo codigo da soma porem com um -)
matrix * subt(matrix * a, matrix * b){
    matrix *c;

    c = criar(a->linhas, a->colunas);
    for(int i = 0; i < a->linhas*a->colunas; i++)
        c->data[i] = a->data[i] - b->data[i];
    return c;

}

//multiplica as matrizes
matrix * mult(matrix * a, matrix * b){
    matrix *c;
    c=criar(a->linhas,b->colunas);
    for(int li=0; li<a->linhas; li++){
        for(int co=0; co<b->colunas; co++){
            for(int k=0; k<a->colunas; k++){
                elemento(c, li, co) += elemento(a, li, k)*elemento(b, k, co);
            }
        }
    }
    return c;
}

// eleva uma matrix a N
// ou seja, a funçao mult() faz C = AxB
// e essa faz C^n 

matrix * elev(matrix * a, int n){
    matrix *sup, *res;
    sup = criar(a->linhas, a->linhas);
    res = criar(a->linhas, a->linhas);
    for(int k = 0; k<a->linhas;k++)
        elemento(sup, k, k)=1;
    for(int i = 0; i<n; i++){
        res = mult(sup, a);
        for(int j = 0; j< a->linhas * a->linhas; j++)
        sup->data[j]=res->data[j];
    }
    deletar(sup);
    return res;
}