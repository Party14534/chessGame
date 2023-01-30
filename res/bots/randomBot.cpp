#include "randomBot.hpp"

std::string randomBotMove(std::vector<std::string> validMoves){

    int num = (rand() % validMoves.size());
    return validMoves[num];

}