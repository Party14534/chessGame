#include "minMovesBot.hpp"

std::string minBotMove(std::vector<std::vector<char>> board, std::vector<std::string> validMoves, int color){

    int min = 10000;
    std::vector<std::string> moves;
    std::vector<chessPiece> tempChessPieces = chessPieces;

    if(validMoves.size() == 0) return NULL;

    for(int i = 0; i < validMoves.size(); i++){

        std::vector<std::vector<char>> tempBoard = board;
        std::vector<std::string> tempValidMoves;

        sf::Vector2i prevCoords = {int(validMoves[i][0]) - 48, int(validMoves[i][1]) - 48};
        sf::Vector2i newCoords = {int(validMoves[i][2]) - 48, int(validMoves[i][3]) - 48};

        int pieceId = getIdatCoord(prevCoords);
        char type = chessPieces[pieceId].type;

        //std::cout << chessPieces[pieceId].type << ": " << newCoords.x << ", " << newCoords.y << "\n";

        tempBoard[prevCoords.y][prevCoords.x] = '\0';

        if(tempBoard[newCoords.y][newCoords.x] != '\0'){
            int killId = getIdatCoord(newCoords);
            chessPieces.erase(chessPieces.begin() + killId);
            for(int i = killId; i < chessPieces.size(); i++) chessPieces[i].id--;
            if(killId < pieceId) pieceId--;
        }

        tempBoard[newCoords.y][newCoords.x] = type;
        chessPieces[pieceId].coords = newCoords;

        /*for(int k = 0; k < 8; k++){
            for (int l = 0; l < 8; l++){

                if(tempBoard[k][l] == '\0') std::cout << "  ";
                else std::cout << tempBoard[k][l] << " "; 

            } 
            std::cout << "\n";
        }*/

        for(int j = 0; j < chessPieces.size(); j++){

            if(color == 0){

                if(!(isupper(chessPieces[j].type))){

                    chessPieces[j].getValidMoves(tempBoard);
                    for(int k = 0; k < chessPieces[j].validMoves.size(); k++){
                        tempValidMoves.push_back(chessPieces[j].validMoves[k]);
                    }

                }

            } else if(color == 1){

                if((isupper(chessPieces[j].type))){
                    
                    chessPieces[j].getValidMoves(tempBoard);
                    //std::cout << chessPieces[j].type << " bruh\n";
                    for(int k = 0; k < chessPieces[j].validMoves.size(); k++){
                        tempValidMoves.push_back(chessPieces[j].validMoves[k]);
                    }

                }

            }

        }

        for(int j = 0; j < tempValidMoves.size(); j++){
            sf::Vector2i previousCoords = {int(tempValidMoves[j][0]) - 48, int(tempValidMoves[j][1]) - 48};
            sf::Vector2i newestCoords = {int(tempValidMoves[j][2]) - 48, int(tempValidMoves[j][3]) - 48};
            //std::cout << chessPieces[getIdatCoord(previousCoords)].type << " hello\n";
            int newId = getIdatCoord(previousCoords);

            if(checkNotCheck(tempBoard, newId, previousCoords, newestCoords)){
                if(j < 0) j = 0;
                tempValidMoves.erase(tempValidMoves.begin()+j);
                j--;
            }
        }

        //std::cout << tempValidMoves.size() << "," << i << "\n";

        if(tempValidMoves.size() < min){
            min = tempValidMoves.size();
            moves.clear();
            moves.push_back(validMoves[i]);
        } else if(tempValidMoves.size() == min){
            moves.push_back(validMoves[i]);
        }

        chessPieces = tempChessPieces;

    }

    //std::cout << moves.size() << "left\n";

    /*for(int i = 0; i < moves.size(); i ++){
        std::cout << moves[i] << "\n";
    }*/

    chessPieces = tempChessPieces;
    tempChessPieces.clear();

    return moves[int(rand() % moves.size())];

}