//Diogo Macedo de Mello n# 13685725
//Leonardo Vaz Ferreira n# 13862330

#ifndef double_list
#define double_list


//Declaração do nó da fila
typedef struct Node{
    char *data;
    struct Node *next;
    struct Node *prev;
} Node;

//Declaração da fila
typedef struct List{
    Node *init;
    Node *end;
    int size;
} List;

List *create();
void ordenate(List *lista);
int isEmpty(List *lista);
void insert(char *name, int pos, List *lista);
void removenode(int pos, List *lista);
int exist(char *name, List *lista);
void printAll(List *lista);
void printAllRev(List *lista);
void exitprogram(List *lista);


#endif