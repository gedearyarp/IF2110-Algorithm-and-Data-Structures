#include <stdio.h>
#include "list_linked.h"

int main(){
  List l;
  CreateList(&l);
  int n, tc;
  scanf("%d %d", &n, &tc);
  for(int i = 1; i <= n; i++) insertLast(&l, i);
  while(tc--){
    int src, id, tmp;
    scanf("%d", &src);
    id = indexOf(l, src);
    if(id == IDX_UNDEF){
      deleteLast(&l, &tmp);
      insertFirst(&l, src);
      printf("miss ");
    }
	else{
      deleteAt(&l, id, &tmp);
      insertFirst(&l, src);
      printf("hit ");
    }
    displayList(l);
    printf("\n");
  }
}
