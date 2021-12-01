#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"

boolean endWord;
Word currentWord;

void ignoreBlank(){
    while (currentChar==BLANK)adv();
}

void startWord(){
    start();
    ignoreBlank();
    if (currentChar==MARK)endWord=true;
    else{
        endWord=false;copyWord();
    }
}

void advWord(){
    ignoreBlank();
    if (currentChar==MARK)endWord=true;
    else{
        copyWord();
        ignoreBlank();
    }
}

void copyWord(){
    int i=0;
    while(currentChar!=MARK && currentChar!=BLANK){
        currentWord.contents[i]=currentChar;adv();i++;
    }
    currentWord.length=(i>CAPACITY) ? CAPACITY : i;
}

