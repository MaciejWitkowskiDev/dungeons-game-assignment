#define MAX_LEN 128
#include <time.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int msleep(long msec)
{
    struct timespec ts;
    int res;

    if (msec < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}

void ppp(char* t){
    srand(time(NULL));
    char * i;
    int delay = 100;
    printf("\n");
    for (i=t; *i; i++) {
        delay = rand() % (100 + 1 - 20) + 20;
        putchar(*i);
        fflush(stdout);
        msleep((long)delay);
    }
    msleep(1000);
}

void print_logo(FILE *fptr)
{
    char read_string[MAX_LEN];
 
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
}