//
// Created by gio on 11/16/18.
//

#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include <string>

class Board {
    std::string** board;
    int   numberOfMoves;

public:
    Board(); // constructor por defecto
    Board(const Board& board); // constructor copia
    virtual ~Board(); // destructor

    virtual Board& operator=(const Board& board); // operador de asignacion (deepCopy)

    // getters
    std::string** getBoard() const;
    int getNumberOfMoves() const;

    void initialize(); // inicializar tablero con sus posiciones
    void print(); // imprimir el tablero en pantalla
    bool markPosition(int x, int y, std::string symbol); // marcar un simbolo en el tablero
};

#endif //TICTACTOE_BOARD_H