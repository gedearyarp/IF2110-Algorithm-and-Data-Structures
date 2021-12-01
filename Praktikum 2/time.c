#include "time.h"
#include <stdio.h>

boolean IsTIMEValid (int H, int M, int S){
	return H>=0 && H<=23 && M>=0 && M<=59 && S>=0 && S<=59;
}

TIME MakeTIME (int HH, int MM, int SS){
	TIME t;
	Hour(t)=HH;
	Minute(t)=MM;
	Second(t)=SS;
	return t;
}

void BacaTIME (TIME * T){
	int h, m, s;
	while(true){
		scanf("%d %d %d", &h, &m, &s);
		if (IsTIMEValid(h, m, s)) break;
		printf("Jam tidak valid\n");
	}
	*T = MakeTIME(h, m, s);
}
   
void TulisTIME (TIME T){
	printf("%02d:%02d:%02d", Hour(T), Minute(T), Second(T));
}

long TIMEToDetik (TIME T){
	long TimeInSecond = Hour(T)*3600 + Minute(T)*60 + Second(T);
	return TimeInSecond;
}

TIME DetikToTIME (long N){
	TIME t;
	long dv=abs(N/86400);
	if(N<0) N+=86400*(dv+1);
	N%=86400;
	Hour(t) = N/3600;
	N%=3600;
	Minute(t) = N/60;
	N%=60;
	Second(t) = N;
	return t;
}

boolean TEQ (TIME T1, TIME T2){
	return TIMEToDetik(T1) == TIMEToDetik(T2);
}

boolean TNEQ (TIME T1, TIME T2){
	return TIMEToDetik(T1) != TIMEToDetik(T2);
}

boolean TLT (TIME T1, TIME T2){
	return TIMEToDetik(T1) < TIMEToDetik(T2);
}

boolean TGT (TIME T1, TIME T2){
	return TIMEToDetik(T1) > TIMEToDetik(T2);
}

TIME NextDetik (TIME T){
	long prev=TIMEToDetik(T), now;
	now = prev+1;
	return DetikToTIME(now);
}

TIME NextNDetik (TIME T, int N){
	long prev=TIMEToDetik(T), now;
	now = prev+N;
	return DetikToTIME(now);
}

TIME PrevDetik (TIME T){
	long prev=TIMEToDetik(T), now;
	now = prev-1;
	return DetikToTIME(now);
}

TIME PrevNDetik (TIME T, int N){
	long prev=TIMEToDetik(T), now;
	now = prev-N;
	return DetikToTIME(now);
}

long Durasi (TIME TAw, TIME TAkh){
	long awal=TIMEToDetik(TAw), akhir=TIMEToDetik(TAkh);
	if(akhir<awal)return akhir-awal+86400;
	return (akhir-awal);
}

