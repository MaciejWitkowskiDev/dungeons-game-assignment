#include <stdio.h>
#include <stdlib.h>
#include "traverser.h"


//Place the treasure in a random terminary room DFS-style :)
void place_treasure(Board *board, time_t seed){
    Room* root = *board;
    srand(seed);
    short int choice = (short int)(rand() % (1-3) + 1);
    Room* current_room = NULL;

    //Randomly choose root side
    if(choice == 1 ){
        current_room = root->left;
    } else if(choice == 2){
        current_room = root->right;
    } else{
        printf("Warning: wrong random number @line 16 in traverser.c");
        current_room = root->left;
    }

    while(current_room->left != NULL || current_room->right != NULL){
        if(current_room->left == NULL){
            current_room = current_room->right;
        } else{
            current_room = current_room->left;
        }
    }
    //So now current_room is some random room at the edge of the map. Here is where the treasure will be.

    current_room->hasTreasure = true;
    printf("Placing the tresure in a room of id %d",current_room->room_id);
}

