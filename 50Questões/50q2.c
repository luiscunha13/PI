#include<stdio.h>

typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;

typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} *ABin;


//-----1-------------
int length (LInt l){
    if(l == NULL) return 0;
    else return (1+length(l->prox));
}

//-----2-------------
void freeL (LInt l){
    while(l != NULL){
        LInt aux = l;
        l = l->prox;
        free(aux);
    }
}

//-----3-------------
void imprimeL (LInt l){
    while(l != NULL){
        printf("%d\n", l->valor);
        l = l->prox;
    }
}

//-----4-------------
LInt reverseL (LInt l){
    LInt atual = l;
    LInt ant = NULL;
    LInt prox = NULL;

    while (atual != NULL){
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;
    }

    return ant;

}

//-----5-------------
int insertOrd (LInt *l, int n){
    LInt new = malloc (sizeof(struct lligada));
    new->valor = n;
    new->prox = NULL;
    LInt anterior = NULL;

    for(;*l != NULL && (*l)->valor <n; anterior = (*l), l = &((*l)->prox));

    if(anterior != NULL){
        new->prox=(*l);
        anterior->prox = new;
    }
    else{
        new->prox=(*l);
        *l=new;
    }

}

//-----6-------------
int removeOneOrd(LInt *l, int n){
    LInt atual = *l, prev = NULL;
    
    while (atual != NULL && atual->valor != n){
        prev = atual;
        atual = atual->prox;
    }

    if(atual == NULL) return 1;

    if(prev == NULL) *l = atual->prox;
    else prev->prox = atual->prox;
    
    return 0;

}

//-----7-------------
void merge (LInt *r, LInt a, LInt b){
    if(a == NULL){
        *r = b;
    }
    else if(b == NULL){
        *r = a;
    }
    else if(a->valor <= b->valor){
        *r = a;
        a = a->prox;
        merge(&(*r)->prox, a, b);
    }
    else{
        *r = b;
        b = b->prox;
        merge(&(*r)->prox, a, b);
    }


}

//-----8-------------
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    if(l == NULL) return;

    if(l->valor<x){
        (*mx) = l;
        (*Mx) = NULL;
        splitQS(l->prox, x, &((*mx)->prox), Mx);
    }
    else{
        (*mx) = NULL;
        (*Mx) = l;
        splitQS(l->prox, x, mx, &((*Mx)->prox));
    }
}

//-----9-------------                  ??
LInt parteAmeio (LInt *l){
    LInt nova = malloc(sizeof(struct lligada));
    
    if(nova == NULL) return NULL;
    
    nova = *l;
    LInt atual = *l;

    int tamanho = 0;

    while(atual != NULL) {
        tamanho++;
        atual = atual->prox;
    }

    if(tamanho == 1)
        return NULL;
    
    atual = *l;

    for(int i = 0; i < tamanho/2 - 1; i++){
        atual = atual->prox;
    }

    *l = atual->prox;
    atual->prox = NULL;

    return nova;

}

//-----10------------
int removeAll (LInt *l, int x){
    LInt atual = *l;
    LInt ant = NULL;
    int cont = 0;

    while(atual != NULL){
        if(atual->valor == x){
            cont++;

            if(ant == NULL){
                *l = atual->prox;
            }
            else{
                ant->prox = atual->prox;
            }
        }
        else{
            ant = atual;
        }
        
        atual = atual->prox;
    }

    return cont;

}

//-----11------------                             ??
int removeDups (LInt *l){
    int acc=0;

    for(;*l;l = &((*l)->prox)){
        LInt ant = (*l), aux = (*l)->prox;
        for(;aux;aux = ant->prox){
            if((*l)->valor == aux->valor){
                ant->valor = aux->prox;
                acc++;
            }
            else{
                ant = aux;
            }
        }
    }
    return acc;
}

//-----12------------                          ??
int removeMaiorL (LInt *l){
    int maior = (*l)->valor;
    LInt ant = NULL;
    LInt antMax = NULL;
    LInt aux = (*l);
    LInt maxaux = (*l);

    while(aux != NULL){
        if(aux->valor > maior){
            maxaux = aux;
            antMax = ant;
            maior = aux -> valor;
        }

        ant = aux;
        aux = aux -> prox;
    }

    if(antMax == NULL) (*l) = (*l)->prox;
    else antMax->prox = maxaux->prox;

    return maior;

}

