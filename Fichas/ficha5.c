typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

int nota (Aluno a){
    float notaminiT, notatotal;

    for(int i=0;i<6;i++) notaminiT += a.miniT[i];

    
    notaminiT /= 6;
    notaminiT = (notaminiT*10)/2;

    if(notaminiT>5){
        notatotal = (0.2*notaminiT) + (0.8*a.teste);
    }
    else return 0;
    
    notatotal = round(notatotal);
    if(notatotal<10) return 0;
    else return notatotal; 
}

int main(){
    return 0;
}

int procuraNum (int num, Aluno t[], int N){
    for(int i=0;i<N;i++){
        if(num == t[i].numero) return i;
        if(t[i].numero > num) break;
    }

    return -1;
}

procuraNum2 (int num, Aluno t[], int N){
    int left, right, mid;
    left=0, right = N-1, mid=N/2;
    
    if(t[mid].numero > num){
        right = mid-1;
    }
    else if(t[mid].numero<num){
        left=mid+1;
    }
    else{
        return mid;
    }

  
}

void ordenaPorNum (Aluno t[], int N){
    int aux;
    for(int i=0;i<N;i++){
        aux=t[i].numero;
        for(int j=i;j>0 && t[j-1].numero > aux;j--){
            t[j].numero = t[j-1].numero;
            t[j].numero = aux;
        }
    }
}

