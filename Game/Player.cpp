//
// Created by gio on 11/16/18.
//

#include "Player.h"

Player::Player()
        :name(new std::string), symbol(new std::string) { }

Player::Player(bool turn, std::string* name, std::string* symbol)
        :turn(turn), name(name), symbol(symbol) { }

Player::Player(const Player& player)
        :turn(player.turn), name(player.name), symbol(player.symbol) { }


Player::~Player()
{
    delete name;
    delete symbol;
}

Player& Player::operator=(const Player& player)
{
    if(this != &player)
    {
        name = player.getName();
        symbol = player.getSymbol();
        turn = player.isTurn();
    }
    return *this;
}

std::string* Player::getSymbol() const
{
    return symbol;
}

std::string* Player::getName() const
{
    return name;
}

void Player::setName(std::string* name)
{
    Player::name = name;
}

void Player::setTurn(bool turn)
{
    Player::turn = turn;
}

bool Player::isTurn() const
{
    return turn;
}