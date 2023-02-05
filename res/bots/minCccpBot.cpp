#include "minCccpBot.hpp"

std::string minCccpBotMove(std::vector<std::vector<char>> board, std::vector<std::string> validMoves, int color){

    int num = 50;
    //std::cout << "ham\n";
    std::vector<std::string> checkmateMoves;
    int mateNum = 0;
    std::vector<std::string> checkMoves;
    //std::cout << "ham\n";
    int checkNum = 0;
    std::vector<std::string> captureMoves;
    int capNum = 0;
    //std::cout << "ham\n";

    
    for(int i = 0; i < validMoves.size(); i++){
    //std::cout << "loop\n";
        
        std::vector<chessPiece> tempChessPieces = chessPieces;
        std::vector<std::vector<char>> tempBoard = board;

        //std::cout << "valid movess\n";
        sf::Vector2i prevCoords = {int(validMoves[i][0]) - 48, int(validMoves[i][1]) - 48};
        sf::Vector2i newCoords = {int(validMoves[i][2]) - 48, int(validMoves[i][3]) - 48};
        //std::cout << "board\n";
        char type = tempBoard[prevCoords.y][prevCoords.x];
        //std::cout << "hereee0\n";

        if(tempBoard[newCoords.y][newCoords.x] != '\0') {captureMoves.push_back(validMoves[i]); capNum++;}
        int id = getIdatCoord(prevCoords);
        if(id == -1) continue;
        chessPieces[id].coords = newCoords;
        //std::cout << "heree1e\n";

        tempBoard[prevCoords.y][prevCoords.x] = '\0';
        tempBoard[newCoords.y][newCoords.x] = type;
        checkInCheck(tempBoard, color);
        //std::cout << "hereee\n";
        if(!color){
            if(blackInCheck){
                checkMoves.push_back(validMoves[i]);
                checkNum++;
            //std::cout << "oush\n";
            }
        } else {
            if(whiteInCheck){
                checkMoves.push_back(validMoves[i]);
                checkNum++;
                
            }
        }
        if(checkMate(board,color)) {checkmateMoves.push_back(validMoves[i]); mateNum++;}
        //std::cout << "mama\n";
        chessPieces = tempChessPieces;
        tempChessPieces.clear();
        tempBoard.clear();
    }

    if(mateNum != 0) {
        std::string ans = minBotMove(board, checkmateMoves, color);
        checkmateMoves.clear();
        checkMoves.clear();
        captureMoves.clear();
        return ans;
    }
    else if(checkNum != 0) {
        std::string ans = minBotMove(board, checkMoves, color);
        checkMoves.clear();
        captureMoves.clear();
        return ans;
    }
    else if(capNum != 0) {
        //std::cout << "here\n";
        std::string ans = minBotMove(board, captureMoves, color);
        //std::cout << "lost here\n";
        captureMoves.clear();
        return ans;
    }
    checkmateMoves.clear();
    checkMoves.clear();
    captureMoves.clear();
    return minBotMove(board, validMoves, color);

}