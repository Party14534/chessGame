#include "chessPiece.hpp"

chessPiece::chessPiece(char initType, sf::Vector2i initCoords, bool newHasMoved){
    if(initType != '\0'){
        hasMoved = newHasMoved;
        //std::cout << initType << ": " << hasMoved << "\n";
        type = initType;
        coords = initCoords;
        int coord = initCoords.y*8 + initCoords.x;

        //sprite initialization
        
        if(type == 'K') sprite.setTexture(whiteKingTexture);
        if(type == 'Q') sprite.setTexture(whiteQueenTexture);
        if(type == 'R') sprite.setTexture(whiteRookTexture);
        if(type == 'B') sprite.setTexture(whiteBishopTexture);
        if(type == 'N') sprite.setTexture(whiteKnightTexture);
        if(type == 'P') sprite.setTexture(whitePawnTexture);
        if(type == 'k') sprite.setTexture(blackKingTexture);
        if(type == 'q') sprite.setTexture(blackQueenTexture);
        if(type == 'r') sprite.setTexture(blackRookTexture);
        if(type == 'b') sprite.setTexture(blackBishopTexture);
        if(type == 'n') sprite.setTexture(blackKnightTexture);
        if(type == 'p') sprite.setTexture(blackPawnTexture);

        sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
        sprite.setPosition(chessBoard[coord].getPosition());

        id = chessPieces.size();
        chessPieces.push_back(*this);
    }
}

void chessPiece::getValidMoves(std::vector<std::vector<char>> boardState){

    validMoves.clear();
    if(type == 'P') whitePawnMove(boardState, id);
    if(type == 'p') blackPawnMove(boardState, id);
    if(type == 'N') whiteKnightMove(boardState, id);
    if(type == 'n') blackKnightMove(boardState, id);
    if(type == 'Q') whiteQueenMove(boardState, id);
    if(type == 'q') blackQueenMove(boardState, id);
    if(type == 'B') whiteBishopMove(boardState, id);
    if(type == 'b') blackBishopMove(boardState, id);
    if(type == 'R') whiteRookMove(boardState, id);
    if(type == 'r') blackRookMove(boardState, id);
    if(type == 'K') whiteKingMove(boardState, id);
    if(type == 'k') blackKingMove(boardState, id);

}


void chessPiece::getPawnDanger(std::vector<std::vector<char>> boardState, int id){

    sf::Vector2i coords = chessPieces[id].coords;
    if(chessPieces[id].type == 'P' && coords.y != 0){
        if(coords.x != 7){

                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x+1) + '0';
                stringCoords[3] = char(coords.y-1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);

        }
        if(coords.x != 0){

                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x-1) + '0';
                stringCoords[3] = char(coords.y-1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);

        }

    } else if (chessPieces[id].type == 'p' && coords.y != 7){

        if(coords.x != 7){

                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x+1) + '0';
                stringCoords[3] = char(coords.y+1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);

        }
        if(coords.x != 0){

                std::string stringCoords = "    ";
                stringCoords[0] = char(coords.x) + '0';
                stringCoords[1] = char(coords.y) + '0';
                stringCoords[2] = char(coords.x-1) + '0';
                stringCoords[3] = char(coords.y+1) + '0';
                chessPieces[id].validMoves.push_back(stringCoords);

        }

    }
}