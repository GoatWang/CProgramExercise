#include "specific.h"
#include "../boolarr.h"

/* All elements initialised to "0" */
boolarr* boolarr_init(void)
{
    boolarr* ba = (boolarr*) ncalloc(1, sizeof(boolarr));
    ba->a = (boolarrtype*) ncalloc(FIXEDSIZE, sizeof(boolarrtype));
    ba->n_bits = 0;
    ba->capacity = FIXEDSIZE;
    return ba;
}

int _stridx2bitidx(int stridx)
{
    int bit_idx = stridx % NBITS;
    return bit_idx;
}

int _stridx2byteidx(int stridx)
{
    int byteidx = stridx / NBITS;
    return byteidx;
}

int _bitidx2stridx(int byteidx, int bitidx)
{
    int stridx = byteidx * NBITS + bitidx;
    return stridx;
}

/* Create boolarr based on string e.g. "1100001" */
boolarr* boolarr_initstr(const char* str)
{
    boolarr* ba = boolarr_init();
    int n_bits = strlen(str);
    int n_bytes = (n_bits / NBITS + 1);
    while (ba->capacity < n_bytes){
        ba->a = (boolarrtype*) nrecalloc(ba->a, ba->capacity, ba->capacity*SCALEFACTOR*sizeof(boolarrtype));
        ba->capacity = ba->capacity*SCALEFACTOR*sizeof(boolarrtype);
    }

    // LSB is the first bit
    for (int i=0; i<n_bits; i++){
        if (str[n_bits-1-i] == '1'){
            int bit_idx = _stridx2bitidx(i);
            int byte_idx = _stridx2byteidx(i);
            ba->a[byte_idx] += pow(BASE2, bit_idx);
        }
    }

    ba->n_bits = n_bits;
    return ba;
}

/* Return a deep copy */
boolarr* boolarr_clone(const boolarr* ba)
{
    boolarr* ba_new = boolarr_init();
    ba_new->a = (boolarrtype*) nrecalloc(ba_new->a, ba_new->capacity, ba->capacity);
    ba_new->n_bits = ba->n_bits;
    ba_new->capacity = ba->capacity;
    memcpy(ba_new->a,  ba->a, ba_new->capacity);
    return ba_new;
}

/* Get number of bits in array */
unsigned int boolarr_size(const boolarr* ba)
{
    if(ba==NULL){
        return 0;
    }
    return ba->n_bits;
}

/* Return number of bits that are set true */
unsigned int boolarr_count1s(const boolarr* ba)
{
    int cnt = 0;
    if(ba!=NULL){
        int n_bytes = (boolarr_size(ba)/NBITS+1);
        for (int i=0; i<n_bytes; i++){
            for (int j=0; j<NBITS; j++){
                if ((ba->a[i] && pow(BASE2, j)) > 0){
                    cnt += 1;        
                }
            }
        }
    }
    return cnt;
}

/* Set nth bit on/off */
bool boolarr_set(boolarr* ba, const unsigned int n, const bool b)
{
    if(ba==NULL){
        return false;
    }

    int n_bits = n + 1;
    int n_bytes = (n_bits / NBITS + 1);
    while (ba->capacity < n_bytes){
        ba->a = (boolarrtype*) nrecalloc(ba->a, ba->capacity, ba->capacity*SCALEFACTOR*sizeof(boolarrtype));
        ba->capacity = ba->capacity*SCALEFACTOR*sizeof(boolarrtype);
    }

    int bit_idx = _stridx2bitidx(n);
    int byte_idx = _stridx2byteidx(n);
    if (b == 1 && ((int) ba->a[byte_idx] & (int) pow(2, bit_idx)) == 0){
        ba->a[byte_idx] += pow(2, bit_idx);
    }
    else if (b == 0 && ((int) ba->a[byte_idx] & (int) pow(2, bit_idx)) != 0){
        ba->a[byte_idx] -= pow(2, bit_idx);
    }

    if (boolarr_size(ba) < (n + 1)){
        ba->n_bits = n + 1;
    }
    return true;
}

/* Get nth bit */
bool boolarr_get(const boolarr* ba, const unsigned int n, bool* b)
{   
    if (ba == NULL){
        return false;
    }

    int bit_idx = _stridx2bitidx(n);
    int byte_idx = _stridx2byteidx(n);
    *b = (int) ba->a[byte_idx] & (int) pow(BASE2, bit_idx);
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

    bool issame = true;
    for (int i=0; i<(int) boolarr_size(b1)/NBITS+1; i++){
        if (b1->a[i] != b2->a[i]){
            issame = false;
        }
    }
    return issame;
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

    int n_bits = boolarr_size(ba);
    int n_bytes = (n_bits / NBITS + 1);
    // TODO: Conditional jump or move depends on uninitialised value(s)
    char str_temp[BIGSTR];
    memset(str_temp, '\0', BIGSTR);
    for (int byteidx=0; byteidx<n_bytes; byteidx++){
        for (int bitidx=0; bitidx<NBITS; bitidx++){
            if (byteidx*NBITS+bitidx < n_bits){
                int stridx = n_bits - 1 - _bitidx2stridx(byteidx, bitidx);
                if (((int) ba->a[byteidx] & (int) pow(BASE2, bitidx)) != 0){
                    // str[stridx] = '1';
                    str_temp[stridx] = '1';
                }
                else{
                    // str[stridx] = '0';
                    str_temp[stridx] = '0';
                }
            }
        }
    }

    strcpy(str, str_temp);
    return true;
}

/* Print out array & meta info */
bool boolarr_print(const boolarr* ba)
{
    int n_bits = boolarr_size(ba);
    int n_bytes = (n_bits / NBITS + 1);
    char str[BIGSTR];
    memset(str, '\0', BIGSTR);
    boolarr_tostring(ba, str);
    printf("n_bits: %i\n", n_bits);
    printf("n_bytes: %i\n", n_bytes);
    printf("capacity: %i\n", ba->capacity);
    printf("binary: %s\n", str);
    return true;
}

/* Flip all bits */
bool boolarr_negate(boolarr* ba)
{
    int n_bits = boolarr_size(ba);
    int n_bytes = (n_bits / NBITS + 1);
    for (int byteidx=0; byteidx<n_bytes; byteidx++){
        for (int bitidx=0; bitidx<NBITS; bitidx++){
            if (byteidx*NBITS+bitidx < n_bits){
                if (((int) ba->a[byteidx] & (int) pow(BASE2, bitidx)) != 0){
                    ba->a[byteidx] -= pow(BASE2, bitidx);
                }
                else{
                    ba->a[byteidx] += pow(BASE2, bitidx);
                }
            }
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
    for (int i=0; i<(int) boolarr_size(ba1)/NBITS+1; i++){
        if (l == and){
            ba3->a[i] = ba1->a[i] & ba2->a[i];
        }
        else if(l == or){
            ba3->a[i] = ba1->a[i] | ba2->a[i];
        }
        else if(l == xor){
            ba3->a[i] = (ba1->a[i] ^ ba2->a[i]);
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




