#include<stdio.h>

typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} * ABin;

ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc (sizeof(struct nodo));
    if (a!=NULL) {  
        a->valor = r; a->esq = e; a->dir = d;
    }
    return a;
}

int max(int a, int b){
    if (a>= b) return b;
    else return a;
}

int altura (ABin a){
    if (a == NULL) return 0;
    else return (1+max(altura(a->esq), altura(a->dir)));
}

int nFolhas (ABin a){
    if(a == NULL) return 0;
    else if(a-> dir == NULL && a-> esq == NULL) return 1;
    else return (nfolhas(a->esq) + nfolhas(a->dir));
}

ABin maisEsquerda (ABin a){
    if(a == NULL) return 0;
    else if(a->esq == NULL && a -> dir == NULL) return a;
    else return (maisEsquerda(a->esq));
}

void imprimeNivel (ABin a, int l){
    int acc=0;
    if(altura(a)<l-1) printf("Altura da árvore menor que o nível");
    if(acc<l){

    }
}

int procuraE (ABin a, int x){
    if(a== NULL) return 0;
    if(a->valor == x) return 1;
    if(a-> valor != x && a->esq == NULL && a-> dir == NULL) return 0;
    else return (procuraE(a->esq,x) || procuraE(a->dir, x));
}


struct nodo *procura (ABin a, int x){
    if(x == a->valor || a == NULL) return a;
    if(x!=a-> valor && a->dir == NULL && a-> esq == NULL) return NULL;
    if(x>a->valor) return procura(a->dir,x);
    if(x<a->valor) return procura(a->esq,x);
    
    
}

struct nodo *procura2 (ABin a, int x){
    wgile(a !=NULL && a->valor != x){
        if(a-> valor > x) a = a->esq;
        else a = a -> dir;
    }
    return a;
    
}

int nivel (ABin a, int x){
    if(x!=a-> valor && a->dir == NULL && a-> esq == NULL) return -1;
    if(x> a->valor) return (1+nivel(a->dir,x));
    if(x> a->valor) return (1+nivel(a->dir,x));
}

int nivel2 (ABin a, int x){
    int contador=0;
    while(a!=NULL &&& a->valor != x){
        
    }

    if(a==NULL) return -1;

    return contador;
}