#include "../include/field.h"

bool field::make_move(int coord) {
    if (!is_movable(coord))
        return false;

    progress++;
    team = !team;

    map[coord] = team + 1;

    return true;
}

bool field::is_movable(int coord) {
    return !map[coord];
}

int field::is_win() {
    // check rows
    if ((map[0] == map[1]) && (map[0] == map[2]) && (map[0] != 0))
        return map[0];

    if ((map[3] == map[4]) && (map[3] == map[5]) && (map[3] != 0))
        return map[3];

    if ((map[6] == map[7]) && (map[6] == map[8]) && (map[6] != 0))
        return map[6];

    //check rows
    if ((map[0] == map[3]) && (map[0] == map[6]) && (map[0] != 0))
        return map[0];

    if ((map[1] == map[4]) && (map[1] == map[7]) && (map[1] != 0))
        return map[1];

    if ((map[2] == map[5]) && (map[2] == map[8]) && (map[2] != 0))
        return map[2];

    // check \ and /
    if ((map[0] == map[4]) && (map[0] == map[8]) && (map[0] != 0))
        return map[0];

    if ((map[2] == map[4]) && (map[2] == map[6]) && (map[2] != 0))
        return map[2];

    if (progress >= 9)
        return 3;

    return 0;
}

void field::get_map() {
    for (int i = 0; i < 3; ++i) {
        std::cout << map[i] << " ";
    }

    std::cout << std::endl;

    for (int i = 0; i < 3; ++i) {
        std::cout << map[i+3] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 3; ++i) {
        std::cout << map[i+6] << " ";
    }
    std::cout << std::endl;
}

int field::get_team() const {
    return team;
}

field::field() = default;

field::~field() = default;