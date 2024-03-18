#include<stdio.h>

typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;

//--------1---------
int length (LInt l){
    if(!l) return 0;
    else return 1 +length(l->prox);
}

//--------2---------
void freeL (LInt l){

     LInt aux;

    while(l != NULL){
        aux = l;
        l = l->prox;
        free(aux);
    }
}

//--------3---------
void imprimeL (LInt l){
    
    while(l!= NULL){
        printf("%d",l->valor);
        l = l->prox;
    }
}

//--------4---------
LInt reverseL (LInt l){
    if(!l) return NULL;

    LInt atual = l, ant = NULL, prox = NULL;

    while(atual != NULL){
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;
    }

    return ant;
}

//--------5---------
void insertOrd (LInt *l, int n){
    LInt novo = malloc(sizeof(struct lligada));

    if(!novo) return;

    novo->valor = n;
    novo->prox = NULL;
  
    LInt ant = NULL,atual = (*l);
    while(atual != NULL &&atual->valor < n){
        ant = atual;
        atual = atual->prox;
    }

    if(!ant){
        novo->prox = (*l);
        (*l) = novo;
    }
    else{
        novo->prox = atual;
        ant->prox = novo;
    }
}

//--------6---------
int removeOneOrd (LInt *l, int n){

    LInt ant = NULL, atual = (*l);

    while(atual != NULL && atual->valor != n){
        ant = atual;
        atual = atual->prox;
    }

    if(!atual) return 1;

    if(ant == NULL){
        *l = atual->prox;
    }
    else{
        ant->prox = atual->prox;
    }
    return 0;

}

//--------7---------
void merge (LInt *r, LInt a, LInt b){
    if(!a) (*r) = b;
    if(!b) (*r) = a;

    if(a->valor <= b->valor){
        (*r) = a;
        a = a->prox;
        merge(&(*r)->prox,a,b);
    }
    else{
        (*r) = b;
        b = b->prox;
        merge(&(*r)->prox,a,b);
    }

}

//--------8---------
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    if(!l) return;

    while(l!= NULL){
        if(l->valor < x){
            (*mx) = l;
            *Mx = NULL;
            l = l->prox;
            splitQS(l,x,&(*mx)->prox,*Mx);
        }
        else{
            (*Mx) = l;
            *mx = NULL;
            l = l->prox;
            splitQS(l,x,*mx,&(*Mx)->prox);
        }
    }

}

//--------9---------
LInt parteAmeio (LInt *l){
    int meio = length(l)/2;

    if(length(l) == 1) return NULL;

    LInt novo = malloc(sizeof(struct lligada));

    if(!novo) return NULL;

    novo = *l;

    LInt atual = (*l);

    for(int i=0;i<meio;i++){
        atual = atual->prox;
    }

    *l = atual->prox;
    atual->prox = NULL;

    return novo;
}

//--------10---------
int removeAll (LInt *l, int n){
    if(!(*l)) return 0;

    LInt atual =(*l), ant = NULL;
    int acc=0;

    while(atual != NULL){
        if(atual->valor == n){
            acc++;
            if(!ant) *l = atual->prox;
            else{
                ant->prox = atual->prox;
            }
        }
        else{
            ant = atual;
        }

        atual = atual->prox;
    }

    return acc;

}

//--------11---------
int removeDups (LInt *l){
    LInt atual = (*l);
    int acc=0;

    if(!atual) return 0;

    while(atual != NULL){
        LInt prev = atual, aux = atual->prox;

        while(aux != NULL){
            if(aux->valor == atual->valor){
               prev->prox = aux->prox;
                acc++; 
            }
            else{
                prev = aux;
            }
        }
    }

    return acc;
}

//--------12---------
int removeMaiorL (LInt *l){
    LInt atual = (*l);
    int max=atual->valor;

    while(atual!=NULL){
        if(atual->valor > max) max = atual->valor;
        atual = atual->prox;
    }

    LInt prev = NULL;

    atual = (*l);

    while(atual->valor != max){
        prev = atual;
        atual = atual->prox;
    }

    if(prev == NULL) (*l) = (*l)->prox;
    else{
        prev->prox = atual->prox;
    }

    return max;
}

//--------13---------
void init (LInt *l){
    LInt atual = (*l),prev = NULL;

    while(atual->prox != NULL){
        prev = atual;
        atual = atual->prox;
    }

    if(prev == NULL) (*l) = NULL;
    else{
        prev->prox = NULL;
    }
    free(atual);
    
}

