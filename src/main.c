#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./board/board.h"

int main(){
    time_t seed = time(NULL);
    Board xd = generate_board(5, seed);
    int choice = -1;
    Room* current_room = xd;

    while(choice != 0){
        printf("\n\nYou are currently in a room of type %d\n", current_room->room_type);
        printf("1 - go right, 2 - go left 3- go back\n");
        
        scanf("%d",&choice);
        if(choice == 1){
            if(current_room->right == NULL){
                printf("\nTHERE IS NOTHING HERE!\n");
            }else
            {
                current_room = current_room->right;
            }
        } else if(choice == 2){
            if(current_room->left == NULL){
                printf("\nTHERE IS NOTHING HERE!\n");
            }else{
                    current_room = current_room->left;
                }
            } else if(choice == 3){
                if(current_room->prev == NULL){
                    printf("\nYOURE IN THE ROOT!\n");
                } else{
                    current_room = current_room->prev;
                }
            } else{
                continue;
            }
    }

    return 0;
    
}
