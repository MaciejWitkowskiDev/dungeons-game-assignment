#include "storyteller.h"
#include "textheaders.h"
#include "../utils/prettyprint.h"
#include <string.h>

//Print a room description.
void print_room_desc(Room* room, Player* turn){
    
    int prop = -1;

    if(room->room_type == 1){ 
        ppp(root_header()); 
        return;
    } else {
        ppp(random_room_header());
    }

    for(int i = 0; i < 7; i++){
        if(room->props[i]){
            prop = i;
        }
    }
    if(prop == -1){
        bool roomHasTurnPlayerKey = (turn->num == 1 && room->hasP1Key) || (turn->num == 2 && room->hasP2Key);
        if(roomHasTurnPlayerKey && !room->hasTreasure){
            ppp("Dostrzegasz w pokoju złoty klucz. Czujesz, że jest przeznaczony dla Ciebie.");
        } else if((room->hasP1Key || room->hasP2Key)){
            ppp("Dostrzegasz w pokoju złoty klucz. Niestety, nie jest przeznaczony dla Ciebie.");
        }
        if(room->hasTreasure && roomHasTurnPlayerKey){
            ppp("Widzisz w pokoju wielką, ciężką skrzynię. Odnalazłeś to czego poszukiwałeś.");
            ppp("Co za szczęście!\nDostrzegasz w pokoju złoty klucz. Czujesz, że jest przeznaczony dla Ciebie.");
        }
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

int handle_room(Room* room, Player* player, Player* rival){
    print_room_desc(room);

}