#include "list_circular.h"
#include <stdio.h>
#include <stdlib.h> 

void deleteRR (List *L, ElType tq){
    if(!isEmpty(*L)) {
        Address last = FIRST(*L);
        while (NEXT(last) != FIRST(*L)) last = NEXT(last);
        if ( INFO(last) <= tq ){
            int now;
            deleteLast(L, &now);
            printf("%d\n", now);
        }
        else {
            printf("%d\n", tq);
            INFO(last) = INFO(last)-tq;
            FIRST(*L) = last;
        } 
    } 
    else printf("List kosong\n");
}

float average (List L){
    Address now = FIRST(L);
    float summ = 0;
    int cnt = 0;
    while (NEXT(now) != FIRST(L)) {
        summ += INFO(now);
        now = NEXT(now);
        cnt++;
    }
    summ += INFO(now);
    cnt++;
    return (float)summ/cnt;
}

int main () {
    int tq;
    List L;
    CreateList(&L);
    while(true){
        scanf("%d",&tq);
        if(tq > 0) break;
    }
    while(true) {
        char op;
        scanf(" %c", &op);
        if (op == 'A') {
            int n;
            scanf("%d",&n);
            if (n > 0) insertFirst(&L,n);
        } 
        else if (op == 'D') deleteRR(&L,tq);
        else if (op == 'F') break;
        else printf("Kode salah\n");
    }  

    if(!isEmpty(L)) printf("%.2f\n", average(L));
    else printf("Proses selesai\n");

    return 0;
}
