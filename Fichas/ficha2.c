#include<stdio.h>

float multInt1 (int n, float m){
    float r = 0;
    int i=0;

    while(i<n){
        r += m;
        i++;
    }

    return r;
}

float multInt2 (int n, float m){
    float r = 0; int i = 0;
    
    while (n >= 1){
     
        if ((n % 2) == 1){
            r += m;
        }
        
        n = n / 2;
        m = m * 2;
        i++;
    }

    return r;
}


int mdc1 (int a, int b){
    if (b>=a){
        for(int i=a; i>0; i--){
            if (((a % i) == 0) && (b % i == 0)) return i;
        }
    }
    if (a>b){
         for(int j=b; j>0; j--){
            if (((b % j) == 0) && (a % j == 0)) return j;
        }
    }
}

int mdc2 (int a, int b){
    while(a>0 && b>0){
        if (a>b) a -= b;
        if (b>a) b -= a;
        if (a==b) break;
    }

    if (a>=b) return a;
    else return b;
}

int mdc3 (int a, int b){
      while(a>0 && b>0){
        if (a>b) a = a % b;
        if (b>a) b = b % a;
        if (a==b) break;
    }

    if (a>=b) return a;
    else return b;
}

int fib1 (int n){
    if (n == 1 || n == 2) return 1;
    else return (fib1(n-1) + fib1(n-2));
}

int fib2 (int n){
    int x = fib2(n-1);
    int y = fib2(n-2);

    return (x+y); 
}



int main () {
    int n = 0, l = 0, x = 0, c = 0;
    float m = 0, y = 0, r = 0;

    if (scanf ("%d",&x) == 1) n = x;
    //if (scanf ("%d", &x) == 1) l = x;

    c = fib1 (n);

    printf("%d\n",c);

    return 0;
}

// &x -> endereço de memória de x
// *p -> conteúdo de p

void cenas () {
    int x, y;
    int *p;
     x = 1; y = 2;

    p = &x;
    y = *p;
    *p = 0;

// no final o x=0 e y=1 (testar depois)
}