#include<stdio.h>
#include<string.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

void libertaLista (Palavras l){
    Palavras aux;

    while(l != NULL){
        aux = l -> prox;
        free(l->palavra);
        free(l);
        l=aux;
        
    }

}

int quantasP (Palavras l){
    int acc=0;
    while(l != NULL){
        acc++;
        l = l-> prox;
    }
}

void listaPal (Palavras l){
    while (l != NULL){
        printf("%s %d\n", &l->palavra, &l->ocorr);
    }
}

char * ultima (Palavras l){
    char* aux = NULL;

    while(l!=NULL){
        aux = l->palavra;
        l=l->prox;
    }

    return aux;
}

Palavras acrescentaInicio (Palavras l, char *p){
    Palavras novo = malloc (sizeof(struct celula));

    novo->prox = l;
    novo->ocorr = 1;

    char *aux = malloc (sizeof(char) * strlen(p) + 1);
    strcpy(aux,p);
    novo->palavra = aux;

    return novo;

}

Palavras acrescentaFim (Palavras l, char *p){

}

Palavras acrescenta (Palavras l, char*p){
    
}

struct celula * maisFreq (Palavras l){
    int max=0;
    
}
