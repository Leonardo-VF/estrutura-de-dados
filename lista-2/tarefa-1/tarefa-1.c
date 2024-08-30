#include <stdio.h>
#include <stdlib.h>
#include "complex.h"


void menu();

int main(int argc, char *argv[]){
    int resp;
    Complex z1, z2;

    resp = 1;

    while (resp == 1){
        printf("1. Realizar uma operação\n");
        printf("2. Sair \n");
        scanf("%i", &resp);

        if (resp == 1){
            printf("Insira os coeficientes do primeiro complexo\n");
            scanf("%lf %lf", &z1.real, &z1.img);

            printf("Insira os coeficientes do segundo complexo\n");
            scanf("%lf %lf", &z2.real, &z2.img);

            menu();

            scanf("%i", &resp);

            if (resp == 1){
                printf("Parte real do primeiro é = %lf\n", value_real(z1));
                printf("Parte real do segundo é = %lf\n", value_real(z2));
                printf("\n\n");
            } 
            
            else if (resp == 2){
                printf("Parte imaginária do primeiro é = %lf\n", value_img(z1));
                printf("Parte imaginária do segundo é = %lf\n", value_img(z2));
                printf("\n\n");
            }
            
            else if (resp == 3){
                show_complex(sum(z1, z2));
            }
            
            else if (resp == 4){
                show_complex(sub(z1, z2));
            }
            
            else if (resp == 5){
                show_complex(mult(z1, z2));
            }

            else {
                show_complex(division(z1, z2));
            }

            resp = 1;
        }
    }
    return(0);
}

void menu(){
    printf("\n\n");
    printf("1. Mostrar parte real\n");
    printf("2. Mostrar parte imaginária\n");
    printf("3. Adição de 2 números complexos\n");
    printf("4. Subtração de 2 números complexos\n");
    printf("5. Multiplicação de 2 números complexos\n");
    printf("6. Divisão de 2 números complexos\n");
    printf("\n\n");
}
