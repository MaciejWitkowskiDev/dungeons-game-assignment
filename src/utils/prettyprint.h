#ifndef INCLUDE_PRETTYPRINT
    #define INCLUDE_PRETTYPRINT
    
#include <stdio.h>

//Nanosleep implementation, bcs usleep is deprecated
int msleep(long msec);

//Prettyprint (shortened name for easier typing)
void ppp(char* t);

//Print ascii art from file :-)
void print_file(FILE *fptr);

#endif
