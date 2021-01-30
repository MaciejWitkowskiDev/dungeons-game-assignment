#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>    
#include <unistd.h>
#include "./utils/clear.h"
#include "./utils/prettyprint.h"
#include "./utils/ui.h"
#include "./utils/filehandler.h"
#include "./game/game.h"

int main(){

    int choice = -1;
    time_t seed;
    //show_introduction();
    show_main_menu();
    printf("\nTwój wybór: "); scanf("%d",&choice);
    clear_screen();

    if(choice == 1){
        //Create a seed
        seed = time(NULL);
        ppp("Zapisuję unikalny seed mapy do katalogu seeds.");
        ppp("Można użyć go do wczytania mapy.");
        if(save_seed(seed) == -1){
            ppp("Nie udało mi się zapisać seeda. Sprawdź uprawnienia.");
        } else {
            ppp("Zrobione.");
        }
        clear_screen();
        start_game(seed);
        clear_screen();
        ppp("Dziękuję za grę. Do zobaczenia następnym razem!");
        ppp("~ Maciej Witkowski");
        return 0;
    } else if(choice == 2){
        ppp("Wprowadź seed mapy: ");
        scanf("%d", &seed);
        ppp("Wczytano seed.");
        clear_screen();
        start_game(seed);
        clear_screen();
        ppp("Dziękuję za grę. Do zobaczenia następnym razem!");
        ppp("~ Maciej Witkowski");
        return 0;
    } else{
        return 0;
    }

    return 0;
    
}
