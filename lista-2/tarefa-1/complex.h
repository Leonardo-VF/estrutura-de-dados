#ifndef complex
#define complex

typedef struct {
    double real;
    double img;
} Complex;

Complex creat_num (double a, double b);
double value_real(Complex a);
double value_img(Complex a);
Complex sum(Complex a, Complex b);
Complex sub(Complex a, Complex b);
Complex mult(Complex a, Complex b);
Complex division(Complex a, Complex b);
void show_complex (Complex a);

#endif