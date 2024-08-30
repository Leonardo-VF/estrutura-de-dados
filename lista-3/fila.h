//Diogo Macedo de Mello n# 13685725
//Leonardo Vaz Ferreira n# 13862330

#ifndef fila
#define fila


//Declaração do nó da fila
typedef struct Node{
    int data;
    Node *next;
} Node;

//Declaração da fila
typedef struct Fila{
    Node *init;
    Node *end;
    int size;
} Fila;

//Declaração das funções da fila
Fila *criar();
void insert(Fila *vec, int num);
void element(Fila *vec);
void delet(Fila *vec, int num);
void len(Fila *vec);
int search(Fila *vec, int num);
void inverter_aux(Fila *vec);
void inverter(Fila *vec);
int ind(Fila *vec, int num);
void eliminar(Fila *vec);
void print(Fila *vec);

#endif