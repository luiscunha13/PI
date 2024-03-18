#include<stdio.h>
#include<string.h>

void um (){
    int x=0, maior=0;

    while(scanf("%d",&x) == 1){
        if(x==0)break;
        if(x>=maior) maior = x;
    }

    printf("%d",maior);
}

void dois (){
    int x=0, soma=0, acc=0;
    float media;

    while(scanf("%d",&x) == 1){
        if(x==0)break;
        else{
            soma += x;
            acc++;
        }
    }

    media = soma/acc;
    printf("%f",media);
}

void tres (){
    int x=0, maior=0, segundomaior=0;

    while(scanf("%d",&x) == 1){
        if(x==0) break;
        if(x>maior) {
            segundomaior = maior;
            maior = x;
        }
        else if(x>segundomaior) segundomaior = x;
    }

    printf("%d",segundomaior);
}


int bitsUM (unsigned int n){
    int r=0;
    while(n){
        r += (n%2);
        n /=2;
    }

    return r;
}


int trailingZ (unsigned int n){
    int r = 0;

    while(n % 2 != 1){
        if(n == 0)
            return 32;
        n /= 2;
        r++;
    }
    
    return r;
}

int qDig (unsigned int n){
    int acc=1;

    if(n/10 <1) return acc;
    else return 1 + qDig(n/10);

}

char *strcat1 (char s1[], char s2[]){
    int x = strlen (s1);
    for(int i=0;i<strlen(s2);i++){
        s1[x+i] = s2[i];
    }
    s1[x+strlen(s2)] = '\0';

    return s1;
}

char* strcpy1 (char* dest, char source[]) {
    int x = strlen(source);

    for(int i=0;i<x;i++){
        dest[i] = source[i];
    }
    dest[x] = '\0';

    return dest;
}

int strcmp1 (char s1[], char s2[]){
    for(int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++){
        if(s1[i] > s2[i] || s2[i] == '\0'){
            return 1;
        }
        
        if(s1[i] < s2[i] || s1[i] == '\0'){
            return -1;
        }
    }
    
    return 0;
}

char *strstr (char s1[], char s2[]){

    int existe=1;
    for(int i=0;i<strlen(s1);i++){
        if(s1[i] == s2[0] && strlen(s1)-i>=strlen(s2)){ // ver a condição melhor
            existe=1;
            for(int j=1,k=i+1;j<strlen(s2);j++,k++){
                if(s1[k]!=s2[j]){
                    existe=0;
                    break;
                }
            }
            if (existe==1) return i;
        }
    }

    return NULL;
}

void strrev (char s[]) {
    int x = strlen(s);
    char reverse[x];

    for(int i=0;i<x;i++) reverse[i] = s[x-i-1];
    for(int j=0;j<x;j++) s[j] = reverse[j];
}

void strnoV (char s[]) {
    int x = strlen(s);

    for(int i=0;i<x;i++){
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            for(int j=i;j<x;j++){
                s[j] = s[j+1];
            }
            i--;
            x--;
        }
    
    }
}

void truncW (char t[], int n) {
    int x=strlen(t);

    for(int i=0;i<x;i++){                // ver esta melhor depois
        int j=i+n;

        while(t[j] != ' ' ||t[j] != '\0' || t[j] != '\n'){
                t[j] = t[j+1];
                x--;
        }

        i++;


    }
}

int existe(char c[], char l){
    int x = strlen(c);
    int aux=0;

    for(int i=0;i<x;i++){
        if(c[i] == l){
            aux = 1;
            break;
        }
    }

    return aux;

}

char charMaisFreq (char s[]){
    int x = strlen(s);
    char aux[x];
    int conta[x];
    aux[0] = s[0];
    conta[0] = 1;

    for(int i=1;i<x;i++){
        if(existe(aux,s[i]) == 1){
            for(int j=0;j<strlen(aux);j++){
                if(s[i] == aux[j]){
                   conta[j]+=1; 
                   break;
                } 
            }
        }
        else{
            aux[strlen(aux)] = s[i];
            conta[strlen(aux)] = 1;

        }
    }

    int max=0;
    for(int j=1;j<strlen(aux);j++){
        if(conta[j] > conta[max]) max = j;
    }

    return aux[max];
}

int iguaisConsecutivos (char s[]) {
    int aux=1, max=0;

    for(int i=0;i<strlen(s);i++){
        if(s[i] == s[i+1]) aux++;
        else{
            if(aux > max) max = aux;
            aux = 1;
        }
    }

    return max;
}

int ediferente(char s[],char c, int pos){
    int aux=1;

    for(int i=pos;i>=0;i--){
        if(s[i] == c){
            aux = 0;
        }
    }

    return aux;
}

