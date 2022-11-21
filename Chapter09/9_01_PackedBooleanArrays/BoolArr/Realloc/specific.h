#include<string.h>
#define FIXEDSIZE 16
#define SCALEFACTOR 2
typedef unsigned char colltype;

struct boolarr{
    colltype* a;
    int size;
    int capacity;
};
typedef struct boolarr boolarr;


