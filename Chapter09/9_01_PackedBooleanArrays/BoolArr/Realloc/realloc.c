#include "specific.h"
#include "../boolarr.h"

/* All elements initialised to "0" */
boolarr* boolarr_init(void)
{
    boolarr* ba = (boolarr*) ncalloc(1, sizeof(boolarr));
    ba->a = (colltype*) ncalloc(FIXEDSIZE, sizeof(colltype));
    memset(ba->a, '0', FIXEDSIZE);
    ba->size = 0;
    ba->capacity = FIXEDSIZE;
    return ba;
}

/* Create boolarr based on string e.g. "1100001" */
boolarr* boolarr_initstr(const char* str)
{
    boolarr* ba = boolarr_init();
    int length = strlen(str);
    memcpy(ba->a, (colltype*) str, length);
    ba->size = length;
    ba->capacity = FIXEDSIZE;
    return ba;
}

/* Return a deep copy */
boolarr* boolarr_clone(const boolarr* ba)
{
    boolarr* ba_new = (boolarr*) ncalloc(1, sizeof(boolarr));
    ba_new->a = (colltype*) nrecalloc(ba_new->a, ba_new->capacity, ba->capacity);
    memset(ba_new->a, '0', ba_new->capacity);
    ba_new->size = ba->size;
    ba_new->capacity = ba->size;
    memcpy(ba_new->a, (colltype*) ba->a, (int)ba_new->capacity);
    return ba_new;
}

/* Get number of bits in array */
unsigned int boolarr_size(const boolarr* ba)
{
    if(ba==NULL){
        return 0;
    }
    return ba->size;
}

/* Return number of bits that are set true */
unsigned int boolarr_count1s(const boolarr* ba)
{
    int cnt = 0;
    for (int i=0; i<(int)boolarr_size(ba); i++){
        if (ba->a[i] == '1'){
            cnt += 1;
        }
    }
    return cnt;
}

/* Set nth bit on/off */
bool boolarr_set(boolarr* ba, const unsigned int n, const bool b){
    if(ba==NULL){
        return false;
    }

    while (ba->capacity < (int)n+1){
        int length = boolarr_size(ba);
        int new_capacity = ba->capacity*SCALEFACTOR;
        ba->a = (colltype*) nrecalloc(ba->a, ba->capacity, new_capacity);
        memset(ba->a+length, '0', new_capacity-length);
        ba->capacity = new_capacity;
    }

    if (b == true){
        ba->a[n] = '1';
    }
    else{
        ba->a[n] = '0';
    }

    // TODO
    if (boolarr_size(ba) < n+1){
        ba->size = n+1;
    }

    return true;
}

/* Get nth bit */
bool boolarr_get(const boolarr* ba, const unsigned int n, bool* b)
{   
    if (ba == NULL){
        return false;
    }
    if (ba->a[n] == '1'){
        *b = true;        
    }
    else{
        *b = false;
    }
    return true;
}

/* Return if two arrays are the same (bitwise) */
bool boolarr_issame(const boolarr* b1, const boolarr* b2)
{
    if (b1 == NULL && b2 == NULL){
        return true;
    }
    else if(b1 == NULL){
        return false;
    }
    else if(b2 == NULL){
        return false;
    }

    if (boolarr_size(b1) != boolarr_size(b2)){
        return false;
    }

    
    if (memcmp(b1->a, b2->a, (int)boolarr_size(b1)) == 0){
        return true;
    }
    return false;
}

/* Store to string - rightmost bit is LSB */
bool boolarr_tostring(const boolarr* ba, char* str)
{
    if (ba == NULL){
        return false;
    }
    if (str == NULL){
        return false;
    }
    memcpy(str, (char*) ba->a, (int)boolarr_size(ba));
    return true;
}

/* Print out array & meta info */
bool boolarr_print(const boolarr* ba)
{
    printf("size: %i\n", ba->size);
    printf("capacity: %i\n", ba->capacity);
    for (int i=0; i<(int)boolarr_size(ba); i++){
        printf("%c", ba->a[i]);
    }
    printf("\n");
    return true;
}

/* Flip all bits */
bool boolarr_negate(boolarr* ba)
{
    for (int i=0; i<(int)boolarr_size(ba); i++){
        if (ba->a[i] == '1'){
            ba->a[i] = '0';
        }
        else{
            ba->a[i] = '1';
        }
    }
    return true;
}

/* Functions dealing with 2 bitwise-arrays */
/* Must be the same length */
boolarr* boolarr_bitwise(const boolarr* ba1, const boolarr* ba2, const logicalop l)
{
    if (boolarr_size(ba1) != boolarr_size(ba2)){
        fprintf(stderr, "boolarr_bitwise operation must be the same length.");
        exit(EXIT_FAILURE);
    }
    boolarr* ba3 = boolarr_clone(ba1);

    for (int i=0; i<(int)boolarr_size(ba1); i++){
        if (l == and){
            if (ba1->a[i] == '1' && ba2->a[i] == '1'){
                ba3->a[i] = '1';
            }
            else{
                ba3->a[i] = '0';
            }
        }
        else if(l == or){
            if (ba1->a[i] == '1' || ba2->a[i] == '1'){
                ba3->a[i] = '1';
            }
            else{
                ba3->a[i] = '0';
            }
        }
        else if(l == xor){
            if (ba1->a[i] == '1' && ba2->a[i] == '0'){
                ba3->a[i] = '1';
            }
            else if (ba1->a[i] == '0' && ba2->a[i] == '1'){
                ba3->a[i] = '1';
            }
            else{
                ba3->a[i] = '0';
            }
        }
    }
    return ba3;
}

/* Clears all space */
bool boolarr_free(boolarr* p)
{
    free(p->a);
    free(p);
    return true;
}

