#include <stdio.h>
#include "complex.h"


Complex creat_num (double a, double b){
    Complex c;

    c.real = a;
    c.img = b;

    return c;
}

double value_real(Complex a){
    return a.real;
}

double value_img(Complex a){
    return a.img;
}

Complex sum(Complex a, Complex b){
    return creat_num(a.real + b.real, a.img + b.img);
}

Complex sub(Complex a, Complex b){
    return creat_num(a.real - b.real, a.img - b.img);
}

Complex mult(Complex a, Complex b){
    return creat_num((a.real*b.real)-(a.img*b.img), (a.real*b.img)+(a.img*b.real));
}

Complex division(Complex a, Complex b){
    double r, i;

    r = (a.real*b.real + a.img*b.img)/(b.real*b.real + b.img*b.img);
    i = (-a.real*b.img + a.img*b.real)/(b.real*b.real + b.img*b.img);

    return creat_num(r, i);
}

void show_complex (Complex a){
    if (a.img < 0){
        printf("%f %fi\n", a.real, a.img);
    } else {
        printf("%f + %fi\n", a.real, a.img);
    }
    printf("\n\n");
}