//
// Created by gio on 11/16/18.
//

#ifndef TICTACTOE_TICTACTOEGAME_H
#define TICTACTOE_TICTACTOEGAME_H

#include <stack>
#include <iostream>
#include "Player.h"
#include "Board.h"
#include "Memento/GameState.h"
#include "Memento/Memento.h"

class TicTacToeGame {
    Player* player1;
    Player* player2;
    Board*  board;
    Memento backward, forward;

    void save(); // guardar el estado actual en el memento
    void undo(); // restaurar un estado anterior
    void redo();

    void initPlayers(); // construir instancias para player1 y player2
    void changeTurn(); // cambiar el turno de los jugadores
    void nextTurn(); // indicar en pantalla cual es el turno correspondiente
    void endGame(); // indicar en pantalla el final del juego

    std::string* getSymbolTurn(); // tomar el simbolo representativo del jugador al turno
    bool makeMove(int index); // marcar la jugada indicada en el tablero

    Player* getPlayer(std::string symbol); // identificar al jugador del simbolo proporcionado
    Player* checkForWinner(); // determinar al jugador ganador en base a las condiciones del tablero
    bool doWeHaveWinner(); // determinar a un ganador

public:
    TicTacToeGame(); // constructor por defecto
    TicTacToeGame(const TicTacToeGame& game); // constructor copia
    virtual ~TicTacToeGame(); // destructor

    void play(); // jugar
};

#endif //TICTACTOE_TICTACTOEGAME_H