#include<stdio.h>

typedef struct LInt_nodo {
    int valor;
    struct LInt_nodo *prox;
} *LInt;

typedef struct ABin_nodo {
    int valor;
    struct ABin_nodo *pai, *esq, *dir;
} *ABin;

//----------1----------
int paresImpares (int v[], int N){
    if(N<=0) return 0;
    int acc=0;

    for(int i=0;i<N;i++){
        if(v[i]%2 == 0){
            acc++;
            continue;
        }
        else{
            if(i == N-1) break;
            for(int j=i+1;j<N;j++){
                if(v[j]%2 == 0){
                    int aux = v[i];
                    v[i] = v[j];
                    v[j] = v[i];
                    acc++;
                }

            }  
        }
    }

    return acc;
}

//----------2---------
void merge (LInt *r, LInt a, LInt b){
    if(!a) *r = b;
    if(!b) *r = a;

    if(a->valor<=b->valor){
        *r = a;
        a = a->prox;
        merge(&(*r)->prox,a,b);
    }
    else{
        *r = b;
        b = b->prox;
        merge(&(*r)->prox,a,b);
    }
}

//----------3---------
void shiftesq (int N, int v[]){
    int aux =v[0];

    for(int i=1;i<N;i++){
        v[i-1] = v[i];
    }
    v[N-1]=aux;
}

void latino (int N, int m[N][N]){
    int v[N];
    for(int a=1;a<=N;v[a-1]=a,a++);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            m[i][j] = v[j];
        }
        shiftesq(N,v);
    }
}

//----------4---------
ABin next(ABin a){
    
    ABin inicio = a;
    if(a == NULL) return;

    if(a->dir == NULL){
        while(a->pai->valor< a->valor){
            if(a->pai == NULL) return NULL;
            a = a->pai;
        }
        if(a->pai->valor > a->valor) return a->pai;
    }
    
    if(a->dir != NULL){
        a = a->dir;

        while(a->esq != NULL){
            a = a->esq;
        }
        return a;
    }

}

