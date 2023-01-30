#include "cccpBot.hpp"

std::string cccpBotMove(std::vector<std::vector<char>> board, std::vector<std::string> validMoves, int color){

    std::vector<std::string> checkmateMoves;
    std::vector<std::string> checkMoves;
    std::vector<std::string> captureMoves;

    
    for(int i = 0; i < validMoves.size(); i++){
        
        std::vector<chessPiece> tempChessPieces = chessPieces;
        std::vector<std::vector<char>> tempBoard = board;
        sf::Vector2i prevCoords = {int(validMoves[i][0]) - 48, int(validMoves[i][1]) - 48};
        sf::Vector2i newCoords = {int(validMoves[i][2]) - 48, int(validMoves[i][3]) - 48};
        char type = tempBoard[prevCoords.y][prevCoords.x];

        if(tempBoard[newCoords.y][newCoords.x] != '\0') captureMoves.push_back(validMoves[i]);
        int id = getIdatCoord(prevCoords);
        chessPieces[id].coords = newCoords;

        tempBoard[prevCoords.y][prevCoords.x] = '\0';
        tempBoard[newCoords.y][newCoords.x] = type;
        checkInCheck(tempBoard, color);
        if(!color){
            if(blackInCheck){
                checkMoves.push_back(validMoves[i]);
            }
        } else {
            if(whiteInCheck){
                checkMoves.push_back(validMoves[i]);
            }
        }

        if(checkMate(board,color)) checkmateMoves.push_back(validMoves[i]);
        chessPieces = tempChessPieces;
    }

    if(checkmateMoves.size() != 0) {std::cout << "M\n"; return checkmateMoves[(int)(rand()%checkmateMoves.size())];}
    if(checkMoves.size() != 0) {std::cout << "C\n"; return checkMoves[(int)(rand()%checkMoves.size())];}
    if(captureMoves.size() != 0) {std::cout << "CA\n"; return captureMoves[(int)(rand()%captureMoves.size())];}
    std::cout << "R\n"; 
    return validMoves[(int)(rand()%validMoves.size())];

}