#include<stdio.h>

typedef struct LInt_nodo {
    int valor;
    struct LInt_nodo *prox;
} *LInt;

typedef struct nodo {
int valor;
struct nodo *pai, *esq, *dir;
} *ABin;

//---------1---------
int sumhtpo (int n){
    int *v, acc=0;
    
    while (n != 1) {
        v[acc]= n; // põe as parcelas no array
        acc++;
        if (n%2 == 0) n = n/2; else n = 1+(3*n);
    }

    if(acc<99) return -1;  // caso tenha menos de 100 parcelas

    for(int i=0;i<=acc;i++){   // pôe o array por ordem decrescente
        for(int j=i+1;j<=acc;j++){
            if(v[j]<v[i]){
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }

    return v[99]; 

}

//---------2---------
int existe(int *aux, int N, int x){ // função que vê se há um valor num array
    for(int i=0;i<N;i++){
        if(aux[i] == x) return 1;
    }
    return 0;
}

int moda(int v[], int N, int *m){
    int *aux, *modas, acc=0;

    for(int i=0;i<N;i++){    //fazer uma lista com os valores(sem haver repetidos)
        if(acc=0 ||existe(aux,acc,v) == 0){
          aux[acc] = v[i];
          modas[acc] = 0;
          acc++;  
        } 
    }

    for(int j=0;j<N;j++){         //fazer lista com as modas dos valores
        for(int k=0;k<acc;k++){
            if(v[j] == aux[k]) modas[k] +=1;
        }
    }

    int max = modas[0];

    for(int l=0;l<acc;l++){        // ver a maior moda
        if(modas[l]>max) max = modas[l];
    }
    
    for(int m=0,acc=0;m<acc;m++){ // ver se há mais do que um valor com a maior moda
        if(acc>1) return 0;
        if(modas[m] == max) acc++;
    }

    *m = max;
    return *m;
}

//---------3---------
int procura (LInt *l, int x){
    if(!(*l)) return 0;

    LInt atual = (*l),ant = NULL;

    while(atual->valor != x && atual != NULL){
        ant = atual;
        atual = atual->prox;
    }

    if(!atual) return 0;
    if(ant == NULL) return 1;
    else{
        ant->prox = atual->prox;
        atual->prox = (*l);
        (*l) = atual;
        return 1;
    }
}

//---------4---------
int freeAB(ABin a){
    int acc=0;

    if(a!=NULL){
        acc = 1 + freeAB(a->esq) + freeAB(a->dir);
        free(a);
    }

    return acc;
}

//---------5---------
void caminho(ABin a){
    if(a->pai == NULL) return;

    caminho(a->pai);
    if(a->pai->dir->valor == a->valor)
        printf("dir\n");
    else
        printf("esq\n");
}