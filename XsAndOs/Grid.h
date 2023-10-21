//
// Created by Radek on 21/10/2023.
//

#ifndef XSANDOS_GRID_H
#define XSANDOS_GRID_H

#include "Square.h"
#include <vector>
using namespace std;

class Grid {

public:
    Grid();
    vector<vector<Square>> squares;
    bool checkForWin(char& winner);
    void drawGrid();
    bool isFull();
    bool markSquare(char c, int x, int y);
};


#endif //XSANDOS_GRID_H
