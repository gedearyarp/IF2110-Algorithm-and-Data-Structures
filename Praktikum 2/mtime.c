#include "time.h"
#include <stdio.h>

int main(){
	int tc, t; scanf("%d", &tc);
	t=tc;
	TIME maks, mins;
	while(tc--){
		printf("[%d]\n", (t-tc));
		TIME a, b;
		BacaTIME(&a);
		BacaTIME(&b);
		TIMEToDetik(a)>TIMEToDetik(b) ? printf("%li\n", Durasi(b, a)) : printf("%li\n", Durasi(a, b));
		if(tc+1==t){
			if(TIMEToDetik(a)>TIMEToDetik(b)){
				mins=b;maks=a;
			}
			else{
				mins=a;maks=b;
			}
		} 
		else{
			TIME currmins, currmaks;
			if(TLT(b, a)){
				currmins=b;currmaks=a;
			}
			else{
				currmins=a;currmaks=b;
			}
			if(TLT(currmins, mins)) mins=currmins;
			if(TLT(maks, currmaks)) maks=currmaks;
		}
	}
	TulisTIME(mins);
	printf("\n");
	TulisTIME(maks);
}
