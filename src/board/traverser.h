/*
    This is a module that traverses the board and does things
    on the rooms. It implements BFS and DFS.
*/
#include "board.h"
#include "list.h"

//Place the treasure in a random terminary room DFS-style :)
void place_treasure(Board *board, time_t seed);

//Return a list with all room nodes in it
List list_all_rooms(Board *board);

//Print all rooms before we implement the mini-map
void print_all_rooms(List *rooms);

//Place the player keys.
void place_keys(Board *board, time_t seed);

//Populate the board with random events.
void populate_board(Board *board,time_t seed);



