#include "storyteller.h"
#include "textheaders.h"
#include "../utils/prettyprint.h"

//Print a room description.
void print_room_desc(Room* room){
    if(room->room_type == 1){ 
        ppp(root_header()); 
        return;
    } else {
        ppp(random_room_header());
    }
}

//Print player stats.
void print_player_stats(Player* player);

//Handle the player choice.
int handle_event(char input[10], Player* player, Player* rival);
