#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "bintree.h"

boolean isPangkatDua(int n){
    if(n==0) return false;
    while(n%2==0){
        n/=2;
    }
    return n==1;
}

int logDua(int n){
    int ans=0;
    while(n>1){
        n/=2;
        ans++;
    }
    return ans;
}

int main(){
    int n;
    scanf("%d", &n);
    if (isPangkatDua(n)){
        int i, val, now=n;
        BinTree btr[2*n - 1];
        for (i=0; i<n; i++){
            BinTree tr;
            scanf("%d", &val);
            tr = newTreeNode(val);
            btr[i] = tr;
        }
        i = 0;
        while(now < 2*n-1){
            btr[now] = NewTree(ROOT(btr[i])+ROOT(btr[i+1]), btr[i], btr[i+1]);
            i += 2;
            now ++;
        }
        printTree(btr[2*(n-1)], 2);
    }
    else{
        printf("Jumlah masukan tidak sesuai\n");
    }
}