int difConsecutivos(char s[]) {   // ver melhor depois
    int aux=1, max=0;
    
    for(int i=1;i<strlen(s);i++){
        if(ediferente(s,s[i],i) == 1) aux++;
        else{
            if(aux > max) max = aux;
            aux = 1;
        }
    }

    return max;
}

int maiorPrefixo (char s1 [], char s2 []){
    int aux=0;

    if(strlen(s1)>=strlen(s2)){
        for(int i=0;i<strlen(s2);i++){
            if(s1[i] == s2[i]) aux++;
            else{
                break;
            }
        }
    }
    else{
        for(int i=0;i<strlen(s1);i++){
            if(s1[i] == s2[i]) aux++;
            else{
                break;
            }
        }
    }

    return aux;
}

int maiorSufixo (char s1 [], char s2 []){
    int aux=0;

    if(strlen(s1)>=strlen(s2)){
        for(int i=strlen(s2)-1;i>=0;i--){
            if(s1[i] == s2[i]) aux++;
            else{
                break;
            }
        } 
    }
    else{
        for(int i=strlen(s1)-1;i>=0;i--){
            if(s1[i] == s2[i]) aux++;
            else{
                break;
            }
        } 
    }

    return aux;

}

int sufPref (char s1[], char s2[]){
    int size = 0;
    for(int i = 0; s1[i] != '\0'; i++){
        if(s1[i] == s2[size])
            size++;
        else
            size = 0;
    }

    return size;
}


int contaPal (char s[]){
    int x = strlen(s);
    int acc=0;
    int charant = 0;

    for(int i=0;i<x;i++){
        if(s[i] == ' ' || s[i] == '\0' || s[i] == '\n'){
            if(charant == 1) acc++;
            charant=0;
        }
        else{
            charant=1;
        }
    }

    return acc;
}

int contaVogais (char s[]) {
    int acc=0;

    for(int i=0;i<strlen(s);i++){
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') acc++;
    }

    return acc;
}

int contida (char a[], char b[]){
    int aux=1;
    for(int i=0;i<strlen(a);i++){
        if(existe(b,a[i])==0){
            aux = 0;
            break;
        }
    }

    return aux;
}

int palindrome (char s[]){
    int x=strlen(s),aux=1;
    char rev[x];

    for(int i=0;i<x;i++) rev[x-i-1] = s[i];
    for(int j=0;j<x;j++){
        if(s[j] != rev[j]){
            aux=0;
            break;
        }
    }

    return aux;
}

int remRep (char s[]){
    int x = strlen(s);

    for(int i=0;i<x;i++){
        if(s[i] == s[i+1]){
            for(int j=i+1;j<x;j++){
                s[j] = s[j+1];
            }
            i--;
        }
    }

    return (strlen(s));
}

int limpaEspacos(char s[]) {
    int x = strlen(s);

    for(int i=0;i<x;i++){
        if(s[i] == ' ' && s[i+1] == ' '){
            for(int j=i+1;j<x;j++){
                s[j] = s[j+1];
            }
            i--;
        }
    }
}

// falta a 26 não percebi

void merge (int r [], int a[], int b[], int na, int nb){
    int auxa=0, auxb=0;

    for(int i=0;i<na+nb;i++){
        if(auxa<na && a[auxa] < b[auxb]){
            r[i] = a[auxa];
            auxa++;
        }
        else if(auxb<nb && b[auxb] < a[auxa]){
            r[i] = b[auxb];
            auxb++;
        }
        else if(auxb==nb) r[i] = a[auxa];
        else if(auxa==na) r[i] = b[auxb];
    }

}

int crescente (int a[], int i, int j){
    int aux=1;

    for(int k=i;k<j;k++){
        if(a[i]>a[i+1]) aux=0;

    }

    return aux;
}

int retiraNeg (int v[], int N){
    int aux=0;

    for(int i=0;i<N;i++){
        if(v[i]<0){
            for(int j=i;j<N;j++){
                v[j] = v[j+1];
            }
            i--;
            aux++;
        }
    }

    return (N-aux);
}

int menosFreq (int v[], int N){
    int pos = 0, acc=1,min=N, final=0;

    for(int i=0;i<N;i++){
        if(v[i] == v[i+1]){
            acc++;
        }
        else{
            if(acc<min) {
                final = pos;
                min = acc;
            }
            acc=1; 
            pos=i+1;
        }
    }

    return(v[final]);
}

int maisFreq (int v[], int N){
    int pos = 0, acc=1,max=0, final=0;

    for(int i=0;i<N;i++){
        if(v[i] == v[i+1]){
            acc++;
        }
        else{
            if(acc>max) {
                final = pos;
                max = acc;
            }
            acc=1; 
            pos=i+1;
        }
    }

    return(v[final]);
}

int maxCresc (int v[], int N){
    int pos = 0, acc=1,max=0;

    for(int i=0;i<N;i++){
        if(v[i] < v[i+1]){
            acc++;
        }
        else{
            if(acc>max) max = acc;
            acc=1; 
        }
    }

    return(max);
}

int elimRep (int v[], int N) {
    int acc=0;

    for(int i=1;i<N;i++){
        for(int j=i-1;j>=0;j--){
            if (v[j] == v[i]){
                for(int k=i;k<N;k++){
                    v[k] = v[k+1];
                }
                i--;
                acc++;
                break;
            }
        }
    }

    return (N-acc);
}

int elimRepOrd (int v[], int N){
    int acc=0;

    for(int i=0;i<N;i++){
        if(v[i]==v[i+1]){
            for(int j=i+1;j<N;j++){
                v[j] = v[j+1];
            }
            i--;
            acc++;
        }
    }

    return (N-acc);
}

int comunsOrd (int a[], int na, int b[], int nb){
    int acc=0;
    
    for(int i=0;i<na;i++){
        for(int j=0;j<nb;j++){
            if(a[i] == b[j]){
                acc++;
                break;
            }
        }
    }

    return acc;
}

int comuns (int a[], int na, int b[], int nb){
    int acc=0;
    
    for(int i=0;i<na;i++){
        for(int j=0;j<nb;j++){
            if(a[i] == b[j]){
                acc++;
                break;
            }
        }
    }

    return acc;
}

int minInd (int v[], int n){
    int min=0;

    for(int i=1;i<n;i++){
        if(v[i]<v[min]) min = i;
    }

    return min;
}

void somasAc (int v[], int Ac [], int N){
    int acc=0;

    for(int i=0;i<N;i++){
        acc+= v[i];
        Ac[i] = acc;
    }

}

// falta 39 e 40

void addTo(int N, int M, int a[N][M], int b[N][M]){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            a[N][M] += b[N][M];
        }
    }
}

int unionSet (int N, int v1[N], int v2[N], int r[N]){
    int acc=0;
    for(int i=0;i<N;i++){
        if(v1[i] + v2[i] >= 1) r[i] = 1;
        else r[i] = 0;
        acc++;
    }

    return acc;
}

int intersectSet (int N, int v1[N], int v2[N],int r[N]){
    int  acc=0;

    for(int i=0;i<N;i++){
        if(v1[i] == v2[i]) r[i] = v1[i];
        else r[i] = 0;
        acc++;
    }

    return acc;
    
}

int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
    int acc=0;

    for(int i=0;i<N;i++){
        if(v1[i] == 0 || v2[i] == 0) r[i] = 0;
        else{
            if(v1[i] >= v2[i]) r[i] = v2[i];
            if(v1[i] < v2[i]) r[i] = v1[i];
        }
        acc++;
    }

    return acc;

}


int unionMSet (int N, int v1[N], int v2[N], int r[N]){
    int acc=0;

    for(int i=0;i<N;i++){
        if(v1[i] >= v2[i]) r[i] = v1[i];
        else if(v1[i] < v2[i]) r[i] = v2[i];
        
        acc++;
    }

    return acc;
} 

int cardinalMSet (int N, int v[N]){
    int acc=0;

    for(int i=0;i<N;i++) acc+=v[i];

    return acc;
}

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
    int x, y;
} Posicao; 

Posicao posFinal (Posicao inicial, Movimento mov[], int N) {

    for(int i=0;i<N;i++){
        if(mov[i] == Este) inicial.x +=1;
        else if(mov[i] == Oeste) inicial.x +=1;
        else if(mov[i] == Norte) inicial.y -=1;
        else if(mov[i] == Sul) inicial.y -=1;
    }

    return inicial;
}

int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    for(int i=0;i<N;i++){
        if(inicial.x < final.x){
            inicial.x++;
            mov[i] = Este;
        }
        else if(inicial.x > final.x){
            inicial.x--;
            mov[i] = Oeste;
        }
        else if(inicial.y < final.y){
            inicial.y++;
            mov[i] = Norte;
        }
        else if(inicial.y < final.y){
            inicial.y--;
            mov[i] = Sul;
        }
        else break;
    }

    if(inicial.x != final.x || inicial.y != final.y) return -1;
    else return 1;
}





int main(){

    char s[] = "liberdade, igualdade e fraternidade";
    truncW(s,4);

    printf("%s",s);
    return 0;
}