//--------14---------
void appendL (LInt *l, int n){
    LInt novo = malloc(sizeof(struct lligada));

    if(!novo) return;
    novo->valor = n;
    novo->prox = NULL;

    if(!(*l)){
        (*l) = novo;
        return;
    }

    LInt atual = (*l);

    while(atual->prox != NULL){
        atual = atual->prox;
    }

    atual->prox = novo;
}

//--------15---------
void concatL (LInt *a, LInt b){
    if(!(*a)) *a = b;
    
    LInt atual = *a;

    while(atual->prox != NULL){
        atual = atual->prox;
    }

    atual->prox = b;
}

//--------16---------
LInt cloneL (LInt l){
    if(!l) return NULL;


    LInt novo = malloc(sizeof(struct lligada));

    if(!novo) return NULL;

    novo->valor = l->valor;
    novo->prox = clone(l->prox);
}

//--------17---------
LInt cloneRev (LInt l){
    if(!l) return NULL;

    LInt lista = NULL;

    while(l != NULL){
        LInt novo = malloc(sizeof(struct lligada));

        if(!novo) return NULL;

        novo->valor = l->valor;
        novo->prox = lista;
        lista = novo;

        l = l->prox;
    }
    return lista;

}

//--------18---------
int maximo (LInt l){
       LInt atual = l;
    int max=atual->valor;

    while(atual!=NULL){
        if(atual->valor > max) max = atual->valor;
        atual = atual->prox;
    }

    return max;
}

//--------19---------
int take (int n, LInt *l){
    int acc=0;

    if(!(*l)) return 0;

    LInt atual = (*l), ant = NULL;

    while(atual != NULL && n>0){
        ant = atual;
        atual = atual->prox;
        acc++,
        n--;
    }

    if(!atual) return acc;

    LInt temp;
    ant->prox = NULL;

    while(atual != NULL){
        temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return acc;
}

//--------20---------
int drop (int n, LInt *l){
    if(!(*l)) return l;
    int acc;

    LInt temp;

    while( (*l)!= NULL && n>0){
        temp = (*l);
        (*l) = (*l)->prox;
        free(temp);
        n--;
        acc++;
    }

    return acc;

}

//--------21---------
LInt Nforward (LInt l, int N){
    if(!l) return NULL;

    for(int i=0;i<N;i++){
        l = l->prox;
    }

    return l;
}

//--------22---------
int listToArray (LInt l, int v[], int N){
    if(!l) return 0;
    int acc;

    while(l != NULL && N>0){
         v[acc] = l->valor;
        l = l->prox,
        acc++;
        N--;
    }

    return acc;
}

//--------23---------
LInt arrayToList (int v[], int N){

    if(N==0) return NULL;
    
    LInt novo = malloc(sizeof(struct lligada));

    if(!novo) return;

    novo->valor = *v;
    novo->prox = arrayToList(v+1,N-1);
    

    return novo;
}

//--------24---------
LInt somasAcL (LInt l){
    if(!l) return NULL;

    int acc=0;
    LInt lista=NULL,aux = NULL;

    while(l!=NULL){
        acc+=l->valor;

        LInt novo = malloc(sizeof(struct lligada));

        if(!novo) return;

        novo->valor = acc;
        novo->prox = NULL;

        if(!lista) lista = aux = novo;
        else{
            aux->prox = novo;
            aux = novo;
        }

        l = l->prox;
    }

    return lista;
}

//--------25---------
void remreps (LInt l){
    if(l != NULL){
        while(l->prox){
            if(l->prox->valor == l->valor){
                LInt temp = l->prox;
                l->prox = temp->prox;
                free(temp);
            }
            else{
                l = l->prox;
            }
        }
    }
}

//--------26---------
LInt rotateL (LInt l){
    if(!l || !l->prox) return l;

    LInt fst = l;
    l = l->prox;
    fst->prox = NULL;

    LInt atual = l;
    while(atual->prox != NULL){
        atual = atual->prox;
    }

    atual->prox = fst;

    return l;
}

//--------27---------
LInt parte (LInt l){
    if(l == NULL || l->prox == NULL) return NULL;

    LInt novo = l->prox;
    l->prox = l->prox->prox;
    novo->prox = parte(l->prox);

    return novo;

}