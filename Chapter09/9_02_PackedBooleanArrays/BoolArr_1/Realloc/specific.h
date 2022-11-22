#include<math.h>
#include<string.h>
#define FIXEDSIZE 1
#define SCALEFACTOR 2
#define BASE2 2
#define NBITS 8
#define BIGSTR 1000
typedef unsigned char boolarrtype;

struct boolarr{
    boolarrtype* a;
    int capacity;
    int n_bits;
};
typedef struct boolarr boolarr;


