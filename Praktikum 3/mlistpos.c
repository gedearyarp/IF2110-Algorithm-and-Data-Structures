#include <stdio.h>
#include "boolean.h"
#include "listpos.h"

int main(){
	ListPos l;int n, pjg, ind;
	readList(&l);
	scanf("%d", &n);
	pjg=length(l);
	ind = indexOf(l, n);
	displayList(l);
	printf("\n");
	if(ind==IDX_UNDEF) printf("%d tidak ada\n", n);
	else{
		printf("%d\n", ind);
		int med, maxx, minn;
		extremes(l, &maxx, &minn);
		sort(&l, true);
		if(pjg%2) med=ELMT(l, pjg/2);
		else med=ELMT(l, (pjg-1)/2);
		if(n==maxx) printf("maksimum\n");
		if(n==minn) printf("minimum\n");
		if(n==med) printf("median\n");
	}
}
