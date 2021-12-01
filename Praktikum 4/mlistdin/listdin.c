#include "listdin.h"
#include <stdio.h>

void CreateListDin(ListDin *l, int capacity){
	NEFF(*l)=0;
	CAPACITY(*l)=capacity;
	BUFFER(*l)=(int *) malloc(capacity * sizeof(int));
	int i;
	for(i=0;i<capacity;i++){
		ELMT(*l, i)=0;
	}
}

void dealocate(ListDin *l){
	free(BUFFER(*l));
	NEFF(*l)=0;
	CAPACITY(*l)=0;
}

int length(ListDin l){
	return NEFF(l);
}

IdxType getLastIdx(ListDin l){
	return NEFF(l)-1;
}

boolean isIdxValid(ListDin l, int i){
	return (i>=0 && i < CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i){
	return (i>=0 && i < NEFF(l));
}

boolean isEmpty(ListDin l){
	return (NEFF(l)==0);
}

boolean isFull(ListDin l){
	return (NEFF(l)==CAPACITY(l));
}

void readList(ListDin *l){
	int n, i;
	while(scanf("%d", &n))if(n>=0 && n<=CAPACITY(*l)) break;
	NEFF(*l)=n;
	for(i=0;i<n;i++)scanf("%d", &ELMT(*l, i));
}

void displayList(ListDin l){
	printf("[");
	int i;
	for(i=0;i<NEFF(l);i++){
		printf("%d", ELMT(l, i));
		if(i!=NEFF(l)-1) printf(",");
	}
	printf("]");
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
	ListDin lTot;
	CreateListDin(&lTot, CAPACITY(l2));
	NEFF(lTot)=NEFF(l1);
	int i;
	for(i=0;i<NEFF(lTot);i++){
		ELMT(lTot, i)=ELMT(l1, i)+ELMT(l2, i)*(plus ? 1 : -1);
	}
	return lTot;
}

boolean isListEqual(ListDin l1, ListDin l2){
	if (NEFF(l1)==NEFF(l2)){
		int i;
		for(i=0;i<NEFF(l1);i++)if(ELMT(l1,i)!=ELMT(l2,i)) return false;
		return true;
	}
	return false;
}

IdxType indexOf(ListDin l, ElType val){
	int i;
	for(i=0;i<NEFF(l);i++)if(ELMT(l, i)==val) return i;
	return IDX_UNDEF;
}

void extremes(ListDin l, ElType *max, ElType *min){
	int pjg = length(l), mx=ELMT(l,0), mn=ELMT(l,0), i;
	for(i=0;i<pjg;i++){
		if(ELMT(l,i)>mx) mx=ELMT(l,i);
		if(ELMT(l,i)<mn) mn=ELMT(l,i);
	}
	*max=mx;
	*min=mn;
}

void copyList(ListDin lIn, ListDin *lOut){
	dealocate(lOut);int i;
	CreateListDin(lOut, CAPACITY(lIn));
	NEFF(*lOut) = NEFF(lIn);
	for (i=0;i<length(lIn);i++)ELMT(*lOut, i)=ELMT(lIn, i);
}

ElType sumList(ListDin l){
	int i, sum=0;
	for(i=0;i<length(l);i++)sum+=ELMT(l, i);
	return sum;
}

int countVal(ListDin l, ElType val){
	int i, cnt=0;
	for(i=0;i<length(l);i++)if(ELMT(l,i)==val) cnt++;
	return cnt;
}

boolean isAllEven(ListDin l){
	int i;
	for(i=0;i<length(l);i++)if(ELMT(l, i)%2!=0) return false;
	return true;
}

void sort(ListDin *l, boolean asc){
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

void insertLast(ListDin *l, ElType val){
	ELMT(*l, length(*l)) = val;
	NEFF(*l)++;
}

void deleteLast(ListDin *l, ElType *val){
	*val=ELMT(*l, length(*l)-1);
	NEFF(*l)--;
}

void growList(ListDin *l, int num){
	ListDin lNew;int i;
	CreateListDin(&lNew, CAPACITY(*l)+num);
	NEFF(lNew)=NEFF(*l);
	for(i=0;i<CAPACITY(*l);i++) ELMT(lNew, i)=ELMT(*l, i);
	for(i=CAPACITY(*l);i<CAPACITY(lNew);i++)ELMT(lNew, i)=0;
	dealocate(l);
	*l=lNew;
}

void shrinkList(ListDin *l, int num){
	ListDin lNew;int i;
    CreateListDin(&lNew, CAPACITY(*l));
    copyList(*l, &lNew);
    dealocate(l);
    CreateListDin(l,CAPACITY(lNew)-num);
    if (NEFF(lNew)>CAPACITY(lNew)-num)NEFF(*l)=CAPACITY(lNew)-num;
    else NEFF(*l) = NEFF(lNew);
    for (i=0;i<NEFF(*l);i++)ELMT(*l, i)=ELMT(lNew, i);
}

void compactList(ListDin *l){
	ListDin lNew;int i;
	CreateListDin(&lNew, NEFF(*l));
	NEFF(lNew)=NEFF(*l);
	for(i=0;i<CAPACITY(lNew);i++)ELMT(lNew, i)=ELMT(*l, i);
	dealocate(l);
	*l=lNew;
}

