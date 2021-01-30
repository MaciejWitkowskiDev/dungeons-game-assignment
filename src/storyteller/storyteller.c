#include "storyteller.h"
#include "textheaders.h"
#include "../utils/prettyprint.h"
#include <string.h>

//Print a room description.
void print_room_desc(Room* room, Player* player, Player* rival){
    if(room->room_type == 1){ 
        ppp(root_header()); 
        return;
    } else {
        ppp(random_room_header());
    }
}

void print_movement_opts(Room* room){
    ppp("Wybierz ruch:\n");
    if(room->left != NULL){
        printf("l - aby iśc w lewo.\n");
    }
    if(room->right != NULL){
        printf("p - aby iść w prawo.\n");
    }
    if(room->prev != NULL){
        printf("c - aby się cofnąć.\n");
    }
}

//Print player stats.
void print_player_stats(Player* player){
    char player_info[40] = {'\0'};
    char eq[40] = {'\0'};
    sprintf(player_info,"Tura gracza %d. \nMasz %d/10 punktów życia.",player->num,player->hp);
    if(!player->hasSword && !player->hasPickaxe){
        sprintf(eq,"Nie masz żadnych przedmiotów.");
    } else if(player->hasSword && !player->hasPickaxe){
        sprintf(eq,"Masz przy sobie miecz.");
    } else if(!player->hasSword && player->hasPickaxe){
        sprintf(eq,"Masz przy sobie kilof.");
    } else if(player->hasSword && player->hasPickaxe){
        sprintf(eq,"Masz przy sobie miecz i kilof.");
    }
    ppp(player_info);
    ppp(eq);
}
