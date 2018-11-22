#include <iostream>
#include "Game/TicTacToeGame.h"

using namespace std;

int main()
{
    auto* ticTacToeGame = new TicTacToeGame();
    ticTacToeGame->play();
    return 0;
}