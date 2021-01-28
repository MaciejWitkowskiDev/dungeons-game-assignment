#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "./player/player.h"

#ifdef _WIN32
	    void clear_screen(){
            system("cls");
        }
	#elif __linux__
	    void clear_screen(){
            system("clear");
        }
	#elif __unix__
	    void clear_screen(){
            system("clear");
        }
	#else
        void clear_screen(){
           printf("Wyglada na to ze uzywasz niewspieranego systemu!!\n");
           printf("Nie wszystkie funkcje programu beda dzialac poprawnie!\n");
           return 0;
        }
	    
#endif

int main(){
    clear_screen();
    time_t seed = time(NULL);
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
    clear_screen();
    
    return 0;
    
}
