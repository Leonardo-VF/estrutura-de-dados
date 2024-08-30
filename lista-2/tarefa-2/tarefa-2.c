#include <stdio.h>
#include <stdlib.h>
#include "matrizes.h"

int main(int argc, char argv[]){
    int m1, n1, m2, n2, o, t, j;
    matrix *a, *b, *c, *d;
    j=1;

    // loop em que rodará o programa
    while(j==1){
        
        //inputs da primeira matriz
        printf("\nInsira o numero de linhas e colunas da sua matrix\n");
        scanf("%d %d", &m1, &n1);
        a = criar(m1, n1);
        printf("Insira os elementos da primeira matrix \n");
        ler(a);
        printf("\n-----------------------------\n");
        printf("A matrix inserida foi \n");
        escrever(a);


        // escolha de operaçao
        printf("\nQual operacao deseja fazer? \n");
        printf("1. Adicao\n");
        printf("2. Subtracao\n");
        printf("3. Multiplicacao\n");

        scanf("%d", &o);
        
        // estrutura condicional que faz cada operaçao dependendo da resposta

        if(o==1||o==2){

            // para A+B e A-B, A e B devem ter as mesmas dimensoes
            // ler segunda matriz
            printf("Insira outra matrix %d por %d \n", m1, n1);
            b = criar(m1, n1);
            ler(b);
            printf("\n-----------------------------\n");
            printf("A segunda matrix inserida foi \n");
            escrever(b);
            printf("\n-----------------------------\n");

            // if else para somar ou subtrair
            if(o==1){
                printf("O resultado da soma das matrizes:\n");
                c = soma(a,b);
                escrever(c);
            }
            else{
                printf("O resultado da subtracao das matrizes:\n");
                c = subt(a,b);
                escrever(c);
            }
        }

        // caso seja multiplicacao
        else if (o==3){
            
            //lê o n (antes de ler a segunda matriz
            // pois se 'n' for 1, a matriz nao precisa
            // ser quadrada, mas se nao for precisa)

            int n;
            printf("A qual indice voce quer elevar o resultado?\n");
            scanf("%d", &n);

            if(n==1){

                //pede o numero de colunas da segunda matrix,
                //cria e lê ela

                printf("Qual o numero de colunas da segunda matriz?\n");
                scanf("%d", &n2);
                b = criar(n1,n2);

                printf("Insira a matrix %d por %d \n", n1, n2);
                ler(b);

                printf("\n-----------------------------\n");
                printf("A segunda matrix inserida foi \n");
                escrever(b);
                printf("\n-----------------------------\n");

                //multiplica e printa
                c = mult(a, b);
                printf("O resultado da multiplicacao das matrizes:\n");
                escrever(c);
       
            }
            else{
                
                //aqui ele ja sabe as dimensoes, pois ela é quadrada
                //e igual a matriz A
                //ele cria, le e calcula (AxB)^n
                printf("Insira outra matrix %d por %d \n", m1, n1);
                b = criar(m1, n1);
                ler(b);
                printf("\n-----------------------------\n");
                printf("A segunda matrix inserida foi \n");
                escrever(b);
                printf("\n-----------------------------\n");
                c = mult(a, b);
                d = elev(c,n);
                printf("O resultado da multiplicacao das matrizes:\n");
                escrever(d);
                deletar(d);
            }
        }

//limpa cache
        deletar(a);
        deletar(b);
        deletar(c);
    
//o usuario decide se quer continuar fazendo operações ou sair
    printf("\n1. Fazer outra operacao\n");
    printf("2. Para sair\n");
    scanf("%d", &t);
    if(t==2)
        j++;
    printf("\n-----------------------------\n");
    }
    return 0;
}