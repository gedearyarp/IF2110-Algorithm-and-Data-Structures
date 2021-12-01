#include "garis.h"
#include <stdio.h>

void MakeGARIS (POINT P1, POINT P2, GARIS * L){
	PAwal(*L)=P1;
	PAkhir(*L)=P2;
}

void BacaGARIS (GARIS * L){
	POINT A, B;
	while(true){
		BacaPOINT(&A);
		BacaPOINT(&B);
		if(NEQ(A,B)) break;
		printf("Garis tidak valid\n");
	}
	MakeGARIS(A, B, L);
}

void TulisGARIS (GARIS L){
	printf("(");
	TulisPOINT(PAwal(L));
	printf(",");
	TulisPOINT(PAkhir(L));
	printf(")");
	
}

float PanjangGARIS (GARIS L){
	return Panjang(PAwal(L), PAkhir(L));
	/* Menghitung panjang garis L : sqrt(x*x+y*y) */
}

float Gradien (GARIS L){
	return (Ordinat(PAkhir(L))-Ordinat(PAwal(L)))/(Absis(PAkhir(L))-Absis(PAwal(L)));
}

void GeserGARIS (GARIS * L, float deltaX, float deltaY){
	Geser (&PAwal(*L), deltaX, deltaY);
	Geser (&PAkhir(*L), deltaX, deltaY);
}

boolean IsTegakLurus (GARIS L1, GARIS L2){
	return Gradien(L1)*Gradien(L2)==-1 ? true : false;
}

boolean IsSejajar (GARIS L1, GARIS L2){
	return Gradien(L1)==Gradien(L2) ? true : false;
}

