#include <stdio.h>
#include <stdlib.h>
#include "traverser.h"
#include "list.h"


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
    printf("Placing the tresure in a room of type %d",current_room->room_type);
}

//Return a list with all room nodes in it
List list_all_rooms(Board *board){

    //List of rooms to service (add to all_rooms)
    List to_service = create_list();
    List all_rooms = create_list();
    Room* root = *board;
    Room* current_room = root->right;
    Room* next_room = NULL;
    //Add all rooms to the right of root to our list BFS-style:
    do
    {
        if(current_room->left != NULL){
            push(&to_service,current_room->left);
            push(&all_rooms,current_room->left);
        }
        if(current_room->right != NULL){
            push(&to_service,current_room->right);
            push(&all_rooms,current_room->right);
        }
        next_room = pop(&to_service);

    } while (next_room != NULL);

    current_room = root->left;
    next_room = NULL;
    to_service = NULL;
    //Add all rooms to the left of root to our list BFS-style:
    do
    {
        if(current_room->left != NULL){
            push(&to_service,current_room->left);
            push(&all_rooms,current_room->left);
        }
        if(current_room->right != NULL){
            push(&to_service,current_room->right);
            push(&all_rooms,current_room->right);
        }
        next_room = pop(&to_service);

    } while (next_room != NULL);

    return all_rooms;
}
