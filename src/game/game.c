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

    //REMOVE LATER!!
    for(int i = 0; i < 7; i++){
        game_board->left->props[i] = false;
    }
    game_board->left->props[1] = true;

    //Create player objects
    Player *player_1 = malloc(sizeof(Player)+1);
    Player *player_2 = malloc(sizeof(Player)+1);

    player_1->hasKey = false;
    player_1->hasPickaxe = false;
    player_1->hasSword = false;
    
    player_2->hasKey = false;
    player_2->hasPickaxe = false;
    player_2->hasSword = false;

    player_1->num = 1;
    player_1->hp = 10;
    player_2->num = 2;
    player_2->hp = 10;

    player_1->current_room = game_board;
    player_2->current_room = game_board;

    //Set turn to player_1
    Player *turn = player_1;
    Player *rival = player_2;

    ppp("Budzicie się w ciemnym pomieszczeniu. Lata poszukiwań doprowadziły was właśnie tutaj.\nSkarb jest już blisko. \nPozostaje pytanie, kto pierwszy go znajdzie? \nNie macie wątpliwości - jedyna droga prowadzi naprzód. \nPora rozpocząć poszukiwania.\n\n");
    msleep(2000);

    while(input != "exit"){
        rival = turn->num == 1 ? player_2 : player_1;
        clear_screen();
        print_player_stats(turn);
        print_movement_opts(turn->current_room);
        printf("\nGdzie chcesz pójść? : "); scanf(" %c",&input);

        if(input[0] == 'l' && turn->current_room->left != NULL){
            turn->current_room = turn->current_room->left;
        } else if(input[0] == 'p' && turn->current_room->right != NULL){
            turn->current_room = turn->current_room->right;
        } else if(input[0] == 'c' && turn->current_room->prev != NULL){
            turn->current_room = turn->current_room->prev;
        } else if(input[0] == 'e'){
            return;
        } else {
            clear_screen();
            continue;
        }
        handle_room(turn->current_room,turn, rival);

        if(turn->num == 1) { turn = player_2; }
        else { turn = player_1; }

        continue;
    }



    
}