#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "board.h"
#include "list.h"


/*
    Board handbook:
    Board is always a pointer at the root room.
*/

Board generate_board(short int maxdepth, time_t seed){
    //Create the root room
    Room* root = create_room(1,NULL,NULL,NULL);

    Room* left_of_root = create_room(2, root, NULL, NULL);
    Room* right_of_root = create_room(2,root,NULL,NULL);
    
    root->left = left_of_root;
    root->right = right_of_root;
    
    //Randomly generate the right path.
    srand(seed);
    List to_service = create_list();
    short int depth = 0;
    int choice;
    Room* currently_serviced = right_of_root;
    while(depth < maxdepth){
        choice = rand() % (1-4) + 1;
        printf("Randomised number: %d\n",choice); 
        depth ++;
    }

}