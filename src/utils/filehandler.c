#define MAX_LEN 125
#include "filehandler.h"
#include <stdio.h>

//Print ascii art from file :-)
void print_file(FILE *fptr)
{
    char read_string[MAX_LEN];
 
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
}