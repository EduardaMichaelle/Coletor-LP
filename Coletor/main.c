#include <stdio.h>
#include <stdlib.h>
#include "contref\contref.h"

int main()
{
    int *v=malloc2(sizeof(int));
    *v=10;
    int *w=malloc2(sizeof(int));
    *w=20;
    atrib2(&v,w);
    char *c=malloc2(sizeof(char));
    *c='z';
    atrib2(&w,NULL);
    printRefList();
    clearAll();
    return 0;
}
