#include "specific.h"
#include "../set.h"
#include "../../IndexedArray/Realloc/specific.h"


/*
A Set ADT - based on an underlying arr ADT. Here:
1. No element can appear twice
2. No particular ordering of elements is implied
*/

/* Create empty set */
set* set_init(void)
{
    set* s = (set*) ncalloc(1, sizeof(set));
    s->a = arr_init();
    return s;
}

/* Create new set, copied from another */
set* set_copy(set* s)
{
    set* s_new = set_init();
    for (int i=0; i<s->a->size; i++){
        arr_set(s_new->a, i, s->a->a[i]);
    }
    return s_new;
}

/* Create new set, copied from an array of length n*/
set* set_fromarray(int* a, int n){
    set* s = set_init();
    if (a != NULL){
        for (int i=0; i<n; i++){
            set_insert(s, a[i]);
        }
    }
    return s;
}

/* Basic Operations */
/* Add one element into the set */
void set_insert(set* s, int l)
{
    if (s != NULL){
        if (!set_contains(s, l)){
            arr_set(s->a, set_size(s), l);
        }
    }
}

/* Return size of the set */
int set_size(set* s)
{
    if (s == NULL){
        return 0;
    }
    return s->a->size;
}

/* Returns true if l is in the array, false elsewise */
int set_contains(set* s, int l)
{
    bool contains = false;
    for (int i=0; i<set_size(s); i++){
        if (s->a->a[i] == l){
            contains = true;
        }
    }
    return contains;
}

/* Remove l from the set (if it's in) */
void set_remove(set* s, int l)
{
    if (set_contains(s, l)){
        int cursor = 0;
        while (l != s->a->a[cursor]){
            cursor += 1;
        }
        while (cursor < set_size(s)-1){
            s->a->a[cursor] = s->a->a[cursor+1];  
            cursor += 1;
        }
    }
}

/* Remove one element from the set - there's no
   particular order for the elements, so any will do */
int set_removeone(set* s)
{
    s->a->size = set_size(s) - 1;
    return s->a->a[set_size(s)];
}

/* Operations on 2 sets */
/* Create a new set, containing all elements from s1 & s2 */
set* set_union(set* s1, set* s2)
{  
    set* s_out = set_init();
    for (int i=0; i<set_size(s1); i++){
        set_insert(s_out, s1->a->a[i]);
    }
    for (int j=0; j<set_size(s2); j++){
        set_insert(s_out, s2->a->a[j]);
    }
    return s_out;
}

/* Create a new set, containing all elements in both s1 & s2 */
set* set_intersection(set* s1, set* s2)
{
    set* s_out = set_init();
    for (int i=0; i<set_size(s1); i++){
        if (set_contains(s2, s1->a->a[i])){
                set_insert(s_out, s1->a->a[i]);
        }
    }
    return s_out;
}

/* Finish up */
/* Clears all space used, and sets pointer to NULL */
void set_free(set** s)
{
    if (s !=NULL){
        arr_free(&(*s)->a);
        free(*s);
        *s = NULL;
    }
}

