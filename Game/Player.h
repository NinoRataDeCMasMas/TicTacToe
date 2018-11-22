//
// Created by gio on 11/16/18.
//

#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H

#include <string>

class Player {
    bool turn;
    std::string* name;
    std::string* symbol;

public:
    Player(); // constructor por defecto
    Player(bool turn, std::string* name, std::string* symbol); // constructor parametrizado
    Player(const Player& player); // constructor copia
    virtual ~Player(); // destructor

    virtual Player& operator=(const Player& player); // operador de asignacion (deepCopy)

    // getters
    std::string* getSymbol() const;
    std::string* getName() const;
    bool isTurn() const;

    // setters
    void setName(std::string* name);
    void setTurn(bool turn);
};

#endif //TICTACTOE_PLAYER_H