cmake_minimum_required(VERSION 3.12)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 14)

add_executable(TicTacToe main.cpp Game/Player.cpp Game/Player.h Game/Board.cpp Game/Board.h Game/Memento/GameState.cpp Game/Memento/GameState.h Game/TicTacToeGame.cpp Game/TicTacToeGame.h Game/Memento/Memento.cpp Game/Memento/Memento.h)