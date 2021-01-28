#ifndef INCLUDE_LIST
    #define INCLUDE_LIST

typedef struct node {
    Room* data;
    struct node* next;
} Node; 

typedef Node* List;

List create_list();

void push(List *list, Room *room);

Room* pop(List *list);

bool list_empty(List *list);

#endif