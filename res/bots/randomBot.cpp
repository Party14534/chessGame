#include "randomBot.hpp"

std::string randomBotMove(std::vector<std::string> validMoves){

    //std::cout << "random\n";
    int num = (rand() % validMoves.size());
    return validMoves[num];

}