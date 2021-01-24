#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "board.h"
#include "list.h"

/*
    Board handbook:
    A board is basically a graph, so BFS and DFS are used for traversal.
    Board is always a pointer at the root room.
*/

Board generate_board(short int maxdepth, time_t seed){
    //Create the root room
    Room* root = create_room(1,NULL,NULL,NULL);
    root->room_id = 0;

    Room* left_of_root = create_room(2, root, NULL, NULL);
    Room* right_of_root = create_room(2,root,NULL,NULL);
    left_of_root->room_id = rand();
    right_of_root->room_id = rand();
    
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
            Room* left_room = create_room(room_type,currently_serviced,NULL,NULL);
            left_room->room_id = rand();
            push(&to_service, left_room);
            currently_serviced->left = left_room;
            printf("Creating one room with id %d.\n",left_room->room_id);
        }
        //if choice is two - generate two extra rooms.
        else if(choice == 2){
            Room* left_room = create_room(room_type,currently_serviced,NULL,NULL);
            Room* right_room = create_room(room_type,currently_serviced,NULL,NULL);
            left_room->room_id = rand();
            right_room->room_id = rand();
            push(&to_service, left_room);
            push(&to_service, right_room);
            currently_serviced->left = left_room;
            currently_serviced->right = right_room;
            printf("Creating two rooms with id: %d and %d.\n",left_room->room_id,right_room->room_id);
        }
        else{
            printf("Wrong random number, board.c line 42");
        }
        currently_serviced = pop(&to_service);
        depth ++;
    }

    //Now generate the left route:
    depth = 0;
    choice = 0;
    currently_serviced = left_of_root;
    to_service = NULL;

    while(depth <= maxdepth){
        choice = (short int)(rand() % (1-3) + 1);
        short int room_type = depth == maxdepth || depth == maxdepth - 1 ? 3 : 2;
        //if choice is one - generate only one extra room
        if(choice == 1){
            Room* left_room = create_room(room_type,currently_serviced,NULL,NULL);
            left_room->room_id = rand();
            push(&to_service, left_room);
            currently_serviced->left = left_room;
            printf("Creating one room with id %d.\n",left_room->room_id);
        }
        //if choice is two - generate two extra rooms.
        else if(choice == 2){
            Room* left_room = create_room(room_type,currently_serviced,NULL,NULL);
            Room* right_room = create_room(room_type,currently_serviced,NULL,NULL);
            left_room->room_id = rand();
            right_room->room_id = rand();
            push(&to_service, left_room);
            push(&to_service, right_room);
            currently_serviced->left = left_room;
            currently_serviced->right = right_room;
            printf("Creating two rooms with id: %d and %d.\n",left_room->room_id,right_room->room_id);
        }
        else{
            printf("Wrong random number, board.c line 83");
        }
        currently_serviced = pop(&to_service);
        depth ++;
    }

    return root;

}