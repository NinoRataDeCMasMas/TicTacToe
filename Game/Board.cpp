//
// Created by gio on 11/16/18.
//

#include <iostream>
#include "Board.h"

Board::Board()
{
    board = new std::string*[3];
    for(int i = 0; i < 3; ++i)  board[i] = new std::string[3];
    numberOfMoves = 9;
    initialize();
}

Board::Board(const Board& board)
//        :board(board.board), numberOfMoves(board.numberOfMoves) { }
{
    numberOfMoves = board.getNumberOfMoves();

    this->board = new std::string*[3];
    for(int i = 0; i < 3; ++i)  this->board[i] = new std::string[3];

    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            this->board[i][j] = board.getBoard()[i][j];
}

Board::~Board()
{
    for(int i = 0; i < 3; ++i)  delete[] board[i];
    delete[] board;
}

Board& Board::operator=(const Board& board)
{
    if(this != &board)
    {
        numberOfMoves = board.getNumberOfMoves();
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                this->board[i][j] = board.getBoard()[i][j];
    }
    return *this;
}

std::string** Board::getBoard() const
{
    return board;
}

int Board::getNumberOfMoves() const
{
    return numberOfMoves;
}
/**
 * @brief inicializar tablero con sus posiciones
 */
void Board::initialize()
{
    int position = 1;
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
        {
            board[i][j] = std::to_string(position);
            position++;
        }
}
/**
 * @brief imprimir el tablero en pantalla
 */
void Board::print()
{
    std::cout << std::endl;
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            if(j < 2)
                std::cout << " " << board[i][j] << " |";
            else
                std::cout << " " << board[i][j] << " ";
        }
        if(i < 2)
            std::cout << "\n-----------" << std::endl;
    }
    std::cout << std::endl;
}
/**
 * @brief marcar un simbolo en el tablero
 * @param x renglon
 * @param y columna
 * @param symbol simbolo a grabar
 * @return operacion exitosa
 */
bool Board::markPosition(int x, int y, std::string symbol)
{
    if(board[x][y] != "X" && board[x][y] != "0")
    {
        board[x][y] = symbol;
        numberOfMoves--;
        return true;
    }
    else
        return false;
}