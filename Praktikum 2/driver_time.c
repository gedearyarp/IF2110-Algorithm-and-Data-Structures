#include "time.h"
#include <stdio.h>

int main(){
	TIME T, T1, T2;
	int N;
	printf("Input jam, menit, waktu (T): ");
	BacaTIME(&T);
	printf("Hasil TulisTIME: ");
	TulisTIME(T);
	printf("\nHasil TIMEToDetik %ld\n", TIMEToDetik(T));
	long dtk;
	printf("Input detik: ");
	scanf("%li", &dtk);
	printf("Hasil DetikToTIME: ");
	TulisTIME(DetikToTIME(dtk));
	printf("\nInput jam, menit, waktu (T1): ");
	BacaTIME(&T1);
	printf("Input jam, menit, waktu (T2): ");
	BacaTIME(&T2);
	TEQ(T1, T2) ? printf("Hasil TEQ: true\n") : printf("Hasil TEQ: false\n");
	TNEQ(T1, T2) ? printf("Hasil TNEQ: true\n") : printf("Hasil TNEQ: false\n");
	TLT(T1, T2) ? printf("Hasil TLT: true\n") : printf("Hasil TLT: false\n");
	TGT(T1, T2) ? printf("Hasil TGT: true\n") : printf("Hasil TGT: false\n");
	printf("Masukan Nilai N: ");
	scanf("%d", &N);
	printf("Hasil NextDetik: ");
	TulisTIME(NextDetik(T));
	printf("\nHasil NextNDetik: ");
	TulisTIME(NextNDetik(T, N));
	printf("\nHasil PrevDetik: ");
	TulisTIME(PrevDetik(T));
	printf("\nHasil PrevNDetik: ");
	TulisTIME(PrevNDetik(T, N));
	printf("\nHasil Durasi T1 & T2: %d", Durasi(T1, T2));
}
