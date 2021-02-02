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
    int difficulty = -1;
    show_introduction();
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
        ppp("Podaj poziom trudności, od 1 do 5. Im wyższą liczbę podasz, tym większa będzie mapa.");
        while(difficulty < 1 || difficulty > 5){
            ppp("Wprowadź trudność: ");
            scanf("%d",&difficulty);
            if(difficulty < 1 || difficulty > 5){
                ppp("Nieprawidłowy przedział trudności.");
            }
        }
        difficulty *= 5;
        clear_screen();
        start_game(seed,difficulty);
        clear_screen();
        ppp("Dziękuję za grę. Do zobaczenia następnym razem!");
        ppp("~ Maciej Witkowski\n\n");
        msleep(3000);
        return 0;
    } else if(choice == 2){
        ppp("Wprowadź seed mapy: ");
        scanf("%d", &seed);
        ppp("Wczytano seed.");
        ppp("Podaj poziom trudności, od 1 do 5. Im wyższą liczbę podasz, tym większa będzie mapa.");
        while(difficulty < 1 || difficulty > 5){
            ppp("Wprowadź trudność: ");
            scanf("%d",&difficulty);
            if(difficulty < 1 || difficulty > 5){
                ppp("Nieprawidłowy przedział trudności.");
            }
        }
        difficulty *= 5;
        clear_screen();
        start_game(seed,difficulty);
        clear_screen();
        ppp("Dziękuję za grę. Do zobaczenia następnym razem!");
        ppp("~ Maciej Witkowski\n\n");
        msleep(3000);
        return 0;
    } else{
        return 0;
    }

    return 0;
    
}
