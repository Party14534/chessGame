#include "generateDangerMaps.hpp"

void generateWhiteDangerMap(std::vector<std::vector<char>> &board){

    whiteDangerMap = 0;

    for(int i = 0; i < chessPieces.size(); i++){
        if(isupper(chessPieces[i].type)){
            chessPieces[i].getValidMoves(board);
            for(int j = 0; j < chessPieces[i].validMoves.size(); j++){
                
                int coord1 = int(chessPieces[i].validMoves[j][2]) - 48;
                int coord2 = int(chessPieces[i].validMoves[j][3]) - 48;
                int num = (coord2*8) + coord1;

                int64_t bit = 1;
                bit = bit << num;
                whiteDangerMap = whiteDangerMap | bit;

            }
        }

    }

    /*std::bitset<64> bits(whiteDangerMap);
    std::cout << "\nwhite danger map \n";
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){

            std::cout << bits[(i * 8) + j] << " ";

        }
        std::cout << "\n";
    }
    std::cout << "\n";*/

}


void generateBlackDangerMap(std::vector<std::vector<char>> &board){

    blackDangerMap = 0;

    for(int i = 0; i < chessPieces.size(); i++){

        if(!isupper(chessPieces[i].type)){
        chessPieces[i].getValidMoves(board);
            for(int j = 0; j < chessPieces[i].validMoves.size(); j++){

                int coord1 = int(chessPieces[i].validMoves[j][2]) - 48;
                int coord2 = int(chessPieces[i].validMoves[j][3]) - 48;
                int num = coord2*8 + coord1;
                int64_t bit = 1;
                bit = bit << num;
                blackDangerMap = blackDangerMap | bit;

            }
        }

    }

    /*std::bitset<64> bits(blackDangerMap);
    std::cout << "\nblack danger map \n";
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){

            std::cout << bits[(i * 8) + j] << " ";

        }
        std::cout << "\n";
    }
    std::cout << "\n";*/

}