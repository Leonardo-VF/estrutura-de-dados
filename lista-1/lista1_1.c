#include <stdlib.h>
#include <stdio.h>


void concatenar(char x[], char y[], char z[]);

int main (int argc, char *argv[]){
    char a[100], b[100], c[1];
    int i, j;

    //recebe os inputs do usuário
    printf("Insira a primeira string: \n");
    scanf("%s", &a);

    printf("Insira a segunda string: \n");
    scanf("%s", &b);

    printf("Insira o caracter de concatenação: \n");
    scanf("%s", &c);

    concatenar(a, b, c);

    return(0);
}

void concatenar(char x[], char y[], char z[]){
    char *p1, *p2; 
    int i;
    char cont[201];

    i = 0;
    p1 = x;
    p2 = y;
    
    //adiciona as letras da primeira palavra a nova palavra (cont) 
    while (*p1){
        cont[i] = *p1;
        *p1++;
        i++;
    }

    //adiciona o conector a nova palavra (cont)
    cont[i] = z[0];
    i++;

    //adiciona as letras da segunda palavra a nova palavra (cont)
    while (*p2){
        cont[i] = *p2;
        *p2++;
        i++;
    }

    //finaliza a nova palavra (cont)
    cont[i] = '\0';

    printf("%s \n", cont);
}
