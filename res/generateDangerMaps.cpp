#include "generateDangerMaps.hpp"

void generateWhiteDangerMap(std::vector<std::vector<char>> &board){

    whiteDangerMap = 0;

    for(int i = 0; i < chessPieces.size(); i++){
        if(isupper(chessPieces[i].type)){
            //std::cout << "before for loop\n";
            if(chessPieces[i].type == 'P'){
                //std::cout << "pawnMoves\n"; 
                chessPieces[i].getPawnDanger(board, i);
                //std::cout << "avalidMoves\n";
            }else {/*"bvalidMoves\n";*/ chessPieces[i].getValidMoves(board);/*std::cout << "avalidMoves\n";*/}
            for(int j = 0; j < chessPieces[i].validMoves.size(); j++){

                //std::cout << "before for coords\n";
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
    std::cout << board[2][6] << "\n";
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
            //std::cout << "before for loop\n";
            if(chessPieces[i].type == 'p'){
                //std::cout << "pawnMoves\n"; 
                chessPieces[i].getPawnDanger(board, i);
                //std::cout << "avalidMoves\n"; 
            }
            else {/*std::cout << "bvalidMoves\n";*/ chessPieces[i].getValidMoves(board);/*std::cout << "avalidMoves\n";*/ }
            for(int j = 0; j < chessPieces[i].validMoves.size(); j++){
                
                //std::cout << "before for coords\n";
                int coord1 = int(chessPieces[i].validMoves[j][2]) - 48;
                int coord2 = int(chessPieces[i].validMoves[j][3]) - 48;
                //std::cout << "after for loop\n";
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