//-----13------------
void init (LInt *l){
    LInt aux = (*l);
    LInt ant = NULL;

    if(aux == NULL) return;

    while(aux->prox != NULL){
        ant = aux;
        aux = aux->prox;
    }

    if(ant == NULL) aux = NULL;
    else ant->prox = NULL;

    free(aux);

}

//-----14------------
void appendL (LInt *l, int x){
    LInt novo = malloc(sizeof(struct lligada));
    LInt aux = (*l);

    if(novo == NULL) return;

    novo->valor = x;
    novo->prox = NULL;

    if((*l) == NULL){
        (*l) = novo;
        return;
    }


    while(aux -> prox != NULL){
        aux = aux->prox;
    }

    aux->prox = novo;
}

//-----15------------
void concatL (LInt *a, LInt b){
    
    if((*a) == NULL) (*a) = b;

    else{
        concatL(&((*a)->prox), b);
    }
}

//-----16------------
LInt cloneL (LInt l){
    if(l == NULL) return NULL;

    LInt novo = malloc(sizeof(struct lligada));

    if(novo==NULL) return NULL;

    novo->valor = l->valor;
    novo->prox = clone(l->prox);

    return novo;
}

//-----17------------
LInt cloneRev (LInt l){
    LInt lista = NULL;

    while(l != NULL){
        LInt novo = malloc(sizeof(struct lligada));

        if(novo == NULL) return NULL;

        novo->valor = l->valor;
        novo->prox = lista;
        lista = novo;

        l = l->prox;
    }
}

//-----18------------
int maximo (LInt l){
    int max = l->valor;

    while(l != NULL){
        if(l->valor > max) max = l->valor;

        l = l->prox;
    }

    return max;
}

//-----19------------
int take (int n, LInt *l){
    LInt aux = (*l), ant = NULL;
    int comp = 0;

    while(l!=NULL && n>0){
        ant = aux;
        aux = aux->prox;
        comp++;
        n--;
    }

    if(ant == NULL) return comp;

    LInt temp;
    temp->prox = NULL;

    while(aux !=NULL){
        temp = aux;
        aux = aux->prox;
        free(temp);
    }

    return comp;
}

//-----20------------
int drop (int n, LInt *l){
    LInt aux;
    int acc;

    while((*l) != NULL && n>0){
        aux = (*l);
        (*l) = (*l)->prox;
        free(aux);
        n--;
        acc++;
    }

    return acc;
}

//-----21------------
LInt Nforward (LInt l, int N){
    for(int i=0;i<N;i++){
        l = l->prox;
    }

    return l;
}

//-----22------------
int listToArray (LInt l, int v[], int N){
    int acc=0;
    
    if(N==0) return NULL;

    while(N>0 && l != NULL){
        v[acc] = l->valor;
        l = l->prox;
        N--;
        acc++;
    }

    return acc;
}

//-----23------------
LInt arrayToList (int v[], int N){

    if(N==0) return NULL;

    LInt l = malloc(sizeof(struct lligada));
    
    if(l == NULL) return NULL;

    l->valor = (*v);
    l->prox = arrayToList(v+1,N-1);

    return l;
}

//-----24------------                  ??
LInt somasAcL (LInt l){
    int soma=0;

    LInt lista = NULL, aux = NULL;

    while(l != NULL){
        soma += l->valor;

        LInt novo = malloc(sizeof(struct lligada));

        if(novo == NULL) return;

        novo->valor = soma;
        novo->prox = NULL;

        if(lista == NULL) lista = aux = novo;
        else aux = aux->prox = novo;

    }

    return lista;

} 

//-----25------------
void remreps (LInt l){

    while(l != NULL){

        while(l->prox != NULL){
            if(l->prox->valor == l->valor){
                LInt aux = l->prox;
                l->prox = aux->prox;
                free(aux);
            }
            else l = l->prox;
        }
    }
}

