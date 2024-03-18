#include<stdio.h>
#include<math.h>
//Ex 1
// 1 - 12 16

// 2 - 0 (valor random)

// 3 - A 65
//     B 66 2 50
//     b 98

// 4 - 100 200

//Ex 2
// a) - 3 5
// b) - 11 66
// c) - _#_#_ ...
// d) 



// Informações importantes

// d% - print int
// c% - print char
// f% - print float
// % resto da divisão inteira
// != diferente
// y += x -> y = y + x
// putchar acrescentar um char
// void usa-se quando não retorna nada
// variaveis globais podem ser alteradas por todas as funções que as utilizem

//Ex 3

// 1)
void imprime_cardinal (int n)  {
    int i = 0;
    while (i<n) {
        putchar ('#');
        i+=1;
    }
}

void quadrado (int n) {
    int i = 0;
    while (i<n) {
        imprime_cardinal (n);
        putchar ('\n');
        i+=1;
    }
}

void imprime_hifen (int n)  {
    int i = 0;
    while (i<n) {
        putchar ('-');
        i+=1;
    }
}

void quadrado_v2 (int n) {
    int i = 0;
    while (i<n){
        if (i%2 == 0) {
            imprime_cardinal (n);
            putchar ('\n');
            i+=1;
        }
        else {
            imprime_hifen (n);
            putchar ('\n');
            i+=1;
        }

    }

}

// 2)

void imprimecardhif (int a, int b) {
    int i = 0;
    while (i<a) {
        if (b == 0) {
            putchar ('#');
            b == 1;
        }
        else {
            putchar ('_');
            b == 0;
        }
        i+=1;
    }
}

void quadrado2 (int n) {
    int i = 0;
    while (i<n) {
        if (i % 2 == 0) {
            imprimecardhif (n,0);
        }
        else {
            imprimecardhif (n,1);
        }
        i +=1;
    }

}

void imprimev2 (int n) {
    int i, cardinal=1;
    for (i=0; i<n; i++){
        if (cardinal == 1) {
            putchar ('#'), cardinal == 0;
        }
        else {
            putchar ('_'), cardinal == 1;
        }
    }
}

void quadrado2v2 (int n) {
    int i;
    for (i=0; i<n; i++){

    } // acabar depois
}

//3)
void triangulovertical (int n) {
    int i;
    for (i=0; i<n; i++){
        imprime_cardinal (i+1);
        putchar ('\n');
    }
    for (i=n-1; i> 0; i--) {
        imprime_cardinal (i);
        putchar ('\n');
    }
}

void triangulovertical2 (){
    int n,i, j, altura=1;

    scanf ("%d", &n);
    for (i=0;i<n;i++){
        for(j=0;j<altura;j++){
            putchar ('#');
        }
        altura += 1;
        putchar ('\n');
    }

    for (i=n-1;i>0;i--){
        for(j=0;j<i;j++){
            putchar ('#');
        }
        putchar ('\n');
    }
}

void imprime_espaco (int n)  {
    int i = 0;
    while (i<n) {
        putchar (' ');
        i+=1;
    }
}

int main () {

    int i,n;
    scanf("%d",&n);

    for (i=0; i<(n-1); i++){
        imprime_espaco (n-i-1);
        imprime_cardinal (i*2 + 1);
        putchar ('\n');
    }
    return 0;
}

//4)
/*
void circulo (int raio) {
    int res = 0, j, i;
    for (i=0; i< 2*raio + 1; i++) {
        for (j=0; i< 2*raio + 1; i++) {
            float d = sqrt(pow(i-raio,2) + pow (j-raio,2));
            if (d<=raio) {
                putchar ('#'), res++;
            }
            
        }
    }
    
}
*/