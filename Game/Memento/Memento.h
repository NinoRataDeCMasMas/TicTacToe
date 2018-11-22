//
// Created by gio on 11/17/18.
//

#ifndef TICTACTOE_MEMENTO_H
#define TICTACTOE_MEMENTO_H

#include "GameState.h"
#include <stack>

class Memento {
    std::stack<GameState*> record;

public:
    Memento();
    virtual ~Memento();

    void save(GameState* state);
    GameState* restore();
};

#endif //TICTACTOE_MEMENTO_H