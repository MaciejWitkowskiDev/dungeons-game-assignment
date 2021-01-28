#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>    
#include <unistd.h>
#include "./player/player.h"
#include "./board/traverser.h"
#include "./utils/clear.h"
#include "./utils/prettyprint.h"
#include "./utils/ui.h"
#include "./utils/filehandler.h"

int main(){

    int choice = -1;
    //show_introduction();
    show_main_menu();
    printf("\nTwój wybór: "); scanf("%d",&choice);
    clear_screen();

    if(choice = 1){
        //Create a seed
        time_t seed = time(NULL);
        ppp("Zapisuję twój unikalny seed do katalogu seeds.");
        ppp("Możesz użyć go do wczytania mapy.");

    }
    /*
    //Generate a board
    Board game_board = generate_board(5, seed);
    Player *player_1 = malloc(sizeof(Player)+1);
    Player *player_2 = malloc(sizeof(Player)+1);
    player_1->num = 1;
    player_1->hp = 10;
    player_2->num = 2;
    player_2->hp = 10;
    place_treasure(&game_board,seed);
    place_keys(&game_board,seed);
    populate_board(&game_board,seed);
    player_1->current_room = game_board;
    player_2->current_room = game_board;

    */
    

    return 0;
    
}
