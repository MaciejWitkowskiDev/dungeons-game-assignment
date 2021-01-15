typedef struct node {
    Room* data;
    struct node* next;
} Node; 

typedef Node* List;

List create_list();

void push(List *list, Room *room);

Room* pop();

bool list_empty(List *list);