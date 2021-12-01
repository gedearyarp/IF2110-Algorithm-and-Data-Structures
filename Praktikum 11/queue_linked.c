#include "boolean.h"
#include "queue_linked.h"
#include <stdlib.h>

/* Prototype manajemen memori */
Address newNode(ElType x){
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NULL jika alokasi gagal */
boolean isEmpty(Queue q){
    return (ADDR_HEAD(q)==NULL && ADDR_TAIL(q)==NULL);
}
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
int length(Queue q){
    int cnt=0;
    Address n = ADDR_HEAD(q);
    while( n != NULL){
        cnt++;
        n = NEXT(n);
    }
    return cnt;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */

/*** Kreator ***/
void CreateQueue(Queue *q){
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */

/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x){
    Address n = newNode(x);
    if(isEmpty(*q)){
        ADDR_TAIL(*q) = n;
        ADDR_HEAD(*q) = n;
        return;
    }
    NEXT(ADDR_TAIL(*q)) = n;
    ADDR_TAIL(*q) = n;
}
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */
void dequeue(Queue *q, ElType *x){
    *x = INFO(ADDR_HEAD(*q));
    ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
    if (ADDR_HEAD(*q) == NULL){
        ADDR_TAIL(*q) = NULL;
    }
}
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
