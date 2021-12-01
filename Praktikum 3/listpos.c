#include <stdio.h>
#include "listpos.h"

void CreateListPos(ListPos *l){
	int i;
	for(i=0;i<CAPACITY;i++) {
		ELMT(*l, i) = VAL_UNDEF;
	}
}

int length(ListPos l){
	int length=0, i=0;
	while(i!=CAPACITY && ELMT(l, i)!=VAL_UNDEF){
		length++;i++;
	}
	return length;
}

boolean isIdxValid(ListPos l, int i){
	return(i>=0 && i < CAPACITY);
}

boolean isIdxEff(ListPos l, int i){
    return(i >= 0 && i < length(l));
}

boolean isEmpty(ListPos l){
	return(length(l) == 0);
}

boolean isFull(ListPos l){
	return(length(l) == CAPACITY);
}

void readList(ListPos *l){
	CreateListPos(l);
	int n, inp, i;
	while(scanf("%d", &n)) if(0<=n && n<=CAPACITY) break;
	for(i=0;i<n;i++){
		scanf("%d", &inp);
		ELMT(*l, i)=inp;
	}
}

void displayList(ListPos l){
	printf("[");
	int pjg = length(l), i;
	for(i=0;i<pjg;i++){
        printf("%d", ELMT(l, i));
        if(i != pjg - 1){
        	printf(",");
      	}
    }
	printf("]");
}

ListPos plusMinusTab(ListPos l1, ListPos l2, boolean plus){
	ListPos ans;
	CreateListPos(&ans);
	int pjg = length(l1), i;
	if(plus){
		for(i=0;i<pjg;i++){
			ELMT(ans,i)=ELMT(l1,i)+ELMT(l2,i);
		}
	}
	else{
		for(i=0;i<pjg;i++){
			ELMT(ans,i)=ELMT(l1,i)-ELMT(l2,i);
		}
	}
	return ans;
}

boolean isListEqual(ListPos l1, ListPos l2){
	int i;
	for(i=0;i<CAPACITY;i++) if (ELMT(l1,i)!=ELMT(l2,i)) return false;
	return true;
}

int indexOf(ListPos l, ElType val){
	int i;
	for(i=0;i<CAPACITY;i++){
		if (ELMT(l,i)==val) return i;
	}
	return IDX_UNDEF;
}

void extremes(ListPos l, ElType *max, ElType *min){
	int pjg = length(l), mx=ELMT(l,0), mn=ELMT(l,0), i;
	for(i=0;i<pjg;i++){
		if(ELMT(l,i)>mx) mx=ELMT(l,i);
		if(ELMT(l,i)<mn) mn=ELMT(l,i);
	}
	*max=mx;
	*min=mn;
}

boolean isAllEven(ListPos l){
	int pjg = length(l), i;
	for(i=0;i<pjg;i++)if(ELMT(l,i)%2) return false;
	return true;
}

void sort(ListPos *l, boolean asc){
	if(!isEmpty(*l)){
		int idx=length(*l)-1, temp, i;
		boolean sorted=false;
		while (!sorted){
			sorted=true;
			for(i=0;i<idx;i++){
				if(asc){
					if(ELMT(*l,i)>ELMT(*l,i+1)){
						sorted=false;
						temp=ELMT(*l,i);
						ELMT(*l,i)=ELMT(*l,i+1);
						ELMT(*l,i+1)=temp;
					}
				}
				else{
					if(ELMT(*l,i)<ELMT(*l,i+1)){
						sorted=false;
						temp=ELMT(*l,i);
						ELMT(*l,i)=ELMT(*l,i+1);
						ELMT(*l,i+1)=temp;
					}
				}
				
			}
			idx--;
		}
	}
}

void insertLast(ListPos *l, ElType val){
	ELMT(*l, length(*l)) = val;
}

void deleteLast(ListPos *l, ElType *val){
	*val = ELMT(*l, length(*l) - 1);
    ELMT(*l, length(*l) - 1) = VAL_UNDEF;
}

