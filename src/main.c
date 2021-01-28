#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./board/traverser.h"
#include "./player/player.h"

int main(){
    time_t seed = time(NULL);
    Board game_board = generate_board(5, seed);
    Player *player_1 = malloc(sizeof(Player)+1);
    Player *player_2 = malloc(sizeof(Player)+1);
    player_1->num = 1;
    player_1->hp = 10;
    player_2->num = 2;
    player_2->hp = 10;
    int choice = -1;

    place_treasure(&game_board,seed);
    place_keys(&game_board,seed);
    populate_board(&game_board,seed);
    Room* current_room = game_board;

    
    while(choice != 0){
        printf("\n\nYou are currently in a room of id %d\n", current_room->room_id);
        if(current_room->hasP1Key){
            printf("You found your key!");
        }
        if(current_room->hasP2Key){
            printf("You found player 2's key!");
        }
        if(current_room->props[0]){
            printf("You stuble upon a trap!");
        }
        if(current_room->props[1]){
            printf("You stuble upon a riddle!");
        }
        if(current_room->props[2]){
            printf("You stuble upon a Shortcut!");
        }
        if(current_room->props[3]){
            printf("You stuble upon a Guard!");
        }
        if(current_room->props[4]){
            printf("You stuble upon a blocked path!");
        }
        if(current_room->props[5]){
            printf("You stuble upon a pickaxe!");
        }
        if(current_room->props[6]){
            printf("You stuble upon a sword!");
        }
        if(current_room->hasTreasure){
            printf("\nTREASURE!!\n");
        }
        printf("\n1 - go right, 2 - go left 3- go back\n");
        
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
