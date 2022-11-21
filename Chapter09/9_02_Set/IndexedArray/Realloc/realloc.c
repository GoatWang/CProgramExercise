#include "specific.h"
#include "../arr.h"

/* Creates the empty array */
arr* arr_init(void)
{
    arr* l = (arr*) ncalloc(1, sizeof(arr));
    l->a = ncalloc(FIXEDSIZE, sizeof(colltype));
    l->capacity = FIXEDSIZE;
    l->size = 0;
   return l;
}

/* Similar to l[n] = i, safely resizing if required */
void arr_set(arr *l, int n, int i)
{
    while (l->capacity < n+1){
        l->a = (colltype*) nrecalloc(l->a, l->capacity, l->capacity*SCALEFACTOR);
        l->capacity = l->capacity*SCALEFACTOR;
    }

    if (l->size < n+1){
        l->a[n] = i;
        l->size = n+1;
    }
}

/* Similar to = l[n] */
int arr_get(arr *l, int n)
{
    return l->a[n];
}

/* Clears all space used, and sets pointer to NULL */
void arr_free(arr **l)
{
    free((*l)->a);
    free((*l));
    (*l)->a = NULL;
    (*l) = NULL;
}

