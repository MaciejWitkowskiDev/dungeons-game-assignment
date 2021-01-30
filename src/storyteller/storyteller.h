#ifndef INCLUDE_STORYTELLER
    #define INCLUDE_STORYTELLER


#include "../player/player.h"
#include "../board/room.h"

//Print a room description.
void print_room_desc(Room* room, Player* turn);

//Print player stats.
void print_player_stats(Player* player);

//Print the prop info
void print_prop_choice(Room* room, Player* player, Player* rival);

//Handle the room.
int handle_room(Room* room, Player* player, Player* rival);

//Print the available movement options.
void print_movement_opts(Room* room);


#endif