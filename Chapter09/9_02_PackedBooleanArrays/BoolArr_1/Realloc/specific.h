#include<math.h>
#include<string.h>
#define FIXEDSIZE 1
#define SCALEFACTOR 2
#define BASE2 2
#define BASE256 256
typedef unsigned char boolarrtype;

struct boolarr{
    colltype* a;
    int size;
    int capacity;
};
typedef struct boolarr boolarr;


