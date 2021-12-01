#include <stdio.h>
#include "wordmachine.h"

boolean endWord;
Word currentWord;

int main() {
    startWord();
    int i=0,n=currentWord.length;
    while (!endWord) {
        for(i=0;i<currentWord.length;i++)printf("%c",(currentWord.contents[i]-'A'+n)%26+'A');
        if(currentChar == MARK)printf("%c\n", MARK);
        else printf("%c", BLANK); advWord();
    }
}
