#include <stdbool.h>
//Room props work like this:
/*
    room_type can be 1,2 or 3.
    1 - Root room
    2 - Intermediary room (in the middle)
    3 - Terminary room (at the end)

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
    //Room properties will go here
    bool hasTreasure;
    bool hasKey;
    bool props[7];

} Room;

Room* create_room(short int room_type, Room* prev, Room* left, Room* right);
