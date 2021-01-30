#include "game.h"
#include "../player/player.h"
#include "../board/traverser.h"
#include "../utils/clear.h"
#include "../utils/prettyprint.h"
#include "../storyteller/storyteller.h"


void start_game(time_t seed){

    char input[10];

    ppp("Generuję losową planszę...");
    clear_screen();
    //Generate a board
    Board game_board = generate_board(5, seed);
    place_treasure(&game_board,seed);
    place_keys(&game_board,seed);
    populate_board(&game_board,seed);

    //Create player objects
    Player *player_1 = malloc(sizeof(Player)+1);
    Player *player_2 = malloc(sizeof(Player)+1);
    player_1->num = 1;
    player_1->hp = 10;
    player_2->num = 2;
    player_2->hp = 10;
    player_1->current_room = game_board;
    player_2->current_room = game_board;

    //Set turn to player_1
    Player *turn = player_1;
    Player *rival = player_2;

    while(input != "exit"){
        rival = turn->num == 1 ? player_2 : player_1;
        
        print_room_desc(turn->current_room);
        //print_player_stats(turn);
        ppp("Co postanowisz zrobić? : ");
        scanf("%s",&input);

        //if(handle_event(input, turn, rival) == -1){
        //    return;
        //}

        if(turn->num == 1) { turn = player_2; }
        else { turn = player_1; }

        continue;
    }



    
}