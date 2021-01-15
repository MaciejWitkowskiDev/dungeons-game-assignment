#include "room.h"
#include "board.h"
#include <stdlib.h>

/*
    Board handbook:
    Board is always a pointer at the root room.
*/

Board generate_board(int maxdepth){
    //Create the root room
    Room* root = create_room(1,NULL,NULL,NULL);

    Room* left_of_root = create_room(2, root, NULL, NULL);
    Room* right_of_root = create_room(2,root,NULL,NULL);
    
    root->left = left_of_root;
    root->right = right_of_root;
    


}