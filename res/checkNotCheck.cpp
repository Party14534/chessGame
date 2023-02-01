#include "checkNotCheck.hpp"

bool checkNotCheck(std::vector<std::vector<char>> board, int id, sf::Vector2i prevCoords, sf::Vector2i newCoords){

    char type = chessPieces[id].type;
    //std::cout << "checknotcheck\n";
    std::vector<chessPiece> tempChessPieces = chessPieces;

    //std::cout << "board\n";
    board[prevCoords.y][prevCoords.x] = '\0';
    
    if(board[newCoords.y][newCoords.x] != '\0'){
        //std::cout << "yes kill\n";
        int killId = getIdatCoord(newCoords);
        //std::cout << killId << "," << chessPieces.size() << "before erase\n";
        chessPieces.erase(chessPieces.begin()+killId);
        //std::cout << "after erase\n";
        for(int i = killId; i < chessPieces.size(); i++) chessPieces[i].id--;
        //std::cout << "after for kill\n";
        board[newCoords.y][newCoords.x] = type;
        if(killId < id) id--;
        chessPieces[id].coords = newCoords;
        /*std::cout << type << " killed " << newCoords.x << newCoords.y << "\n";
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j ++){
                if(board[i][j] == '\0') std::cout << "  ";
                else std::cout << board[i][j] << " ";
            }
            std::cout << "\n";
        }*/
    }
    else {/*std::cout << "no kill\n";*/board[newCoords.y][newCoords.x] = type; chessPieces[id].coords = newCoords;}

    //std::cout << "after kill\n";

    bool prevCheck;

    if(isupper(type)){
        prevCheck = whiteInCheck;
        //std::cout << "before check\n";
        checkInCheck(board, 1);
        bool newCheck = whiteInCheck;
        //std::cout << "in if\n";
        whiteInCheck = prevCheck;
        chessPieces = tempChessPieces;
        //std::cout << "after clear\n";
        return newCheck;
    } else {
        prevCheck = blackInCheck;
        //std::cout << "before check\n";
        checkInCheck(board, 0);
        bool newCheck = blackInCheck;
        //std::cout << "in if\n";
        blackInCheck = prevCheck;
        chessPieces = tempChessPieces;
        //std::cout << "after clear\n";
        //std::cout << newCheck << "\n";
        return newCheck;
    }

}