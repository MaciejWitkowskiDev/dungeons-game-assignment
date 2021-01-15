//The room-node:
typedef struct room{
    enum type{root, intermed, terminary} room_type;
    struct room* prev;
    struct room* left;
    struct room* right;
    //Room properties will go here
} Room;

