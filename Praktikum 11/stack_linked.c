#include "boolean.h"
#include "stack_linked.h"
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
   atau 
   NULL jika alokasi gagal */   

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean isEmpty(Stack s){
    return ADDR_TOP(s) == NULL;
}
/* Mengirim true jika Stack kosong: ADDR_TOP(s) = NULL */
void CreateStack(Stack *s){
    ADDR_TOP(*s) = NULL;
}
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack s yang kosong */
void push(Stack *s, ElType x){
    Address n = newNode(x);
    if(isEmpty(*s)){
        ADDR_TOP(*s) = n;
        return;
    }
    NEXT(n) = ADDR_TOP(*s);
    ADDR_TOP(*s) = n;
}
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */
void pop(Stack *s, ElType *x){
    *x = TOP(*s);
    ADDR_TOP(*s) = NEXT(ADDR_TOP(*s));
}
/* Menghapus Top dari Stack s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */
