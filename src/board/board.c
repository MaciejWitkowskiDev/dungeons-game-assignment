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
    short int choice;
    Room* currently_serviced = right_of_root;

    while(depth <= maxdepth){
        choice = (short int)(rand() % (1-3) + 1);
        short int room_type = depth == maxdepth || depth == maxdepth - 1 ? 3 : 2;
        //if choice is one - generate only one extra room
        if(choice == 1){
            printf("Creating one room of type %d.\n",room_type);
            Room* left_room = create_room(room_type,currently_serviced,NULL,NULL);
            push(&to_service, left_room);
            currently_serviced->left = left_room;
        }
        //if choice is two - generate two extra rooms.
        else if(choice == 2){
            printf("Creating two rooms of type %d.\n",room_type);
            Room* left_room = create_room(room_type,currently_serviced,NULL,NULL);
            Room* right_room = create_room(room_type,currently_serviced,NULL,NULL);
            push(&to_service, left_room);
            push(&to_service, right_room);
            currently_serviced->left = left_room;
            currently_serviced->right = right_room;
        }
        else{
            printf("Wrong random number, board.c line 42");
        }
        currently_serviced = pop(&to_service);
        depth ++;
    }
    return root;

}