#include <cstdlib>
#include <iostream>

#include "../include/field.h"

int main()
{
    field game;

    while (!game.is_win()) {
        int coord;
        std::cout << "Делай ход: ";
        std::cin >> coord;
        std::cout << std::endl;
        while (!game.make_move(coord)) {
            std::cout << "Занято! Делай ход заново:";
            std::cin >> coord;
        }
        game.get_map();
    }

    switch (game.is_win()) {
        case 1: {
            std::cout << "X - выиграл!";
            break;
        }
        case 2: {
            std::cout << "O - выиграл!";
            break;
        }
        case 3: {
            std::cout << "Никто не выиграл!";
            break;
        }
        default: {
            std::cout << "TODO";
        }
    }

    return 0;
}
