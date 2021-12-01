#include "stdio.h"
#include "stdlib.h"
#include "bintree.h"

void invertBtree(BinTree *p){
    if(isTreeEmpty(*p) || isOneElmt(*p)) return;
    invertBtree(&LEFT(*p));
    invertBtree(&RIGHT(*p));
    *p = NewTree(ROOT(*p), RIGHT(*p), LEFT(*p));
}