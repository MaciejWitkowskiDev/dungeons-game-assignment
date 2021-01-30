#include <stdlib.h>
#include <stdbool.h>
#include "room.h"

Room* create_room(short int room_type, Room* prev, Room* left, Room* right){
    Room* new_room = malloc(sizeof(Room)+1);
    new_room->room_type = room_type;
    new_room->prev = prev;
    new_room->left = left;
    new_room->right = right;
    new_room->shortcut = NULL;
    for(int i = 0; i < 7; i++){
        new_room->props[i] = false;
    }
    new_room->hasP1Key = false;
    new_room->hasP2Key = false;
    new_room->hasTreasure = false;
    return new_room;
}