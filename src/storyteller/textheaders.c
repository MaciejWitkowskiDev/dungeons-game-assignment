#include "textheaders.h"
#include <time.h>
#include <stdlib.h>

char room_headers[5][500] = {
                         "Otwierasz ciężkie, drewniane drzwi. Twoim oczom ukazuje się ciemny pokój, delikatnie oświetlony pochodniami.",
                         "Za wielkimi drzwiami znajduje się kolejny, ciemny pokój, słabo oświetlony ogniem pochodni.",
                         "Po przejściu przez drzwi Twoim oczom ukazuje się kamienna komnata, delikatnie oświetlona ogniem pochodni.",
                         "Gdy otwierasz drzwi, zaczynasz dostrzegać ciepłą łunę światła. Twoim oczom ukazuje się słabo oświetlony ogniem pochodni kamienny pokój.",
                         "Otwierając drzwi dostrzegasz światło. Twoje nadzieje o końcu podróży szybko jednak okazują się płonne. Twoim oczom ukazuje się kolejny pokój."
                     };


//Return random room header
char* random_room_header(){
    srand(time(NULL));
    int header = rand() % (4 + 1 - 0) + 0;
    return &room_headers[header][0];
}

//Return the root header
char* root_header(){
    return "Budzicie się w ciemnym pomieszczeniu. Lata poszukiwań doprowadziły was właśnie tutaj.\nSkarb jest już blisko. \nPozostaje pytanie, kto pierwszy go znajdzie? \nNie macie wątpliwości - jedyna droga prowadzi naprzód. \nPora rozpocząć poszukiwania.\n\n";
}