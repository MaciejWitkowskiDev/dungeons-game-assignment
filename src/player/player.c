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

//Handle item pickup
void item_pickup(Player *player,int item){

}

//Handle victory
void victory(Player *player, Player *rival){

}
