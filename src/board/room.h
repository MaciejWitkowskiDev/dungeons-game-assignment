#ifndef INCLUDE_ROOM
    #define INCLUDE_ROOM

#include <stdbool.h>
//Room props work like this:
/*
    props[n] = true - 
    means that room contains a thing numbered n:

    0 - Trap
    1 - Riddle
    2 - Shortcut
    3 - Guard
    4 - BlockedPath
    5 - Pickaxe
    6 - Sword

*/

//The room-node:
typedef struct room{
    int room_id;
    short int room_type;
    struct room* prev;
    struct room* left;
    struct room* right;
    struct room* shortcut;
    //Room properties will go here
    bool hasTreasure;
    bool hasP1Key;
    bool hasP2Key;
    bool props[7];

} Room;

Room* create_room(short int room_type, Room* prev, Room* left, Room* right);

#endif