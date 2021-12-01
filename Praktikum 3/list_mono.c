#include <stdio.h>
#include "boolean.h"
#include "listpos.h"

int main(){
	ListPos l, ldown, lup;
    readList(&l);
    ldown=l;lup=l;
    sort(&lup, true);
    sort(&ldown, false);
    if(isListEqual(ldown,lup)) printf("Static Monotonic List\n");
    else if (isListEqual(l,lup)) printf("Non-descending Monotonic List\n");
	else if (isListEqual(l,ldown)) printf("Non-ascending Monotonic List\n");
	else printf("Non-monotonic List\n");
}
