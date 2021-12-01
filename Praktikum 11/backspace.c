#include <stdio.h>
#include <stdlib.h>
#include "stack_linked.h"
// #include "stack_linked.c"
// #include "boolean.h"

int main(){
    Stack s1, s2;
    CreateStack(&s1);
    CreateStack(&s2);
    int m, n;
    scanf("%d %d", &m, &n);
    while(m--){
        int now;
        scanf("%d", &now);
        if (now == 0 && !isEmpty(s1)){
            int nilai;
            pop(&s1, &nilai);
        }
        else if(now != 0){
            push(&s1, now);
        }
    }
    while(n--){
        int now;
        scanf("%d", &now);
        if (now == 0 && !isEmpty(s2)){
            int nilai;
            pop(&s2, &nilai);
        }
        else if(now != 0){
            push(&s2, now);
        }
    }

    Address p, q;
    p = ADDR_TOP(s1);
    q = ADDR_TOP(s2);
    int eq=1;
    while(true){
        if(p == NULL && q == NULL) break;  
        if((p == NULL && q != NULL) || (p != NULL && q == NULL) || (INFO(p) != INFO(q))){
            eq=0;
            break;
        }
        p = NEXT(p);
        q = NEXT(q);
    }
    if (eq) printf("Sama\n");
    else printf("Tidak sama\n");
}