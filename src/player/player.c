#include "player.h"
#include "room.h"
#include <stdio.h>

//Do Damage to player.
void do_damage(Player *player, Player *rival, int dmg){
    int hp = player->hp - dmg;
    if(hp <= 0){
        printf("\nZginąłeś.\n");
        victory(rival);
        return;
    } else{
        player->hp = hp;
        return;
    }
}

/*
    Key - 0
    Pickaxe - 1
    Sword - 2
*/

//Handle item pickup
void item_pickup(Player *player,Room *room,int item){
    if(item == 0){
        player->hasKey = true;
        if(player->num == 1){
            room->hasP1Key = false;
        } else if(player->num == 2){
            room->hasP2Key = false;
        } else {
            printf("player.c error at line 33. wrong player num. num not set?");
        }
    } else if(item == 1){
        player->hasPickaxe = true;
        room->props[5] = false;
    } else if(item == 2){
        player->hasSword = true;
        room->props[6] = false;
    }
}

//Handle victory
void victory(Player *player){
    printf("\nGracz %d zwycięża!!\n",player->num);
}