#include<stdio.h>
#include<assert.h>
#define HOUR_MINS 60
#define DAY_HOURS 24
#define DAY_MINS DAY_HOURS*HOUR_MINS

int readtime(int h, int m);
int cal_timediff(int t1, int t2);
void test();


int main(void)
{   
    test();
    int h1, m1, h2, m2;
    printf("Enter two times : ");
    if (scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2) == 4){
        int timediff;
        timediff = cal_timediff(readtime(h1, m1), readtime(h2, m2));
        printf("Difference is : %02i:%02i\n", timediff/HOUR_MINS, timediff%HOUR_MINS);
    }
    return 0;
}


int readtime(int h, int m)
{
    return h * HOUR_MINS + m;
}

int cal_timediff(int t1, int t2)
{
    if (t2 > t1){
        return t2 - t1;
    }
    else{
        return DAY_MINS + t2 - t1;
    }
}

void test()
{
    assert(readtime(8, 10) == 490);
    assert(readtime(20, 30) == 1230);
    assert(cal_timediff(readtime(10, 10), readtime(10, 30)) == 20);
    assert(cal_timediff(readtime(23, 59), readtime(0, 1)) == 2);
}
