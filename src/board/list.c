#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "room.h"
#include "list.h"

/*
List handbook:
(*list) to zawsze ostatni element listy
(*list)->next to zawsze pierwszy element listy
*/

//may be of use in the future?
List create_list(){
    return NULL;
}

bool list_empty(List *list){
    return *list == NULL;
}

void push(List *list, Room *room){
    Node *new_node = malloc(sizeof(Node)+1);
    new_node->data = room;
    if(list_empty(list)){
        new_node->next = new_node;
        *list = new_node;
        return;
    }
    new_node->next = (*list)->next;
    (*list)->next = new_node;
}

Room* pop(List *list){
    if(list_empty(list)){
        return NULL;
    }
    Node *first = (*list)->next;
    Room* room = first->data;
    (*list)->next = first->next;
    free(first);
    return room;
}