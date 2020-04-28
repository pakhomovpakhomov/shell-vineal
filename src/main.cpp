#include <cstdlib>
#include <iostream>

#include "../include/field.h"
#include "../include/UI.h"

WINDOW *create_map();
void destroy_win(WINDOW *local_win);

int main()
{
    field game;
    UI tochka(game);
    tochka.game_process();


    return 0;
}



/*WINDOW *create_newwin(int y, int x)
{ WINDOW *local_win;
    local_win = newwin(HEIGHT, WIDTH, STARTY, STARTX); // TODO: do const
    box(local_win, 0 , 0);
    wrefresh(local_win);
    return local_win;
}*/
