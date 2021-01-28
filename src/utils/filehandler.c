#define MAX_LEN 125
#include "filehandler.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//Print ascii art from file :-)
void print_file(FILE *fptr)
{
    char read_string[MAX_LEN];
 
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
}
//Save seed to a file
int save_seed(time_t seed){
    char seed_char[20] = {'\0'};
    sprintf(seed_char, "%d",seed);
    char filename[sizeof "seed999999999.txt"];
    sprintf(filename, "./seeds/seed%03d.txt", seed);
    FILE *fPtr = fopen(filename, "w");
    if(fPtr == NULL)
    {
        return -1;
    }
    fputs(seed_char, fPtr);
    fclose(fPtr);
    return 0;
}