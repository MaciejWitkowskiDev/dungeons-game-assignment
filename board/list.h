#include "room.h"

typedef struct node {
    Room data;
    Room* next;
} Node; 

typedef Node* List;

void push(List *list, Room *room);

Room* pop();
