#include <stdio.h>
#include <time.h>

#ifndef INCLUDE_FILEHANDLER
    #define INCLUDE_FILEHANDLER

//Print ascii art from file :-)
void print_file(FILE *fptr);

//SAve seed to a file
int save_seed(time_t seed);

#endif