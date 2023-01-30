#include "checkInCheck.hpp"

void checkInCheck(std::vector<std::vector<char>> &board, int which){

        //check if black in check
        if(which == 0 || which == 2){
            generateWhiteDangerMap(board);
            sf::Vector2i kingCoords;
            for(int i = 0; i <8; i++){
                for (int j = 0; j < 8; j++){
                    if(board[i][j] == 'k'){kingCoords = {j,i}; break;}
                }
            }
            int num = kingCoords.y*8 + kingCoords.x;
            int64_t bit = 1;
            bit = bit << num;

            if(whiteDangerMap & bit) blackInCheck = true;
            else blackInCheck = false;
        }

        //check if white in check
        if(which == 1 || which == 2){
            generateBlackDangerMap(board);
            sf::Vector2i kingCoords;
            for(int i = 0; i <8; i++){
                for (int j = 0; j < 8; j++){
                    if(board[i][j] == 'K'){kingCoords = {j,i}; break;}
                }
            }
            
            int num = kingCoords.y*8 + kingCoords.x;
            int64_t bit = 1;
            bit = bit << num;

            if(blackDangerMap & bit) whiteInCheck = true;
            else whiteInCheck = false;
        }

}