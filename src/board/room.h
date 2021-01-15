

//The room-node:
typedef struct room{
    short int room_type;
    struct room* prev;
    struct room* left;
    struct room* right;
    //Room properties will go here
} Room;

Room* create_room(short int room_type, Room* prev, Room* left, Room* right);
