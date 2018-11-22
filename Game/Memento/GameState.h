//
// Created by gio on 11/16/18.
//

#ifndef TICTACTOE_GAMESTATE_H
#define TICTACTOE_GAMESTATE_H

#include "../Player.h"
#include "../Board.h"

class GameState {
    Player* player1;
    Player* player2;
    Board*  board;

public:
    GameState(); // constructor por defecto
    GameState(const Player& player1, const Player& player2, const Board& board); // constructor para deepCopy

    // getters
    Player* getPlayer1() const;
    Player* getPlayer2() const;
    Board* getBoard() const;

    // setters
    void setPlayer1(Player* player1);
    void setPlayer2(Player* player2);
    void setBoard(Board* board);
};

#endif //TICTACTOE_GAMESTATE_H
