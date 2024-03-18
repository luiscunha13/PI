#include<stdio.h>

typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;

LInt newLInt (int x, LInt xs) {
    LInt r = malloc (sizeof(struct slist));
    if (r!=NULL) {
        r->valor = x; r->prox = xs;
    }
    return r;
}

typedef LInt Stack;

typedef struct {
    LInt inicio,fim;
} Queue;



void initStack(Stack *s){
    *s = NULL;
}

int Sisempty (Stack *s){
    return (s==NULL);
}

int push (Stack *s, int x){
    Stack alberto = malloc (sizeof(struct slist));

    if(alberto==NULL) return 1;

    alberto->valor = x;

    alberto->prox= *s;

    *s = alberto;

    return 0;
}

int push2 (Stack *s, int x){
    LInt aux = newInt(x, *s);

    if(aux == NULL) return 1;

    *s = aux;

    return 0;
}

int pop (Stack *s, int *x){
    if(Sisempty(*s)) return 1;

    LInt aux;
    
    *x = (*s)-> valor;

    aux = (*s) -> prox;

    free(*s);

    *s = aux;

    return 0;
}

int top (Stack *s, int *x){
    if(Sisempty(*s)) return 1;

    LInt ant = NULL;

    while((*s)-> prox != NULL){
        ant = s;
        *s = (*s)->prox;  
    } 
    
    *x = (*s)-> valor;

    ant = (*s) -> prox;

    free(*s);

    *s = ant;

    return 0;
}


void intqueue (Queue *q ){
    q->inicio = NULL;
    q->fim = NULL;
}

int QisEmpty(Queue q){
    return(q.inicio==NULL);
}

int enqueue (Queue *q, int x){
    LInt aux = newLInt (x,NULL);

    if(QisEmpty(*q)){
        q->inicio = aux;
        q->fim= aux;
    }
    else{
        q -> fim -> prox = aux;
        q->fim = aux;
    }
    return 0;
}

int dequeue (Queue *q, int *x){
    if(QisEmpty(*q)) return 1;
    *x = q->inicio->valor;

    Queue aux = q -> inicio -> prox;

    free(q->inicio);

    q->inicio = aux;

    if(QisEmpty(*q)) q->fim = NULL;

    return 0;
}

int front (Queue q, int *x){
    if(QisEmpty(q)) return 1;

    *x = (q.inicio)->valor;

    return 0;
}