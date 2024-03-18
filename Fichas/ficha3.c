#include<stdio.h>
#include<math.h>
// &i = endereço de i
//*b - conteudo do endereço de b

//1 a) 1 1 4, 2 2 6, 3 3 8, 4 4 10, 5 5 12

//1 b) 13

//2

void swapM (int *x,int *y){
    int aux=0;

    aux = *x;
    *x = *y;
    *y = aux;
}
void swap (int v[], int i, int j){
    int aux=0;

    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int soma (int v[], int N){
    int som = 0;

    for (int i=0;i<N;i++){
        som += v[i];
    }

    return som;
}

void inverteArray (int v[], int N){
    int i,j;
    for(int i=0,j=N-1;i<j;i++,j--){
        swap(v,i,j);
        //swapM(v+i,v+j);
    }
}

int maximum (int v[], int N, int *m){
    
    if(N>0) {

    
    int max=v[0];

    for(int i=1;i<N;i++){
        if(v[i]> max) max = v[i];
    }

    *m = max;

    return 0;
    }
    else return -1;
}

void quadrados (int q[], int N){
    int j=1;
    for (int i=0;i<N;i++,j++){
        q[i] = pow (j,2);
    }
}

void pascal (int v[], int N){
    v[0]=1;
    v[N]=1;

    
}


int main (){
    int x=3,y=5;
    swapM(&x,&y);
    printf("%d %d",x,y);
}