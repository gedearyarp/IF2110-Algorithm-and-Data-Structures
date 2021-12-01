#include <stdio.h>
#include <stdlib.h>
#include "queue_linked.h"

int main(){
    Queue antrian;
    CreateQueue(&antrian);
    int n, tot=0; scanf("%d", &n);
    while(n--){
        int tm; scanf("%d", &tm);
        enqueue(&antrian, tm);
        tot++;
        while(tm-INFO(ADDR_HEAD(antrian))>300){
            int nilai;
            tot--;
            dequeue(&antrian, &nilai);
        }
        printf("%d\n", tot);
    }
}