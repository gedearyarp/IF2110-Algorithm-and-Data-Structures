#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
#include "listdin.h"

int main(){
	ListDin L;
	int capacity, Q, op, num, i;
	scanf("%d", &capacity);
	CreateListDin(&L, capacity);
	readList(&L);
	scanf("%d", &Q);
	for(i=0;i<Q;i++){
		scanf("%d", &op);
		if (op==1){
			scanf("%d", &num);
			if(isFull(L))printf("list sudah penuh\n");
			else {
				insertLast(&L, num);
				printf("%d ", CAPACITY(L));
				displayList(L); printf("\n");
			}
		}
		else if (op==2){
			scanf("%d", &num);
			growList(&L, num);
			printf("%d ", CAPACITY(L));
			displayList(L); printf("\n");
		} 
		else if (op==3){
			scanf("%d", &num);
			if(num > CAPACITY(L)) printf("list terlalu kecil");
			else{
				shrinkList(&L, num);
				printf("%d ", CAPACITY(L));
				displayList(L); printf("\n");
			}
		}
		else {
			compactList(&L);
			printf("%d ", CAPACITY(L));
			displayList(L); printf("\n");
		}
	}
}
