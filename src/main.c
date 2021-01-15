#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./board/board.h"

int main(){
    time_t seed = time(NULL);
    
    Board xd = generate_board(5, seed);
    return 0;
    
}
