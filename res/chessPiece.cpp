#include "chessPiece.hpp"

chessPiece::chessPiece(char initType, sf::Vector2i initCoords, bool newHasMoved){
    if(initType != '\0'){
        hasMoved = newHasMoved;
        type = initType;
        coords = initCoords;
        int coord = initCoords.y*8 + initCoords.x;

        //sprite initialization
        
        if(tolower(type) == 'k') sprite.setTexture(kingTexture);
        if(tolower(type) == 'q') sprite.setTexture(queenTexture);
        if(tolower(type) == 'r') sprite.setTexture(rookTexture);
        if(tolower(type) == 'b') sprite.setTexture(bishopTexture);
        if(tolower(type) == 'n') sprite.setTexture(knightTexture);
        if(tolower(type) == 'p') sprite.setTexture(pawnTexture);

        if(isupper(type)) {sprite.setColor(sf::Color::White);}
        else {sprite.setColor(sf::Color::Black);}
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