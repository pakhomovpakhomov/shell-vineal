#ifndef TIC_TAC_FIELD_H
#define TIC_TAC_FIELD_H

#include <vector>
#include <iostream>
#include <algorithm>

class field {
private:
    std::vector<int> map {0, 0, 0, 0, 0, 0, 0, 0, 0}; // 0 - null, 1 - x, 2 - o
    int progress = 0; //8 - max
    bool team = false;

    bool is_movable(int coord);
public:
    field();
    ~field();
    bool make_move(int coord);
    int is_win(); // 0 - no, 1 - x win, 2 - o win, 3 - draw
    void get_map(); //test

};


#endif
