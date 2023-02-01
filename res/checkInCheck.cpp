#include "checkInCheck.hpp"

void checkInCheck(std::vector<std::vector<char>> &board, int which){

        //check if black in check
        if(which == 0 || which == 2){
            //std::cout << "before board\n";
            generateWhiteDangerMap(board);
            //std::cout << "after board\n";
            sf::Vector2i kingCoords;
            for(int i = 0; i <8; i++){
                for (int j = 0; j < 8; j++){
                    if(board[i][j] == 'k'){kingCoords = {j,i}; break;}
                }
            }
            //std::cout << "after coords\n";
            int num = kingCoords.y*8 + kingCoords.x;
            int64_t bit = 1;
            bit = bit << num;
            //std::cout << "after bit\n";

            if(whiteDangerMap & bit) blackInCheck = true;
            else blackInCheck = false;
        }

        //check if white in check
        if(which == 1 || which == 2){
            //std::cout << "before board\n";
            generateBlackDangerMap(board);
            //std::cout << "after board\n";
            sf::Vector2i kingCoords;
            for(int i = 0; i <8; i++){
                for (int j = 0; j < 8; j++){
                    if(board[i][j] == 'K'){kingCoords = {j,i}; break;}
                }
            }
            //std::cout << "after coord\n";
            
            int num = kingCoords.y*8 + kingCoords.x;
            int64_t bit = 1;
            bit = bit << num;
            //std::cout << "after bit\n";

            if(blackDangerMap & bit) whiteInCheck = true;
            else whiteInCheck = false;
        }

}