//-----26------------
LInt rotateL (LInt l){
    if(l == NULL || l->prox == NULL) return l;

    LInt fst = l;
    l = l->prox;
    fst->prox = NULL;

    LInt aux = l;

    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox =fst;

    return l;
}

//-----27------------                            ??
LInt parte (LInt l){

    if(l == NULL || l->prox == NULL) return NULL;

    LInt novo = l->prox;
    l->prox = l->prox->prox;
    novo->prox = parte(l->prox);
}

//-----28------------
int altura (ABin l){
    
    if(l == NULL) return 0;

    int alturae = altura(l->esq);
    int alturad = altura(l->dir);
    
    return 1 + (alturae >= alturad ? alturae : alturad);
}

//-----29------------
ABin cloneAB (ABin l){
    if(l == NULL) return NULL;

    ABin clone = malloc(sizeof(struct nodo));
    clone->valor = l->valor;
    clone->esq = cloneAB(l->esq);
    clone->dir = cloneAB(l->dir);

    return clone;

}

//-----30------------
void mirror (ABin *l){
    if((*l) == NULL) return;

    ABin *aux = (*l)->esq;
    (*l)->esq = (*l)->dir;
    (*l)->dir = aux;

    mirror(&((*l)->esq));
    mirror(&((*l)->dir));
} 

//-----31------------
void inorderaux (ABin l, LInt *list){
    LInt aux;

    if(l != NULL){
        inorderaux(l->esq, list);

        aux = malloc(sizeof(struct lligada));
        aux->valor = l->valor;
        aux->prox = *list;

        *list = aux;

        inorderaux(l->dir, list);
    }

   
}

void inorder (ABin l, LInt *list){
    *list = NULL;
    inorderaux(l, list);
   
}

//-----32------------
void preorderaux (ABin l, LInt *list){
    LInt aux;

    if(l != NULL){
        preorderaux(l->esq, list);
        preorderaux(l->dir, list);

        aux = malloc(sizeof(struct lligada));
        aux->valor = l->valor;
        aux->prox = *list;

        *list = aux;
    } 
}

void preorder (ABin l, LInt *list){
    *list = NULL;
    preorderaux(l, list);
   
}

//-----33------------
void postorderaux (ABin l, LInt *list){
    LInt aux;

    if(l != NULL){
        

        aux = malloc(sizeof(struct lligada));
        aux->valor = l->valor;
        aux->prox = *list;

        *list = aux;

        postorderaux(l->esq, list);
        postorderaux(l->dir, list);
    } 
}

void postorder (ABin l, LInt *list){
    *list = NULL;
    postorderaux(l, list);
   
}

//-----34------------
int depth (ABin a, int x){
    if(a == NULL) return -1;

    if(a->valor == x) return 1;

    int esq = depth (a->esq, x);
    int dir = depth (a->dir, x);

    if(esq == -1 && dir == -1) return -1;
    if(esq == -1) return 1 + dir;
    if(dir == -1) return 1 + esq;
    return esq < dir ? 1+esq : 1+dir;

}

//-----35------------
int freeAB(ABin a){
    int acc;
    ABin aux;

    if(a != NULL){
        acc= 1+ freeAB(a->dir) + freeAB(a->esq);
        free(a);
    }

    return acc;

}

//-----36------------
int pruneAB (ABin *a, int l){
    int acc;

    if((*a) == NULL) return 0;

    if(l == 0){
        acc = 1 + pruneAB(&((*a)->esq),0) + pruneAB(&((*a)->dir),0);
        free(*a);
        (*a) = NULL;
    }
    else acc = pruneAB(&((*a)->esq),l-1) + pruneAB(&((*a)->dir),l-1);

    return acc;
}

//-----37------------
int iguaisAB (ABin a, ABin b){
    if((a == NULL && b != NULL) ||(a != NULL && b == NULL)) return 0;
    if((a == b) ||(a != NULL && b != NULL)) return 1;
    return a->valor == b->valor && iguaisAB(a->esq,b->esq) && iguaisAB(a->dir,b->dir);
}

