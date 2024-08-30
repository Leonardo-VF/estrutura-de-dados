#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


bool validacao(int lin_a, int col_a, int col_b, int lin_b);
void multmat(float a[][3], float b[][3], int c, int lin, int col);

int main (int argc, char *argv[]){
    int lin_a, col_a, lin_b, col_b, i;
    //número de interações
    int n = 2;
    //definição das matrizes
    float matz_a[][3] ={{2,1,5},
                        {1,4,2},
                        {1,9,7}};
    float matz_b[][3] ={{1,1,1},
                        {1,1,1},
                        {1,1,1}};
    //tamanho das matrizes
    lin_a = 3;
    col_a = 3;
    lin_b = 3;
    col_b = 3;
    
    if (validacao(lin_a, col_a, col_b, lin_b)){
        multmat(matz_a, matz_b, n, lin_a, col_a);
    } else{
        printf("Elas não podem ser multiplicadas");
    }    
}

bool validacao(int lin_a, int col_a, int col_b, int lin_b){
    //retorna a condição de multiplicação
    return (lin_a == col_b && col_a == lin_b);
}

void multmat(float a[][3], float b[][3], int c, int lin, int col){
    float *mat = (float *)malloc(lin * lin * sizeof(int));
    float *matz_aux_1 = (float *)malloc(lin * lin * sizeof(int));
    float *matz_aux_2 = (float *)malloc(lin * lin * sizeof(int));
    
    //multiplica as duas matrizes
    for(int i = 0; i < lin;i++){
        for(int j = 0; j < lin;j++){
            for(int k = 0; k < col;k++){
                mat[i*lin+j] += a[i][k]*b[k][j];
            }
        }
    }
    //copia a matriz para um auxiliar
    for(int l = 0; l < lin * lin; l++){
        matz_aux_1[l] = mat[l];
    }
    //faz a multiplicação n vezes
    for(int p = 1; p < c; p++){
        for(int i = 0; i < lin; i++){
            for(int j = 0; j < lin; j++){
                for(int k = 0; k < col; k++){
                    matz_aux_2[i*lin+j] += matz_aux_1[i*lin+k] * mat[k*lin+j];
                }
            }
        }
        for(int l=0; l<lin * lin; l++){
            matz_aux_1[l]=matz_aux_2[l];
            matz_aux_2[l]=0;
        }
    }
    //imprime a resposta
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < lin; j++){
            printf("%.2f ", matz_aux_1[i*lin+j]);
            
        }
        printf("\n");
    }
    
    free(mat);
    free(matz_aux_1);
    free(matz_aux_2);
}