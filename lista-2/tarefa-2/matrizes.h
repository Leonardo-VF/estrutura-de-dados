#ifndef matrizes
#define matrizes

// tad matrix

typedef struct {
    int linhas;
    int colunas;
    float * data;

} matrix;

matrix * criar(int linhas, int colunas);
int deletar(matrix * mat);
matrix * ler(matrix * mat);
matrix * escrever(matrix * mat);
matrix * soma(matrix * a, matrix * b);
matrix * subt(matrix * a, matrix * b);
matrix * mult(matrix * a, matrix * b);
matrix * elev(matrix * a, int n);

#endif