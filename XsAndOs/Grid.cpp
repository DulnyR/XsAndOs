//
// Created by Radek on 21/10/2023.
//
#include <iostream>
#include "Grid.h"
using namespace std;

vector<vector<Square>> squares;

Grid::Grid() {
    squares.resize(3, vector<Square>(3));
}

bool Grid::checkForWin(char& winner) {
    //Diagonals
    if(squares[0][0].character == squares[1][1].character &&
       squares[1][1].character == squares[2][2].character) {
        winner = squares[0][0].character;
        if (winner == ' ') return false;
        return true;
    }
    if(squares[0][2].character == squares[1][1].character &&
       squares[1][1].character == squares[2][0].character) {
        winner = squares[0][2].character;
        if (winner == ' ') return false;
        return true;
    }
    for(int i = 0; i < 3; i++) {
        //Rows
        if(squares[i][0].character == squares[i][1].character &&
           squares[i][1].character == squares[i][2].character) {
            winner = squares[i][0].character;
            if (winner == ' ') return false;
            return true;
        }
        //Columns
        if(squares[0][i].character == squares[1][i].character &&
           squares[1][i].character == squares[2][i].character) {
            winner = squares[0][i].character;
            if (winner == ' ') return false;
            return true;
        }
    }
    return false;
}

void Grid::drawGrid() {
    cout << "   0   1   2" << endl << "0 ";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << ' ' << squares[i][j].character << ' ';
            if(j != 2) cout << '|';
            else {
                cout << endl;
                if(i != 2){
                    cout << "  ---|---|---" << endl << (i + 1) << ' ';
                }
            }
        }
    }
}

bool Grid::isFull() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(squares[i][j].character == ' ') return false;
        }
    }
    return true;
}

bool Grid::markSquare(char c, int x, int y) {
    char currentChar = squares[y][x].character;
    if(currentChar == 'X' or currentChar == 'O') {
        return false;
    }
    else {
        squares[y][x].character = c;
        return true;
    }
}

