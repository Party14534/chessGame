#include "chessPiece.hpp"

chessPiece::chessPiece(char initType, sf::Vector2i initCoords, bool newHasMoved){
    if(initType != '\0'){
        hasMoved = newHasMoved;
        type = initType;
        coords = initCoords;
        int coord = initCoords.y*8 + initCoords.x;

        //sprite initialization
        sprite.setFont(font);
        sprite.setCharacterSize(25);
        if(isupper(type)) {sprite.setFillColor(sf::Color::White); sprite.setOutlineColor(sf::Color::Black);}
        else {sprite.setFillColor(sf::Color::Black); sprite.setOutlineColor(sf::Color::White);}
        sprite.setOutlineThickness(2);
        sprite.setString(type);
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