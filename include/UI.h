#ifndef TIC_TAC_UI_H
#define TIC_TAC_UI_H

#include <ncurses.h>
#include <cstring>
#include "../include/field.h"

class UI {
private:
    field game;
    int team;
    WINDOW *my_win;
    int ch;
    int y, x;
    char symbol = 'X';
    char line[];

    WINDOW *create_map();
public:
    void game_process();
    UI(field& game);
    ~UI();
};


#endif
