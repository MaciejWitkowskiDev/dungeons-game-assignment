#ifndef INCLUDE_PLAYER
    #define INCLUDE_PLAYER

#include <stdbool.h>
#include "../player/player.h"
#include "../board/room.h"

//Very simple module to handle player actions.

typedef struct player{
    short int num;
    int hp;
    int max_hp;
    bool hasKey;
    bool hasPickaxe;
    bool hasSword;
    Room* current_room;
} Player;


//Do Damage to player.
void do_damage(Player *player, Player *rival, int dmg);

//Handle item pickup
void item_pickup(Player *player,Room *room, int item);

//Handle victory
void victory(Player *player);

#endif