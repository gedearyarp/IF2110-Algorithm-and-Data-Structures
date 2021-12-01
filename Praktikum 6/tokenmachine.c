#include "boolean.h"
#include "charmachine.h"
#include "tokenmachine.h"
#include <stdio.h>

boolean endToken;
Token currentToken;

void ignoreBlank(){
	while (currentChar == BLANK && currentChar != MARK) adv();
}

void startToken(){
	start(); ignoreBlank();
	if (currentChar == MARK) endToken= true;
	else{
		endToken= false;
		ignoreBlank();
	}
}

void advToken(){
	ignoreBlank();
	if(currentChar==MARK) endToken = true;
	else{
		salinToken();
		ignoreBlank();
	}
}

void salinToken(){
	int i=0;
	currentToken.val=0;
	while(currentChar != BLANK && currentChar!=MARK && i<CAPACITY){
		if(currentChar - '0'>=0 && currentChar-'0' <=9){
			currentToken.val=currentToken.val*10+(currentChar-'0');
			currentToken.tkn='b';
		}
		else{
			currentToken.val=-1;
			currentToken.tkn=currentChar;
		}
		adv();i++;
	}
}


