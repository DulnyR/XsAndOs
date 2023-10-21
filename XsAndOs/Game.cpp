#include <iostream>
#include <limits>
#include "Grid.h"

using namespace std;

int main() {
    Grid myGrid;
    cout << "Welcome to Xs and Os!" << endl;
    char winner = ' ';
    char player = 'X';
    string xInput, yInput;
    int x, y;
    while(!myGrid.checkForWin(winner))
    {
        do {
            cout << "Player " << player << ", enter x coordinate from 0 -> 2: " << endl;
            cin >> xInput;
            if(xInput.size() == 1 && isdigit(xInput.at(0))) x = xInput.at(0) - '0';
            else x = -1;
        } while(x > 2 or x < 0);
        do {
            cout << "Player " << player << ", enter y coordinate from 0 -> 2: " << endl;
            cin >> yInput;
            if(yInput.size() == 1 && isdigit(yInput.at(0))) y = yInput.at(0) - '0';
            else y = -1;
        } while(y > 2 or y < 0);
        Square chosenSquare = myGrid.squares[x][y];
        if(!myGrid.markSquare(player, x, y)) cout << "Square already chosen try again!" << endl;
        else {
            myGrid.markSquare(player, x, y);
            myGrid.drawGrid();
            if(myGrid.isFull()) break;
            if(player == 'X') player = 'O';
            else player = 'X';
        }
    }
    if(winner == 'X' || winner == 'O') cout << "Player " << winner << " wins!" << endl;
    else cout << "No one wins, grid is full!";
}
