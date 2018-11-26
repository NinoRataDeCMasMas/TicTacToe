//
// Created by gio on 11/16/18.
//

#include "TicTacToeGame.h"
#include "Memento/Memento.h"

/**
 * @brief constructor por defecto
 */
TicTacToeGame::TicTacToeGame()
        :board(new Board()) { }
/**
 * @brief constructor copia
 */
TicTacToeGame::TicTacToeGame(const TicTacToeGame& game)
        :player1(game.player1), player2(game.player2), board(game.board) { }
/**
 * @brief destructor
 */
TicTacToeGame::~TicTacToeGame()
{
    delete player1;
    delete player2;
    delete board;
}
/**
 * @brief guardar el estado actual en el memento
 */
void TicTacToeGame::save()
{
    auto* state = new GameState(*player1, *player2, *board);
    backward.save(state);
}
/**
 * @brief restaurar un estado anterior
 */
void TicTacToeGame::undo()
{
    forward.save(backward.restore());
    auto* recovery = backward.restore();

    if(recovery)
    {
        *player1 = *recovery->getPlayer1();
        *player2 = *recovery->getPlayer2();
        *board = *recovery->getBoard();
        std::cout << "jugada deshecha. " << std::endl;
    }
    else
        std::cout << "no se puede deshacer la jugada. " << std::endl;
}
/**
 *
 */
void TicTacToeGame::redo()
{
    auto* recovery = forward.restore();

    if(recovery)
    {
        *player1 = *recovery->getPlayer1();
        *player2 = *recovery->getPlayer2();
        *board = *recovery->getBoard();
        std::cout << "jugada restituida. " << std::endl;
    }
    else
        std::cout << "no se puede restituir la jugada. " << std::endl;
}
/**
 * @brief construir instancias para player1 y player2
 */
void TicTacToeGame::initPlayers()
{
    std::string *cross = new std::string("X"), *nought = new std::string("0");
    std::string *namePayer1 = new std::string(), *namePayer2 = new std::string();

    std::cout << "Proporcione el nombre del jugador 1" << std::endl;
    std::cin >> *namePayer1;
    player1 = new Player(true, namePayer1, cross);

    std::cout << "Proporcione el nombre del jugador 2" << std::endl;
    std::cin >> *namePayer2;
    player2 = new Player(false, namePayer2, nought);
}
/**
 * @brief cambiar el turno de los jugadores
 */
void TicTacToeGame::changeTurn()
{
    if(player1->isTurn())
    {
        player1->setTurn(false);
        player2->setTurn(true);
    }
    else
    {
        player1->setTurn(true);
        player2->setTurn(false);
    }
}
/**
 * @brief indicar en pantalla cual es el turno correspondiente
 */
void TicTacToeGame::nextTurn()
{
    std::string bannerOne = *player1->getName() + ":[" + *player1->getSymbol() + "]Elija un casilla entre 1 y 9 "
                            + ", 'u' para deshacer una jugada y 'r' para restituir una jugada deshecha: ";
    std::string bannerTwo = *player2->getName() + ":[" + *player2->getSymbol() + "] Elija un casilla entre 1 y 9 "
                            + ", 'u' para deshacer una jugada y 'r' para restituir una jugada deshecha: ";
    std::cout << (player1->isTurn() ? bannerOne : bannerTwo) << std::endl;
}
/**
 * @brief indicar en pantalla el final del juego
 */
void TicTacToeGame::endGame()
{
    std::string endGame = "Fin del juego";
    std::cout << endGame << std::endl;
}
/**
 * @brief tomar el simbolo representativo del jugador al turno
 * @return simbolo del jugador al turno
 */
std::string* TicTacToeGame::getSymbolTurn()
{
    return (player1->isTurn() ? player1 : player2)->getSymbol();
}
/**
 * @brief marcar la jugada indicada en el tablero
 * @param index numero de casilla
 * @return operacion exitosa
 */
bool TicTacToeGame::makeMove(int index)
{
    int column = 0, row = 0, LineLenght = 3;

    if(index >= 0 && index <= 9)
    {
        index = index - 1;
        row = index / LineLenght;
        column = index % LineLenght;

        return board->markPosition(row, column, *getSymbolTurn());
    }
    else
        return false;
}
/**
 * @brief identificar al jugador del simbolo proporcionado
 * @param symbol simbolo de jugador
 * @return jugador correspondiente
 */
Player* TicTacToeGame::getPlayer(std::string symbol)
{
    return symbol == *player1->getSymbol() ? player1 : symbol == *player2->getSymbol() ? player2 : nullptr;
}
/**
 * @brief determinar al jugador ganador en base a las condiciones del tablero
 * @return jugador ganador
 */
Player* TicTacToeGame::checkForWinner()
{
bool CONDITION_TWO = board->getBoard()[1][1] == board->getBoard()[0][0]
                  && board->getBoard()[1][1] == board->getBoard()[2][2];

bool CONDITION_THREE = board->getBoard()[1][1] == board->getBoard()[0][2]
                    && board->getBoard()[1][1] == board->getBoard()[2][0];

    for(int i = 0; i < 3; i++)
        for(int j = 1; j < 2; j++)
        {
            bool CONDITION_ONE = board->getBoard()[j][i] == board->getBoard()[j - 1][i]
                              && board->getBoard()[j][i] == board->getBoard()[j + 1][i];
            if(CONDITION_ONE) return getPlayer(board->getBoard()[j][i]);
        }

    if(CONDITION_TWO) return getPlayer(board->getBoard()[1][1]);
    if(CONDITION_THREE) return getPlayer(board->getBoard()[1][1]);
    return nullptr;
}
/**
 * @brief determinar a un ganador
 * @return juego acabado
 */
bool TicTacToeGame::doWeHaveWinner()
{
    Player* player = checkForWinner();

    if(player != nullptr)
    {
        std::cout << "El ganador es " << *player->getName() << std::endl;
        return true;
    }
    if(board->getNumberOfMoves() == 0)
    {
        std::cout << "Empate" << std::endl;
        return true;
    }
    return false;
}
/**
 * @brief jugar
 */
void TicTacToeGame::play()
{
    char option = '0';

    initPlayers( ); // construir instancias para player1 y player2
    nextTurn( ); // indicar en pantalla el turno correspondiente
    save(); // guardar el primer estado de la partida

    while(std::cin >> option)
    {
        switch(option)
        {
        // deshacer
        case 'u':
                undo();
                board->print( ); // imprimir el tablero en pantalla
            break;

        // restituir
        case 'r':
                redo();
                board->print( ); // imprimir el tablero en pantalla
            break;

        default:
            if(makeMove(option - '0'))
            {
                changeTurn( ); // cambiar el turno de los jugadores
                board->print( ); // imprimir el tablero en pantalla
            }
            else
            {
                std::string banner = "La casilla esta ocupada o no existe, Elija otra por favor";
                std::cout << banner << std::endl;
            }
            break;
        }

        save(); // guardar el estado actual de la partida

        if(doWeHaveWinner())
        {
            endGame(); // indicar en pantalla el final del juego
            break;
        }

        nextTurn( );
    }
}


