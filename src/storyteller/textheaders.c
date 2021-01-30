#include "textheaders.h"
#include <time.h>
#include <stdlib.h>

char room_headers[5][500] = {
                         "Otwierasz ciężkie, drewniane drzwi.\nTwoim oczom ukazuje się ciemny pokój, delikatnie oświetlony pochodniami.",
                         "Za wielkimi drzwiami znajduje się kolejny, ciemny pokój, słabo oświetlony ogniem pochodni.",
                         "Po przejściu przez drzwi Twoim oczom ukazuje się kamienna komnata, delikatnie oświetlona ogniem pochodni.",
                         "Gdy otwierasz drzwi, zaczynasz dostrzegać ciepłą łunę światła.\nTwoim oczom ukazuje się słabo oświetlony ogniem pochodni kamienny pokój.",
                         "Otwierając drzwi dostrzegasz światło.\nTwoje nadzieje o końcu podróży szybko jednak okazują się płonne.\nTwoim oczom ukazuje się kolejny pokój."
                     };

char riddles[5][1000] = {
                         //horyzont
                         "Jestem granicą, co nie zna granic. Zmierzanie ku mnie nie zda się na nic, bo ja oddalam się z każdym krokiem, choć zawsze jestem jak sięgnąć okiem. Co za mną leży, wszyscy chcą wiedzieć, ale ja leżę zawsze na przedzie.",
                         //papier
                         "Lekki jak piórko, jak trzcina giętki i byle podmuch drze go na strzępki. Zrób z niego miazgę, wciśnij do prasy, a padną przed nim pokotem lasy. Choć cienki, kryje wszechświaty całe – czym chcesz, zapełnisz płaszczyzny białe, co nań przelejesz, zawsze się zmieści, tu nawet pustka nabiera treści.",
                         //czas
                         "Coś, przed czym w świecie nic nie uciecze, co gnie żelazo, przegryza miecze, pożera ptaki, zwierzęta, ziele, najtwardszy kamień na mąkę miele, królów nie szczędzi, rozwala mury, poniża nawet najwyższe góry.",
                         //wiatr
                         "Brak mu skrzydeł, a trzepocze, nie ma ust, a mamrocze, nie ma nóg, a pląsa, nie ma zębów, a kąsa.",
                         //ryba
                         "Nie oddycha, a żyje, nie pragnie, a wciąż pije."
                     };



//Return random room header
char* random_room_header(){
    srand(time(NULL));
    int header = rand() % (4 + 1 - 0) + 0;
    return &room_headers[header][0];
}

//Return a random riddle
char* random_riddle(){
    srand(time(NULL));
    int header = rand() % (4 + 1 - 0) + 0;
    return &riddles[header][0];
}