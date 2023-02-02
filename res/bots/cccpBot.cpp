#include "cccpBot.hpp"

std::string cccpBotMove(std::vector<std::vector<char>> board, std::vector<std::string> validMoves, int color){

    int num = 50;
    std::vector<std::string> checkmateMoves(num, "    ");
    int mateNum = 0;
    std::vector<std::string> checkMoves(num, "    ");
    int checkNum = 0;
    std::vector<std::string> captureMoves(num, "    ");
    int capNum = 0;

    
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

        if(tempBoard[newCoords.y][newCoords.x] != '\0') {captureMoves[capNum] = validMoves[i]; capNum++;}
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
                checkMoves[checkNum] = validMoves[i];
                checkNum++;
            //std::cout << "oush\n";
            }
        } else {
            if(whiteInCheck){
                checkMoves[checkNum] = validMoves[i];
                checkNum++;
        //std::cout << "push\n";
            }
        }
        //std::cout << "mama\n";
        if(checkMate(board,color)) {checkmateMoves[mateNum] == validMoves[i]; mateNum++;}
        //std::cout << "checkMateCheck\n";
        chessPieces = tempChessPieces;
        tempChessPieces.clear();
        tempBoard.clear();
        //std::cout << "heree222e\n";
    }

    if(mateNum != 0) {
        //std::cout << "M\n";
        std::string ans = checkmateMoves[rand()%mateNum];
        //std::cout << "mewoe\n";
        checkmateMoves.clear();
        checkMoves.clear();
        captureMoves.clear();
        //std::cout << "end\n";
        return ans;
    }
    else if(checkNum != 0) {
        //std::cout << "C\n"; 
        std::string ans = checkMoves[rand()%checkNum];
        //std::cout << "Cewo\n";
        checkmateMoves.clear();
        checkMoves.clear();
        captureMoves.clear();
        //std::cout << "end\n";
        return ans;
    }
    else if(capNum != 0) {
        //std::cout << "CA\n";
        std::string ans = captureMoves[rand()%capNum];
        //std::cout << "Cawoe\n";
        checkmateMoves.clear();
        checkMoves.clear();
        captureMoves.clear();
        //std::cout << "end\n";
        return ans;
    }
    checkmateMoves.clear();
    checkMoves.clear();
    captureMoves.clear();
    //std::cout << "R\n"; 
    return validMoves[rand()%validMoves.size()];

}