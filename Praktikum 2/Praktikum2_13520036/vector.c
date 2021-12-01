#include "vector.h"
#include <stdio.h>

VECTOR MakeVector(float x, float y){
	VECTOR V;
	AbsisComponent(V)=x;
	OrdinatComponent(V)=y;
	return V;
}

void TulisVector(VECTOR v){
	printf("<%.2f,%.2f>", AbsisComponent(v), OrdinatComponent(v));
}

float Magnitude(VECTOR v){
	return Jarak0(v);
}

VECTOR Add(VECTOR a, VECTOR b){
	VECTOR V;
	AbsisComponent(V)=AbsisComponent(a)+AbsisComponent(b);
	OrdinatComponent(V)=OrdinatComponent(a)+OrdinatComponent(b);
	return V;
}

VECTOR Substract(VECTOR a, VECTOR b){
	VECTOR V;
	AbsisComponent(V)=AbsisComponent(a)-AbsisComponent(b);
	OrdinatComponent(V)=OrdinatComponent(a)-OrdinatComponent(b);
	return V;
}

float Dot(VECTOR a, VECTOR b){
	return (AbsisComponent(a)*AbsisComponent(b)+OrdinatComponent(a)*OrdinatComponent(b));
}

VECTOR Multiply(VECTOR v, float s){
	AbsisComponent(v)*=s;
	OrdinatComponent(v)*=s;
	return v;
}

