#include <stdio.h>
#include <math.h>
#include "point.h"

POINT MakePOINT (float X, float Y){
	POINT p;
	Absis(p)=X;
	Ordinat(p)=Y;
	return p;
}
                                              
void BacaPOINT (POINT * P){
	float x, y;
	scanf("%f %f", &x, &y);
	*P = MakePOINT(x, y);
}

void TulisPOINT (POINT P){
	printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ (POINT P1, POINT P2){
	return Absis(P1)==Absis(P2) && Ordinat(P1)==Ordinat(P2);
}

boolean NEQ (POINT P1, POINT P2){
	return Absis(P1)!=Absis(P2) || Ordinat(P1)!=Ordinat(P2);
}

boolean IsOrigin (POINT P){
	return Absis(P)==0 && Ordinat(P)==0;
}

boolean IsOnSbX (POINT P){
	return Ordinat(P)==0;
}

boolean IsOnSbY (POINT P){
	return Absis(P)==0;
}

int Kuadran (POINT P){
	float x=Absis(P), y=Ordinat(P);
	if(x>0 && y>0) return 1;
	if(x<0 && y>0) return 2;
	if(x<0 && y<0) return 3;
	if(x>0 && y<0) return 4;
}
                        
POINT NextX (POINT P){
	return MakePOINT(Absis(P)+1, Ordinat(P));
}

POINT NextY (POINT P){
	return MakePOINT(Absis(P), Ordinat(P)+1);
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
	return MakePOINT(Absis(P)+deltaX, Ordinat(P)+deltaY);
}

POINT MirrorOf (POINT P, boolean SbX){
	if(SbX) return MakePOINT(Absis(P), -Ordinat(P));
	return MakePOINT(-Absis(P), Ordinat(P));
}

float Jarak0 (POINT P){
	return sqrt(Absis(P)*Absis(P)+Ordinat(P)*Ordinat(P));
}

float Panjang (POINT P1, POINT P2){
	float deltaX=abs(Absis(P2)-Absis(P1)), deltaY=abs(Ordinat(P2)-Ordinat(P1));
	return sqrt(deltaX*deltaX+deltaY*deltaY);
}

void Geser (POINT *P, float deltaX, float deltaY){
	Absis(*P)+=deltaX;
	Ordinat(*P)+=deltaY;
}

void GeserKeSbX (POINT *P){
	Ordinat(*P)=0;
}

void GeserKeSbY (POINT *P){
	Absis(*P)=0;
}

void Mirror (POINT *P, boolean SbX){
	if (SbX) Ordinat(*P)*=-1;
	else Absis(*P)*=-1;
}

void Putar (POINT *P, float Sudut){
	float x, y;
	Sudut=-Sudut;
	x=Absis(*P);
	y=Ordinat(*P);
	Absis(*P) = x*cos(Sudut*M_PI/180) - y*sin(Sudut*M_PI/180);
	Ordinat(*P) = x*sin(Sudut*M_PI/180) + y*cos(Sudut*M_PI/180);
}

