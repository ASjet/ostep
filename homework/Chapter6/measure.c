#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
////////////////////////////////////////////////////////////////////////////////
#define ITER_C 10000
////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    struct timeval start,end;
    float timer;
    int i = ITER_C;
    gettimeofday(&start,NULL);
    while(--i)
        read(NULL,NULL,0);
    gettimeofday(&end,NULL);
    timer = end.tv_sec - start.tv_sec + (float)(end.tv_usec - start.tv_usec)/1000000;
    printf("timer = %fs\n",timer);
    return 0;
}