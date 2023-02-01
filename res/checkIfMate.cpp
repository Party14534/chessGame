#include "checkIfMate.hpp"

bool checkMate(std::vector<std::vector<char>> board, int color){

        std::vector<chessPiece> tempChessPieces = chessPieces;
        chessPieces.clear();
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                    chessPiece newPiece(board[i][j], {j,i}, false);
            }
        }
        //std::cout << "got here\n";


        std::vector<std::string> validMoves;
        if(!color){

            for(int i = 0; i < chessPieces.size(); i++){

                if(!(isupper(chessPieces[i].type))){

                    chessPieces[i].getValidMoves(board);
                    for(int j = 0; j < chessPieces[i].validMoves.size(); j++){
                        validMoves.push_back(chessPieces[i].validMoves[j]);
                    }

                }

            }

        }else{

            for(int i = 0; i < chessPieces.size(); i++){

                if((isupper(chessPieces[i].type))){

                    chessPieces[i].getValidMoves(board);
                    for(int j = 0; j < chessPieces[i].validMoves.size(); j++){
                        validMoves.push_back(chessPieces[i].validMoves[j]);
                    }

                }

            }

        }
        //std::cout << "got here baby\n";
        for(int i = 0; i < validMoves.size(); i++){
            //std::cout << "before coords\n";
            sf::Vector2i prevCoords = {int(validMoves[i][0]) - 48, int(validMoves[i][1]) - 48};
            //std::cout << "after coords1\n";
            sf::Vector2i newCoords = {int(validMoves[i][2]) - 48, int(validMoves[i][3]) - 48};
            //std::cout << "after coords2\n";
            if(checkNotCheck(board, getIdatCoord(prevCoords), prevCoords, newCoords)){
                //std::cout << "before erase " << "\n";
                validMoves.erase(validMoves.begin()+i);
                i--;
                if(i < 0) i = 0;
                //std::cout << validMoves.size() << ", " << i << "\n";
            }
        }
        //std::cout << "poopies\n";
        chessPieces = tempChessPieces;
        tempChessPieces.clear();
        if(validMoves.size() == 0) {validMoves.clear();return true;}
        validMoves.clear();
        return false;

}