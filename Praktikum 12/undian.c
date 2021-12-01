#include<stdio.h>
#include<stdlib.h>
#include"listrec.h"

List splitOddIndex(List l){
    List ans = NULL;
    Address now = l;
    int cnt = 1;
    while(now != NULL){
        if(cnt%2 == 1){
            ans = konsb(ans, INFO(now));
        }
        cnt++;
        now = NEXT(now);
    }
    return ans;
}
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada indeks
ganjil pada list L, sesuai dengan urutannya. Elemen HEAD merupakan indeks 1.
Jika tidak ada elemen yang bisa diambil, kembalikan NULL */

List splitEvenIndex(List l){
    List ans = NULL;
    Address now = l;
    int cnt = 1;
    while(now != NULL){
        if(cnt%2 == 0){
            ans = konsb(ans, INFO(now));
        }
        cnt++;
        now = NEXT(now);
    }
    return ans;
}
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada indeks
genap pada list L, sesuai dengan urutannya. Elemen HEAD merupakan indeks 1.
Jika tidak ada elemen yang bisa diambil, kembalikan NULL */

List splitBeforeX(List l, ElType x){
    List ans = NULL;
    Address now = l;
    while(now != NULL && INFO(now) != x){
        ans = konsb(ans, INFO(now));
        now = NEXT(now);
    }
    return ans;
}
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen di depan elemen
dengan nilai x pada list l, sesuai dengan urutannya. Jika x tidak ada pada list, maka
kembalikan list l.
Jika tidak ada elemen yang bisa diambil, kembalikan NULL */

List reverseList(List l){
    List ans = NULL;
    Address now = l;
    while(now!=NULL){
        ans = konso(ans, INFO(now));
        now = NEXT(now);
    } 
    return ans;
}
/* Mengembalikan sebuah list baru yang urutannya merupakan kebalikan dari list l.
Jika l kosong, kembalikan list kosong. */

int main(){
    List ans=NULL;
    while(true){
        char op;
        scanf("%c", &op);
        if (op =='F'){
            int val; scanf("%d", &val);
            ans = konso(ans, val);
 
        }
        else if (op =='B'){
            int val; scanf("%d", &val);
            ans = konsb(ans, val);
    
        }
        else if (op == 'O'){
            ans = splitOddIndex(ans);
 
        }
        else if (op == 'E'){
            ans = splitEvenIndex(ans);

        }
        else if(op == 'R'){
            ans = reverseList(ans);

        }
        else if(op == 'P'){
            int val; scanf("%d", &val);
            ans = splitBeforeX(ans, val);

        }
        else if(op == 'X'){
            break;
        }
    }
    if(isEmpty(ans)){
        printf("Semua gugur\n");
    }
    else{
        displayList(ans);
    }
}