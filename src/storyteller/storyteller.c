#include "storyteller.h"
#include "textheaders.h"
#include "../utils/prettyprint.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>

//Room props work like this:
/*
    props[n] = true - 
    means that room contains a thing numbered n:

    0 - Trap
    1 - Riddle
    2 - Shortcut
    3 - Guard
    4 - BlockedPath
    5 - Pickaxe
    6 - Sword

*/

//Print a room description.
char* print_room_desc(Room* room, Player* turn){
    
    srand(time(NULL));
    int prop = -1;

    if(room->room_type == 1){ 
        ppp("Wróciłeś do pomieszczenia, w którym rozpoczęła się twoja podróż."); 
        return "rt";
    } else {
        ppp(random_room_header());
    }

    for(int i = 0; i < 7; i++){
        if(room->props[i]){
            prop = i;
        }
    }
    if(prop == -1){
        bool roomHasTurnPlayerKey = (turn->num == 1 && room->hasP1Key) || (turn->num == 2 && room->hasP2Key);
        if(room->hasTreasure){
            ppp("Widzisz w pokoju wielką, ciężką skrzynię. Odnalazłeś to czego poszukiwałeś.");
        }
        if(roomHasTurnPlayerKey){
            ppp("Dostrzegasz w pokoju złoty klucz. Czujesz, że jest przeznaczony dla Ciebie.");
        } else if((room->hasP1Key || room->hasP2Key)){
            ppp("Dostrzegasz w pokoju złoty klucz. Niestety, nie jest przeznaczony dla Ciebie.");
        }
    } else{
        //Print a trap description
        if(prop == 0){
            ppp("Na środku pomieszczenia dostrzegasz dźwignię.\nZa nią znajduje się duża, wycelowana prosto w ciebie kusza, podłączona do dziwnego mechanizmu.\nCzy pociągniesz za dźwignię?");
            int correct = rand() % (2 + 1 - 1) + 1;
            if(correct == 1){
                return "t1";
            } else {
                return "t2";
            }
        }
        if(prop == 1){
            char* riddle = random_riddle();
            ppp("Wchodzisz do tajemniczego pokoju z napisami na ścianach.");
            ppp("Wśród nich dostrzegasz czytelny napis:");
            ppp(riddle);
            ppp("Co to może być?");
            return &riddle[0];
        } else if(prop == 2){
            ppp("Dostrzegasz schody do podziemnego przejścia. Inskrypcja na ścianie głosi 'wrócisz tam, skąd przybyłeś.'");
            return "ss";
        } else if(prop == 3){
            ppp("W rogu pomieszczenia widzisz parę błyszczących oczu.");
            ppp("O cholera! To strażnik! W pełnej zbroi, z mieczem przy pasie!\nCoraz szybszym krokiem porusza się w twoją stronę.");
            ppp("Jak zareagujesz?\n");
            return "gg";
        } else if(prop == 4){
            ppp("Widzisz, że w tym pomieszczeniu znajdują się drzwi. Niestety zasypane są kamieniami.");
            ppp("Gruz jest zbyt ciężki, aby przenieść go rękoma.");
            if(turn->hasPickaxe){
                ppp("Miałeś szczęście, że podniosłeś ten kilof.");
                ppp("Oczyścić przejście?");
            }
            return turn->hasPickaxe ? "bpu" : "bpl";
        } else if(prop == 5){
            ppp("W tym pomieszczeniu nic nie ma!");
            ppp("Chwila! Na ziemi leży stary, zardzewiały kilof.");
            ppp("Wydaje się bezużyteczny, ale może kiedyś się przyda?");
            ppp("Podniesiesz kilof?");
            return "px";
        } else if(prop == 6){
            ppp("Na ziemi leży stalowy miecz.");
            ppp("Nie chcesz myśleć o tym, dlaczego się tu znalazł...");
            ppp("... ani do kogo wcześniej należał...");
            ppp("Podniesziesz miecz?");
            return "sw";
        }
    }
}

void print_movement_opts(Room* room){
    ppp("Wybierz ruch:\n");
    if(room->left != NULL){
        printf("l - aby iśc w lewo.\n");
    }
    if(room->right != NULL){
        printf("p - aby iść w prawo.\n");
    }
    if(room->prev != NULL){
        printf("c - aby się cofnąć.\n");
    }
}

//Print player stats.
void print_player_stats(Player* player){
    char player_info[40] = {'\0'};
    char eq[40] = {'\0'};
    sprintf(player_info,"Tura gracza %d. \nMasz %d/10 punktów życia.",player->num,player->hp);
    if(!player->hasSword && !player->hasPickaxe){
        sprintf(eq,"Nie masz żadnych przedmiotów.");
    } else if(player->hasSword && !player->hasPickaxe){
        sprintf(eq,"Masz przy sobie miecz.");
    } else if(!player->hasSword && player->hasPickaxe){
        sprintf(eq,"Masz przy sobie kilof.");
    } else if(player->hasSword && player->hasPickaxe){
        sprintf(eq,"Masz przy sobie miecz i kilof.");
    }
    ppp(player_info);
    ppp(eq);
}

int handle_room(Room* room, Player* player, Player* rival){
    char* desc_info = print_room_desc(room,player);

}