//-----38------------
LInt concat (LInt a, LInt b){
    if(a == NULL) return b;
    if(b == NULL) return a;
    LInt aux = a;
    while(aux->prox != NULL) aux = aux->prox;
    aux->prox = b;
    return a;
}


LInt nivelL (ABin a, int n){
    if(a == NULL || n<1) return NULL;
    if(a == 1){
        LInt novo = malloc(sizeof(struct lligada));
        novo->valor = a->valor;
        novo->prox = NULL;
    }
    else concat(nivelL(a->esq,n-1), nivelL(a->dir,n-1));
}

//-----39------------
int nivelV (ABin a, int n, int v[]){
    if(a == NULL || n<1) return 0;
    if(n==1){
        *v = a->valor;
        return 1;
    }
    else{
        int e = nivelV(a->esq,n-1, v);
        int d = nivelV(a->dir,n-1,v+e);
        return e+d;
    }
}

//-----40------------
int dumpAbin (ABin a, int v[], int N){
    int e;
    if(a != NULL || N>0){
        e = dumpAbin(a->esq,v,N);
        if(e<N){
            v[e] = a->valor;
            return 1+e+dumpAbin(a->dir,v+e+1,N-e-1);
        }
        else return N;
    }
    else return 0;

}

//-----41------------
ABin somasAcA (ABin a){

    if(a == NULL) return NULL;

    ABin novo = malloc(sizeof(struct nodo));
    novo->esq = somasAcA(a->esq);
    novo->dir = somasAcA(a->dir);
    novo->valor = a->valor+ (novo->esq ? novo->esq->valor : 0) + (novo->dir ? novo->dir->valor : 0);

    return novo;
}

//-----42------------
int contaFolhas (ABin a){
    if(a == NULL) return 0;
    if(a->esq == NULL && a->dir == NULL) return 1;
    return contaFolhas(a->esq)+contaFolhas(a->dir);
}

//-----43------------
ABin cloneMirror (ABin a){
    if(a == NULL) return NULL;

    ABin clone = malloc(sizeof(struct nodo));
    clone->valor = a->valor;
    clone->esq = cloneAB(a->dir);
    clone->dir = cloneAB(a->esq);

    return clone;
}

//-----44------------
int addOrd (ABin *a, int x){
    while((*a) != NULL){
        if((*a)->valor == x) return 1;
        if((*a)->valor > x) a = &((*a)->esq);
        else a = &((*a)->dir);
    }

    ABin novo = malloc(sizeof(struct nodo));
    novo->valor = x;
    novo->esq = novo->dir = NULL;
    (*a) = novo;
    return 0;
}

//-----45------------
int lookupAB (ABin a, int x){
    while(a != NULL){
        if (a->valor == x) return 1;
        if(a->valor > x) a = a->esq;
        else a = a->dir;
    }
    return 0;

}

//-----46------------
int depthOrd (ABin a, int x){
    int nivel=1;
    while(a != NULL){
        if (a->valor == x) return nivel;
        if(a->valor > x) a = a->esq;
        else a = a->dir;
        nivel++;
    }
    return -1;
}

//-----47------------
int maiorAB (ABin a){
    while(a->dir != NULL) a = a->dir;
    return a->valor;
}

//-----48------------
void removeMaiorA (ABin *a){
    if(*a == NULL) return;

    else if((*a)->dir == NULL){
        ABin aux = (*a) -> esq;
        free(*a);
        *a = aux;
    }
    else{
        removemaiorA(&((*a)->dir));
    }
}

//-----49------------
int quantosMaiores (ABin a, int x){
    if(a == NULL) return 0;
    if(a->valor <= x) return quantosMaiores(a->dir,x);
    else return 1 + quantosMaiores(a->esq,x) + quantosMaiores(a->dir,x);
}

//-----50------------
void listToBTree (LInt l, ABin *a){
    if(l == NULL) return;

    ABin novo = malloc(sizeof(struct nodo));
    int meio = length(l)/2;
    LInt aux = l, ant;

    for(int i=0;i<meio;i++){
        ant = aux;
        aux = aux->prox;
    }

    novo->valor = aux->valor;
    novo->esq = novo->dir = NULL;

    //não percebi o resto

}

//-----51------------
int deProcura (ABin a){

    
}