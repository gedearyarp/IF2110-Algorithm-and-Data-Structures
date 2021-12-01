#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

/* Manajemen Memori */
Address newNode(ElType x){
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l){
    return (l == NULL);
}
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
int isOneElmt(List l){
    if(!isEmpty(l) && NEXT(l) == NULL) return true;
    return false;
}
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */

/* Primitif-Primitif Pemrosesan List */
ElType head(List l){
    return INFO(l);
}
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
List tail(List l){
    if(isEmpty(l)) return NULL;
    return NEXT(l);
}
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
List konso(List l, ElType e){
    Address p = newNode(e);
    NEXT(p) = l;
    return p;
}
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */
List konsb(List l, ElType e){
    Address p = newNode(e);
    Address now = l;
    if(now == NULL) return p;
    while(NEXT(now) != NULL){
        now = NEXT(now);
    }
    NEXT(now) = p;
    return l;
}
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 

/* Fungsi dan Prosedur Lain */
int length(List l){
    Address now = l;
    int sm=0;
    while(now != NULL){
        now = NEXT(now);
        sm++;
    }
    return sm;
}
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
void displayList(List l){
    Address now = l;
    while(now != NULL){
        printf("%d\n", INFO(now));
        now = NEXT(now);
    }
}
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */

/*** Pencarian nilai ekstrim ***/
/* Prekondisi untuk Max/Min/Sum/Average : List tidak kosong */
ElType maxList (List l){
    int ans=INFO(l);
    Address now = l;
    while(now != NULL){
        if(INFO(now) > ans) ans = INFO(now);
        now = NEXT(now);
    }
    return ans;
}
/* Mengirimkan nilai INFO(p) yang maksimum */

ElType minList (List l){
    int ans=INFO(l);
    Address now = l;
    while(now != NULL){
        if(INFO(now) < ans) ans = INFO(now);
        now = NEXT(now);
    }
    return ans;
}
/* Mengirimkan nilai INFO(p) yang minimum */

ElType sumList (List l){
    int ans=0;
    Address now = l;
    while(now != NULL){
        ans += INFO(now);
        now = NEXT(now);
    }
    return ans;
}
/* Mengirimkan total jumlah elemen List l */

float averageList (List l){
    int summ = sumList (l);
    float ans = summ;
    ans /= length(l);
    return ans;
}
/* Mengirimkan nilai rata-rata elemen list l */

/*** Operasi-Operasi Lain ***/
List inverseList (List l){
    List ans = NULL;
    Address now = l;
    while(now!=NULL){
        ans = konso(ans, INFO(now));
        now = NEXT(now);
    } 
    return ans;
}
/* Mengirimkan list baru, hasil invers dari l dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */

void splitPosNeg (List l, List *l1, List *l2){
    Address now = l;
    *l1 = NULL;
    *l2 = NULL;
    while(now!= NULL){
        if(INFO(now)>=0){
            *l1 = konsb(*l1, INFO(now));
        }
        else{
            *l2 = konsb(*l2, INFO(now));
        }
        now = NEXT(now);
    }
}
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan l, dibentuk dua buah list l1 dan l2 */ 
/* l1 berisi semua elemen l yang positif atau 0, sedangkan l2 berisi
semua elemen l yang negatif; semua dengan urutan yang sama seperti di l */
/* l tidak berubah: Semua elemen l1 dan l2 harus dialokasi */
/* Jika l kosong, maka l1 dan l2 kosong */

void splitOnX (List l, ElType x, List *l1, List *l2){
    Address now = l;
    *l1 = NULL;
    *l2 = NULL;
    while(now!= NULL){
        if(INFO(now)<x){
            konsb(*l1, INFO(now));
        }
        else{
            konsb(*l2, INFO(now));
        }
        now = NEXT(now);
    }
}
/* I.S. l dan x terdefinisi, l1 dan l2 sembarang. */
/* F.S. l1 berisi semua elemen l yang lebih kecil dari x, dengan urutan
kemunculan yang sama, l2 berisi semua elemen l yang tidak masuk ke
l1, dengan urutan kemunculan yang sama. */

int compareList (List l1, List l2){
    int a = length(l1), b = length(l2);
    if(a == b){
        Address n1=l1, n2=l2;
        while(n1 != NULL){
            if(INFO(n1) > INFO(n2)){
                return 1;
            }
            else if(INFO(n1) > INFO(n2)){
                return -1;
            }
            n1 = NEXT(n1);
            n2 = NEXT(n2);
        }
        return 0;
    }
    else if(a < b){
        Address n1=l1, n2=l2;
        while(n1 != NULL){
            if(INFO(n1) > INFO(n2)){
                return 1;
            }
            else if(INFO(n1) > INFO(n2)){
                return -1;
            }
            n1 = NEXT(n1);
            n2 = NEXT(n2);
        }
        return -1;
    }
    else{
        Address n1=l1, n2=l2;
        while(n2 != NULL){
            if(INFO(n1) > INFO(n2)){
                return 1;
            }
            else if(INFO(n1) > INFO(n2)){
                return -1;
            }
            n1 = NEXT(n1);
            n2 = NEXT(n2);
        }
        return 1;
    }
}
/* Menghasilkan: -1 jika l1 < l2, 0 jika l1 = l2, dan 1 jika l1 > l2 */
/* Jika l[i] adalah elemen l pada urutan ke-i dan |l| adalah panjang l: */
/* l1 = l2: |l1| = |l2| dan untuk semua i, l1[i] = l2[i] */
/* l1 < l2: Jika i adalah urutan elemen yang berbeda yang terkecil
dari l1 dan l2, l1[i]<l2[i] atau: Jika pada semua elemen pada
urutan i yang sama, l1[i]=l2[i], namun |l1|<|l2| */
/* Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4] */
/* l1>l2: kebalikan dari l1<l2 */

boolean isAllExist (List l1, List l2){
    Address now = l1;
    if(l1 == NULL || l2 == NULL) return false;
    while(now!=NULL){
        Address n2 = l2;
        int flag = 0;
        while(n2!=NULL){ 
            if(INFO(now) == INFO(n2)){
                flag = 1;
                break;
            }
            n2 = NEXT(n2);
        }
        if(!flag){
            return false;
            break;
        }
        now = NEXT(now);
    }
    return true;
}
/* Menghasilkan true jika semua elemen dalam l1 terdapat dalam l2 (tanpa
memperhatikan urutan ataupun banyaknya elemen).
Kedua list mungkin kosong. Jika l1 kosong, maka hasilnya false. */