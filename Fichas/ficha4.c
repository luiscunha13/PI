#include<string.h>

int evogal (char c){
    int acc=0;
    if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' ||c == 'O' || c == 'o' || c == 'U' || c == 'u') acc+=1;
    return acc;
}

int contaVogais (char *s){
    int r=0;

    for(int i=0;s[i] != '\0';i++){
        if (evogal(s[i])) r++;
    }

    return r;
}


int retiraVigaisRep2 (char *s){
    int i,j,count=0;

    for(i=0;s[i] !='\0';i++){
        if(evogal (s[i]) && s[i+1] == s[i]) count++;
        else{
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
    return count;
}

int duplicaVogais (char *s){
    int r = contaVogais(s), aux=0;

    char s1 [(strlen(s)) + r];

    for(int i=0;i<strlen(s);i++,aux++){
        if (evogal(s[i])) {
            s1[aux] = s1[aux+1] = s[i];
            aux+=1;
        }
        else s1[aux] = s[i];
    }

    return (aux-strlen(s));

}

int duplicaVogais2 (char *s){
    char aux [strlen(s)*2 +1];
    int i,j,count=0;

    for(i=j=0;s[i]!='\0';i++){
        if(evogal(s[i])){
            count++;
            aux[j++] = s[i];
            aux[j] = s[i];
        }
        else{
            aux[j] = s[i];
        }
        j++;
    }

    aux[j] = '\0';
    strcpy(s,aux);
    return count;
} 

int ordenado (int *v, int N){
    int i,r=1;

    for(i=1;i<N;i++){
        if(v[i-1]>v[i]) r=0;

   }
   return r;
}