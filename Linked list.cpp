#include <stdio.h>

#define N 100010
#define  INF (1 << 30)

int n, tmp, v;

struct Titem{
    int num;
    Titem *prev;
    Titem *next;
    
} *start, *last;

void prepend(int val){
    if(start == NULL){
        start = new Titem;
        start->num = val;
        start->prev = NULL;
        last = start;
        
    }else{
        Titem *p = new Titem;
        p->next = start;
        p->prev = NULL;
        p->num = val;
        start->prev = p;
        start = p;
    }
    return;
}

void uppend(int val){
    if(last == NULL){
        last = new Titem;
        last->num = val;
        last->prev = NULL; 
        start = last;
    }else{
        Titem *p = new Titem;
        p->next = NULL;
        p->prev = last;
        p->num = val;
        last->next = p;
        last = p;
    }
    return;
}

void Delete(Titem *p){
    if(p == NULL) return;
    
    if(p == start){
        if(start == last){
            delete p;
            start = NULL; 
            last = NULL;
            p = NULL;
            return;
        }
        start = p->next;
        delete p;
        start->prev = NULL;
        return;
    }
    if(p == last){
        if(start == last){
            delete p;
            start = NULL; 
            last = NULL;
            p = NULL;
            return;
        }
        last = last->prev;
        delete p;
        last->next = NULL;
        return;
    }
    (p->prev)->next = p->next;
    (p->next)->prev = p->prev;
    delete p; p = NULL;
    return;
}

int main() {
        while(scanf("%d",&tmp) != EOF){
            switch(tmp){
                case 1: scanf("%d",&v); prepend(v); break;
                case 2: scanf("%d",&v); uppend(v); break;
                case 3: printf("%d\n",start->num); Delete(start); break;
                case 4: printf("%d\n",last->num); Delete(last); break;
            }
        }
        
	return 0;
}
