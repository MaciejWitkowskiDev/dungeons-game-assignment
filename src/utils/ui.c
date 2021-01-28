#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include "clear.h"
#include "prettyprint.h"

//Show the main menu
void show_main_menu(){
    char *filename_menu = "./text_chunks/main_menu.txt";
    FILE *fptr_menu = NULL;
     if((fptr_menu = fopen(filename_menu,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename_menu);
        return;
    }
    print_file(fptr_menu);
    fclose(fptr_menu);
    printf("\n");
}

//Show the intro sequence
void show_introduction(){
    char *filename_logo = "./ascii_arts/logo.txt";
    char *filename_menu_header = "./ascii_arts/header.txt";
    FILE *fptr_logo = NULL;
    FILE *fptr_header = NULL;
 
    if((fptr_logo = fopen(filename_logo,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename_logo);
        return;
    }

    if((fptr_header = fopen(filename_menu_header,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename_menu_header);
        return;
    }
    
    //Introduction
    clear_screen();
    ppp("Budzisz się w ciemnym pomieszczeniu. Wokoło widzisz pochodnie.");
    ppp("To tu rozpoczyna się twoja podróż.");
    clear_screen();
    print_file(fptr_logo);
    fclose(fptr_logo);
    msleep(2000);
    clear_screen();
    print_file(fptr_header);
    fclose(fptr_header);
    printf("\n");
}