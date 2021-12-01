#include "list_circular.h"
#include "stdio.h"
#include "stdlib.h"


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
    return FIRST(l) == NULL;
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    FIRST(*l) = NULL;
}
/* I.S. l sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
Address allocate(ElType val){
    Address nd;
    nd = (Address)malloc(sizeof(ElmtList));
    if(nd != NULL){
        INFO(nd) = val;
        NEXT(nd) = NULL;
    }
    return nd;
}
/* Mengirimkan Address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
/* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
void deallocate(Address P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val){
    if (isEmpty(l)) return NULL;
    Address now = FIRST(l);
    while((NEXT(now) != FIRST(l))){
        if(INFO(now) == val){
            return now;
        }
        now = NEXT(now);
    }
    if(INFO(now) == val) {
        return now;
    }
    return NULL;
}
/* Mencari apakah ada elemen list dengan INFO(P)= val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */

boolean addrSearch(List l, Address p){
    Address now = FIRST(l);
    if (isEmpty(l)) return false;
    while(NEXT(now) != FIRST(l)){
        if(now == p) return true;
        now = NEXT(now);
    }
    if(now == p) return true;
    return false;
}
/* Mencari apakah ada elemen list l yang beralamat p */
/* Mengirimkan true jika ada, false jika tidak ada */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
    Address now, last;
    now = allocate(val);
    last = FIRST(*l);
    if(isEmpty(*l)){
        NEXT(now) = now;
        FIRST(*l) = now;
        return;
    }
    while(NEXT(last) != FIRST(*l)){
        last = NEXT(last);
    }
    NEXT(last) = now;
    NEXT(now) = FIRST(*l);
    FIRST(*l) = now;
}
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
/* Elemen terakhir list menunjuk ke address dari elemen pertama baru list */
void insertLast(List *l, ElType val){
    Address now, last;
    now = allocate(val);
    last = FIRST(*l);
    if(isEmpty(*l)){
        NEXT(now) = now;
        FIRST(*l) = now;
        return;
    }
    while(NEXT(last) != FIRST(*l)){
        last = NEXT(last);
    }
    NEXT(last) = now;
    NEXT(now) = FIRST(*l);
}
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
/* Elemen terakhir baru list menunjuk ke address dari elemen pertama list */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType * val){
    *val = INFO(FIRST(*l));
    if(NEXT(FIRST(*l)) == FIRST(*l)){
        FIRST(*l) = NULL;
        return;
    }
    Address last;
    last = FIRST(*l);
    while(NEXT(last) != FIRST(*l)){
        last = NEXT(last);
    }
    NEXT(last) = NEXT(FIRST(*l));
    FIRST(*l) = NEXT(FIRST(*l));
}
/* I.S. List l tidak kosong  */
/* F.S. val adalah elemen pertama List l sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      First element yg baru adalah suksesor elemen pertama yang lama */
/*      Jika list baru tidak kosong, Last element menunjuk ke First element baru */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen pertama list lama di-dealokasi */
void deleteLast(List *l, ElType * val){
    if(NEXT(FIRST(*l)) == FIRST(*l)){
        *val = INFO(FIRST(*l));
        FIRST(*l) = NULL;
        return;
    }
    Address now, last, bfrlast;
    now = allocate(val);
    last = FIRST(*l);
    bfrlast = NULL;
    while(NEXT(last) != FIRST(*l)){
        bfrlast = last;
        last = NEXT(last);
    }
    *val = INFO(last);
    NEXT(bfrlast) = FIRST(*l);
}
/* I.S. List l tidak kosong */
/* F.S. val adalah elemen terakhir list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      Last element baru adalah predesesor elemen terakhir yg lama, jika ada */
/*      Jika list baru tidak kosong, Last element baru menunjuk ke First element */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen terakhir list lama di-dealokasi */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
    Address last;
    last = FIRST(l);
    printf("[");
    while(NEXT(last) != FIRST(l)){
        printf("%d,", INFO(last));
        last = NEXT(last);
    }
    printf("%d]", INFO(last));
}
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
