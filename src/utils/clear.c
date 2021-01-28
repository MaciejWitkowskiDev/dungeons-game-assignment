#include "clear.h"

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