#define Max 10
struct staticStack {
    int sp;
    int values [Max];
};
typedef struct staticStack *SStack;

struct staticQueue {
	int front;
	int length;
	int values [Max];
};
typedef struct staticQueue *SQueue;

void SinitStack (SStack s){
    s->sp=0;
}

int SisEmpty (SStack s){
    if (s->sp == 0) return 1;
    else return 0;
}

int Spush (SStack s, int x){
    if(s->sp >= Max) return 1;
    else{
        s->values[s->sp] = x;
        s->sp++;
    }
    return 0;

}

int Spop (SStack s, int *x){
    if(SisEmpty(s)==1) return 1;
    else{
        *x = s->values[(s->sp)--];
        s->sp--;
    }

    return 0;
}

int Stop (SStack s, int *x){
    if(SisEmpty(s)==1) return 1;
    else{
        *x = s->values[(s->sp)-1];
    }

    return 0;
}

void SinitQueue (SQueue q){
    q->length = 0;
}

int SisEmptyQ (SQueue q){
    if(q->length == 0) return 1;
    else return 0;
}

int Senqueue (SQueue q, int x){
    if(q->length + q->front >= Max) return 1;
    else{
        q->values[q->length+q->front] = x;
        return 0;
    }
}

int Sdequeue (SQueue q, int *x){
    if(SisEmptyQ(q)==1) return 1;
    else{

    }
}
