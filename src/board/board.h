#ifndef INCLUDE_BOARD
    #define INCLUDE_BOARD

#include "room.h"
#include <time.h>

typedef Room* Board;

Board generate_board(short int maxdepth,time_t seed);

#endif