#include<stdio.h>
#include<stdlib.h>


typedef struct LInt_nodo {
    int valor;
    struct LInt_nodo *prox;
} *LInt;

typedef struct ABin_nodo {
    int valor;
    struct ABin_nodo *esq, *dir;
} *ABin;

//-----------1----------
int nesimo(int a[], int N, int i){
    for(int k=0;i<N;k++){
        for(int j=k+1;j<N;j++){
            if(a[k]<a[j]){
                int aux = a[k];
                a[k] = a[j];
                a[j] = aux;
            }
        }
    }

    return a[i-1];

}


//-----------2----------
LInt removeMaiores(LInt l, int x){
    if(!l) return NULL;

    LInt atual=l, ant=NULL;

    while(atual!=NULL){
        if(atual->valor > x){
            if(!ant){
                l = atual->prox;
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

    return l;
}

//-----------3----------
LInt caminho(ABin a, int x){
    if(!a) return NULL;

    LInt caminho = NULL, ant = NULL;

    while(a != NULL){
        LInt novo = malloc(sizeof(struct LInt_nodo));
        if(!novo) return;
        novo->valor = a->valor;
        novo->prox = NULL;

        if(!ant) caminho = novo = ant;
        else{
            ant->prox = novo;
            ant = novo;
        }

        if(x>a->valor) a = a->dir;
        else if(x<a->valor) a = a->esq;
        else return caminho;
    }
    return NULL;
}



//-----------4----------
void inc(char s[]){
    int size=0;
    for(size;s[size] != '\0';size++);

    if(size == 0) return;

    int num[size+1];

    for(int i=0;i<size;i++){
        if(s[i] == '0') num[i+1] = 0;
        if(s[i] == '1') num[i+1] = 1;
        if(s[i] == '2') num[i+1] = 2;
        if(s[i] == '3') num[i+1] = 3;
        if(s[i] == '4') num[i+1] = 4;
        if(s[i] == '5') num[i+1] = 5;
        if(s[i] == '6') num[i+1] = 6;
        if(s[i] == '7') num[i+1] = 7;
        if(s[i] == '8') num[i+1] = 8;
        if(s[i] == '9') num[i+1] = 9;
    }
    int maisumalg=0;
    for(int j=size+1;j>0;j--){
        if(j==1 && num[j]+1==10){
            num[j] = 0;
            num[0] = 1;
            maisumalg = 1;
        }
        if(num[j]+1 == 10){
            num[j] = 0;
        }
        if(num[j]+1 < 10){
            num[j] +=1;
            break;
        }
    }

    int c=1,d=0;
    if(maisumalg == 1) c=0;

    for(c,d;c<size+1;c++,d++){
        if(num[c] == 0) s[d] = '0';
        if(num[c] == 1) s[d] = '1';
        if(num[c] == 2) s[d] = '2';
        if(num[c] == 3) s[d] = '3';
        if(num[c] == 4) s[d] = '4';
        if(num[c] == 5) s[d] = '5';
        if(num[c] == 6) s[d] = '6';
        if(num[c] == 7) s[d] = '7';
        if(num[c] == 8) s[d] = '8';
        if(num[c] == 9) s[d] = '9';
    }
}


//-----------5----------
int sacos(int p[], int N, int C){
    if(N<=0) return 0;

    
}
















int main(){
    char s[4];

    scanf(" %[^\n]s",s);
    inc(s);

    printf("%s",s);

    return 0;

}