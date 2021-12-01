#include "point.h"
#include "point.c"
#include <stdio.h>

int main(){
	POINT P1, P2, P;
	printf("Input P1(x,y): ");
	BacaPOINT(&P1);
	printf("Output TulisPOINT: ");
	TulisPOINT(P1);
	printf("\nInput P2(x,y): ");
	BacaPOINT(&P2);
	EQ(P1,P2) ? printf("Hasil EQ P1 dan P2: true\n") : printf("Hasil EQ P1 dan P2: false\n");
	NEQ(P1,P2) ? printf("Hasil NEQ P1 dan P2: true\n") : printf("Hasil NEQ P1 dan P2: false\n");
	IsOrigin(P1) ? printf("Hasil IsOrigin P1: true\n") : printf("Hasil IsOrigin P1: false\n");
	IsOnSbX(P1) ? printf("Hasil IsOnSbX P1: true\n") : printf("Hasil IsOnSbX P1: false\n");
	IsOnSbY(P1) ? printf("Hasil IsOnSbY P1: true\n") : printf("Hasil IsOnSbY P1: false\n");
	printf("Titik P1 berada pada kuadran %d\n", Kuadran(P1));
	printf("Titik P1 setelah absis ditambah 1: ");
	TulisPOINT(NextX(P1));
	printf("\nTitik P1 setelah ordinat ditambah 1: ");
	TulisPOINT(NextY(P1));
	printf("\nTitik P1 setelah absis ditambah 5 dan ordinat ditambah 6: ");
	TulisPOINT(PlusDelta(P1, 5, 6));
	printf("\nTitik P1 setelah dicerminkan terhadap sumbu X: ");
	TulisPOINT(MirrorOf(P1, true));
	printf("\nJarak dari titik 0 ke titik P1: %.2f", Jarak0(P1));
	printf("\nJarak titik P1 dan P2: %.2f", Panjang(P1,P2));
	Geser(&P1, 5, 6);
	printf("\nHasil pergeseran P1 setelah absis ditambah 5 dan ordinat ditambah 6: ");
	TulisPOINT(P1);
	GeserKeSbX(&P1);
	printf("\nHasil pergeseran P1 ke sumbu X: ");
	TulisPOINT(P1);
	GeserKeSbY(&P1);
	printf("\nHasil pergeseran P1 ke sumbu Y: ");
	TulisPOINT(P1);
	printf("\nInput P(x,y) untuk pergeseran: ");
	BacaPOINT(&P);
	Putar(&P, 90);
	printf("Output P(x,y) setelah diputar 90 derajat: ");
	TulisPOINT(P);
}
