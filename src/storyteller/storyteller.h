#ifndef INCLUDE_STORYTELLER
    #define INCLUDE_STORYTELLER


#include "../player/player.h"
#include "../board/room.h"

//Print a room description.
void print_room_desc(Room* room);

//Print player stats.
void print_player_stats(Player* player);

//Handle the player choice.
int handle_event(char input[10], Player* player, Player* rival);

#endif