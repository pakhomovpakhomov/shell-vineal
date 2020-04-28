#include "../include/UI.h"

UI::UI(field& game) {
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();

    strcpy(line, "[ ][ ][ ]");
    my_win = create_map();
    move(0,1);
}

UI::~UI() {
    endwin();
}

void UI::game_process() {
    while ((ch = getch()) != KEY_F(1)) {
        switch (ch) {
            case KEY_LEFT: {
                getyx(stdscr, y, x);
                move(y, x - 3);
                break;
            }
            case KEY_RIGHT: {
                getyx(stdscr, y, x);
                if (x < 5)
                    move(y, x + 3);
                break;
            }
            case KEY_UP: {
                getyx(stdscr, y, x);
                move(y - 1, x);
                break;
            }
            case KEY_DOWN: {
                getyx(stdscr, y, x);
                if (y < 2)
                    move(y + 1, x);
                break;
            }
            case 10: {   // 10 is enter. KEY_ENTER don't work :(((
                getyx(stdscr, y, x);

                int game_x;
                int game_y = y;
                switch (x) {   // converter from ui x,y to field array x, y
                    case 1: {
                        game_x = 0;
                        break;
                    }
                    case 4: {
                        game_x = 1;
                        break;
                    }
                    case 7: {
                        game_x = 2;
                        break;
                    }
                }

                int game_coord;
                switch (game_y) {
                    case 0: {
                        game_coord = game_x;
                        break;
                    }
                    case 1: {
                        game_coord = game_x + game_y + 2;
                        break;
                    }
                    case 2: {
                        game_coord = game_x + game_y + 4;
                        break;
                    }
                    default: {
                        // TODO: solve this, idk but looks like shit
                    }
                }
                if (game.make_move(game_coord)) {
                    if (team)
                        symbol = 'X';
                    else
                        symbol = 'O';
                    mvprintw(y, x, "%c", symbol);
                    team = !team;
                    move(y, x);
                    wrefresh(my_win);
                }

                switch (game.is_win()) {
                    case 1: {
                        mvprintw(4, 1, "%s", "X - win");
                        break;
                    }
                    case 2: {
                        mvprintw(4, 1, "%s", "0 - win");
                        break;
                    }
                    case 3: {
                        mvprintw(4, 1, "%s", "I win");
                        break;
                    }
                    case 0: {
                        break;
                    }
                    default: {
                        mvprintw(4, 1, "%s", "Todo"); //TODO: solve
                    }
                        break;
                }
            }
        }
    }
}

WINDOW *UI::create_map() {
    WINDOW *local_win;
    local_win = newwin(9,9,0,0);

    mvprintw(0,0,"%s",line);
    mvprintw(1,0,"%s",line);
    mvprintw(2,0,"%s",line);

    wrefresh(local_win); /* Show that box */
    return local_win;
}