/*
    This is a module that traverses the board and does things
    on the rooms. It implements BFS and DFS.
*/
#include "board.h"

void place_treasure(Board *board, time_t seed);
void place_random_events(Board *board);
void export_board(Board *board);
