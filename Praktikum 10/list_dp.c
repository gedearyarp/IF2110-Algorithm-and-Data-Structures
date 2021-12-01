#include "list_dp.h"
#include "stdio.h"
#include "stdlib.h"


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
    return (FIRST(l) == NULL && LAST(l) == NULL);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    FIRST(*l) == NULL; 
    LAST(*l) == NULL;
}
/* I.S. l sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
Address allocate(ElType val){
    Address nd;
    nd = (Address) malloc (sizeof(Node));
    if(nd != NULL){
        NEXT(nd) = NULL;
        PREV(nd) = NULL;
        INFO(nd) = val;
    }
    return nd;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL. */
/* Misalnya: menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL, PREV(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL. */
void deallocate (Address p){
    free(p);
}
/* I.S. p terdefinisi */
/* F.S. p dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val){
    Address now = FIRST(l);
    while(now != NULL){
        if(INFO(now) == val) break;
        now = NEXT(now);
    }
    return now;
}
/* Mencari apakah ada elemen list dengan INFO(P)=val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
    Address now = allocate(val);
    if(!isEmpty(*l)){
        NEXT(now) = FIRST(*l);
        PREV(FIRST(*l)) = now;
        FIRST(*l) = now;
    }
    else{
        FIRST(*l) = now;
        LAST(*l) = now;
    }
}
/* I.S. List l terdefinisi */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void insertLast(List *l, ElType val){
    Address now = allocate(val);
    if(!isEmpty(*l)){
        PREV(now) = LAST(*l);
        NEXT(LAST(*l)) = now;
        LAST(*l) = now;
    }
    else{
        FIRST(*l) = now;
        LAST(*l) = now;
    }
}
/* I.S. List l terdefinisi */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void insertAfter(List *L, Address p, Address pRec){
    if(LAST(*L) == pRec){
        PREV(p) = pRec;
        NEXT(pRec) = p;
        LAST(*L) = p;
    }
    NEXT(p) = NEXT(pRec);
    PREV(p) = pRec;
    PREV(NEXT(pRec)) = p;
    NEXT(pRec) = p;
}
/* I.S. pRec pasti elemen list; p sudah dialokasi */
/* F.S. Insert p sebagai elemen sesudah elemen beralamat pRec */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
    *val = INFO(FIRST(*l));
    if(FIRST(*l) == LAST(*l)){
        FIRST(*l) = NULL;
        LAST(*l) = NULL;
        return;
    }
    FIRST(*l) = NEXT(FIRST(*l));
    PREV(FIRST(*l)) = NULL;
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val){
    *val = INFO(LAST(*l));
    if(FIRST(*l) == LAST(*l)){
        FIRST(*l) = NULL;
        LAST(*l) = NULL;
        return;
    }
    LAST(*l) = PREV(LAST(*l));
    NEXT(LAST(*l)) = NULL;
}
/* I.S. list l tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen terakhir di-dealokasi */
void deleteAfter(List *l, Address *pDel, Address pRec){
    *pDel = NEXT(pRec);
    if(NEXT(pRec) == LAST(*l)){
        NEXT(pRec) = NULL;
        LAST(*l) = pRec;
        return;
    }
    Address now = NEXT(pRec);
    NEXT(pRec) = NEXT(now);
    PREV(NEXT(now)) = pRec;
}
/* I.S. List tidak kosong. pRec adalah anggota list. 
        NEXT(pRec)!=NULL */
/* F.S. Menghapus NEXT(pRec): */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
    Address now = FIRST(l);
    printf("[");
    while(now != NULL){
        printf("%d", INFO(now));
        now = NEXT(now);
        if(now != NULL) printf(",");
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void displayListBackwards(List l){
    Address now = LAST(l);
    printf("[");
    while(now != NULL){
        printf("%d", INFO(now));
        now = PREV(now);
        if(now != NULL) printf(",");
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
