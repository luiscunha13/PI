#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct LInt_nodo {
int valor;
struct LInt_nodo *prox;
} *LInt;

typedef struct ABin_nodo {
int valor;
struct ABin_nodo *esq, *dir;
} *ABin;

//---------1---------
int pesquisa (int a[], int N, int x){
    int inf=0, sup=N-1, meio,r=-1;

    while(inf<=sup && r ==-1){
        meio = (inf+sup)/2;
        if(a[meio] == x) r = meio;
        else if(a[meio]> x) sup = meio-1;
        else inf = meio+1;
    }
    return r;

}

//---------2---------
void roda (LInt *l){
    if(!(*l) || (*l)->prox == NULL) return;

    LInt atual = (*l), ant = NULL;

    while(atual->prox != NULL){
        ant = atual;
        atual = atual->prox;
    }

    ant->prox = NULL;
    atual->prox = (*l);
    (*l) = atual;

}

//---------3---------
int apaga (ABin a, int n){
    if(!a || n<=0) return 0;

    if(n==1){
        free(a);
        return 1;
    }

    int apagados_esq = apaga(a->esq, n - 1);
    n -= apagados_esq;

    if (n == 1) {
        
        free(a->dir);
        a->dir = NULL;
        return 1 + apagados_esq;
    }

    
    int apagados_dir = apaga(a->dir, n - 1);
    n -= apagados_dir;

    if (n <= 0) {
        free(a->esq);
        free(a->dir);
        a->esq = NULL;
        a->dir = NULL;
        return 1 + apagados_esq + apagados_dir;
    }

    return 0;
}

//---------4---------
void checksum (char s[]){
    int num = atoi(s);

    int size = strlen(s);

    int numero[size];
    int aux = num;

    int j = size-1;
    while (aux != 0) {
        numero[j] = aux % 10;
        aux /= 10;
        j--;
    }

    int acc=0, par=1;
    for(int i=size-1;i>0;i--){
        if(par){
            if(2*numero[i]>10){
                acc += ( 1 + 2*numero[i] -10);
            }
            else{
                acc += 2*numero[i];
            }
            par = 0;
        }
        else{
            acc += numero[i];
            par = 1;
        }
    }

    acc = 10 - acc%10;

    s[size+1] = itoa(acc);
    s[size+2] = '\0';

}