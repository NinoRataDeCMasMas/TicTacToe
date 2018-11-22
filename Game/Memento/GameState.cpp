//
// Created by gio on 11/16/18.
//

#include "GameState.h"

GameState::GameState()
{
    this->player1 = nullptr;
    this->player2 = nullptr;
    this->board = nullptr;
}

GameState::GameState(const Player& player1, const Player& player2, const Board& board)
{
    this->player1 = new Player(player1);
    this->player2 = new Player(player2);
    this->board = new Board(board);
}

Player* GameState::getPlayer1() const
{
    return player1;
}

Player* GameState::getPlayer2() const
{
    return player2;
}

Board* GameState::getBoard() const
{
    return board;
}

void GameState::setPlayer1(Player* player1)
{
    GameState::player1 = player1;
}

void GameState::setPlayer2(Player* player2)
{
    GameState::player2 = player2;
}

void GameState::setBoard(Board* board)
{
    GameState::board = board;
}





