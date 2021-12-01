#include "boolean.h"
#include "node.h"
#include "list_linked.h"
#include <stdio.h>

void CreateList(List *l){
	*l = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
	return (l == NULL);
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
	List cur = l;
	for(int i=0;i<idx;i++){
		cur = NEXT(cur);
	}
	return (INFO(cur));
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, ElType val){
	List cur = *l;
	for(int i=0;i<idx;i++){
		cur = NEXT(cur);
	}
	INFO(cur) = val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val){
	int idx = 0;
	List cur = l;
	if (isEmpty(l)) return IDX_UNDEF;
	while(true){
		if(INFO(cur) == val) return idx;
		if(NEXT(cur) == NULL) break;
		idx++;
		cur = NEXT(cur);
	}
	return (IDX_UNDEF);
}
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
	List cur = newNode(val);
	NEXT(cur) = *l;
	*l = cur;
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, ElType val){
	List apd = newNode(val);
	List cur = *l;
	if (isEmpty(*l)){
		*l = apd;
	}
	else{
		while(NEXT(cur) != NULL){
			cur = NEXT(cur);
		}
		NEXT(cur) = apd;
	}
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, ElType val, int idx){
	List cur, loc;
    int id;
    if (idx == 0) {
        insertFirst(l, val);
    } else {
        cur = newNode(val);
        if (cur != NULL) {
            id = 0;
            loc = FIRST(*l);
            while (id < idx - 1) {
                id++;
                loc = NEXT(loc);
            }
            NEXT(cur) = NEXT(loc);
            NEXT(loc) = cur;
        }
    }
}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
	*val = INFO(*l);
	*l = NEXT(*l);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val){
	List cur = *l;
	if (NEXT(cur) == NULL){
		*val = INFO(*l);
		*l = NULL;
	}
	else{
		while(NEXT(NEXT(cur)) != NULL){
			cur = NEXT(cur);
		}
		*val = INFO(NEXT(cur));
		NEXT(cur) = NULL;
	}
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val){
	if(idx == 0){
		*val = INFO(*l);
		*l = NEXT(*l);
	}
	else{
		int id = 0;
		List cur = *l, now;
		while(id+1 != idx){
			cur = NEXT(cur);
			id++;
		}
		now = NEXT(cur);
		*val = INFO(now);
		NEXT(cur) = NEXT(now);
	}
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
	printf("[");
	if (!isEmpty(l)){
		while(true){
			printf("%d", INFO(l));
			if(NEXT(l) == NULL) break;
			printf(",");
			l = NEXT(l);
		}
	}
	printf("]");
}
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l){
	if(isEmpty(l)) return 0;
	int ans=0;
	while(l != NULL){
		ans++;
		l = NEXT(l);
	}
	return ans;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2){
    List l, cur;
    CreateList(&l);
    cur = l1;
    while (cur != NULL) {
        insertLast(&l, INFO(cur));
        cur = NEXT(cur);
    }
    cur = l2;
    while (cur != NULL) {
        insertLast(&l, INFO(cur));
        cur = NEXT(cur);
    }
    return l;
}
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */

