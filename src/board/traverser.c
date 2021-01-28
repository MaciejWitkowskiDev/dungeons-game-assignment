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
        printf("\nWarning: wrong random number @line 16 in traverser.c\n");
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
    printf("\nPlacing the tresure in a room of id %d\n",current_room->room_id);
}

//Place the player keys.
void place_keys(Board *board, time_t seed){
    Room* root = *board;
    srand(seed);
    int depth = (int)seed % 10;
    int i = 0;
    short int choice = (short int)(rand() % (1-3) + 1);
    Room* current_room = NULL;

    //Randomly choose root side
    if(choice == 1 ){
        current_room = root->right;
    } else if(choice == 2){
        current_room = root->left;
    } else{
        printf("\nWarning: wrong random number @line 49 in traverser.c\n");
        current_room = root->left;
    }

    while((current_room->left != NULL || current_room->right != NULL) && i <=depth) {
        if(current_room->left == NULL){
            current_room = current_room->right;
        } else{
            current_room = current_room->left;
        }
        i++;
    }
    //So now current_room is some random room at the edge of the map. Here is where the key1 will be.
    current_room->hasP1Key = true;
    printf("\nPlacing the key1 in a room of id %d\n",current_room->room_id);

    choice = (short int)(rand() % (1-3) + 1);
    current_room = NULL;

    //Randomly choose root side
    if(choice == 1 ){
        current_room = root->left;
    } else if(choice == 2){
        current_room = root->right;
    } else{
        printf("\nWarning: wrong random number @line 72 in traverser.c\n");
        current_room = root->left;
    }

    while((current_room->left != NULL || current_room->right != NULL) && i <=depth) {
        if(current_room->left == NULL){
            current_room = current_room->right;
        } else{
            current_room = current_room->left;
        }
    }
    current_room->hasP2Key = true;
    printf("\nPlacing the key2 in a room of id %d\n",current_room->room_id);
}

void populate_board(Board *board,time_t seed){
    Room* root = *board;
    List to_service = create_list();
    Room* current_room = NULL;
    int prop;
    bool placedPickaxe = false;
    bool placedSword = false;
    srand(seed);

    //populate right side of root
    current_room = root->right;
    while(current_room != NULL){
        if(current_room->left != NULL){
            push(&to_service, current_room->left);
        }
        if(current_room->right != NULL){
            push(&to_service,current_room->right);
        }
        if(current_room->hasTreasure || current_room->hasP1Key || current_room->hasP2Key){
            current_room = pop(&to_service);
            continue;
        }
        /*
         0 - Trap
        1 - Riddle
        2 - Shortcut
        3 - Guard
        4 - BlockedPath
        5 - Pickaxe
        6 - Sword
        */
        //Generate random prop
        prop = rand() % (7 + 1 - 0) + 0;
        //If sword already placed, then change the prop value to something else.
        if(prop == 6 && placedSword){
            while(prop == 6){
                prop = rand() % (7 + 1 - 0) + 0;
            }
        }
        //If picked blocked path, but there is no pickaxe placed, then change.
        if(prop == 4 && !placedPickaxe){
            //If sword was already placed, then the value cannot be 6 either.
            if(placedSword){
                while(prop == 4 || prop == 6){
                    prop = rand() % (7 + 1 - 0) + 0;
                }
            } else{
                //If there is no sword, then the value can be 6, and just cannot be 4.
                while(prop == 4){
                    prop = rand() % (7 + 1 - 0) + 0;
                }
            }
        }

        if(prop == 6 && !placedSword){
            placedSword = true;
        }
        if(prop == 5 && !placedPickaxe){
            placedPickaxe = true;
        }
        current_room->props[prop] = true;
        current_room = pop(&to_service);
    }
    current_room = root->left;
    while(current_room != NULL){
        if(current_room->left != NULL){
            push(&to_service, current_room->left);
        }
        if(current_room->right != NULL){
            push(&to_service,current_room->right);
        }
        if(current_room->hasTreasure || current_room->hasP1Key || current_room->hasP2Key){
            current_room = pop(&to_service);
            continue;
        }

        prop = rand() % (7 + 1 - 0) + 0;
        current_room->props[prop] = true;
        current_room = pop(&to_service);
    }


}