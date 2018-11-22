//
// Created by gio on 11/17/18.
//

#include "Memento.h"

Memento::Memento() { }

Memento::~Memento() { }

void Memento::save(GameState* state)
{
    record.push(state);
}

GameState* Memento::restore()
{
    if(!record.empty())
    {
        auto* recovery = record.top();
        record.pop();
        return recovery;
    }
    return nullptr;
}
