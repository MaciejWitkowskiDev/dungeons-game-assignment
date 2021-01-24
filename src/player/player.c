#include "player.h"
#include <stdio.h>

//Do Damage to player.
void do_damage(Player *player, Player *rival, int dmg){
    int hp = player->hp - dmg;
    if(hp <= 0){
        printf("\nZginąłeś.\n");
        victory(rival, player);
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
void item_pickup(Player *player,int item){
    if(item == 0){
        player->hasKey = true;
    } else if(item == 1){
        player->hasPickaxe = true;
    } else if(item == 2){
        player->hasSword = true;
    }
}

//Handle victory
void victory(Player *player, Player *rival){

}
