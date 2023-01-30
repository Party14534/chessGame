#include "drawChessBoard.hpp"

void drawChessBoard(float width, float height){
    
    bool colorSwitch = true;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){

            int offsetX;
            int offsetY;

            if(j <= 4) offsetX = -abs(4-j);
            else offsetX = j-4;

            if(i <= 4) offsetY = -abs(4-i);
            else offsetY = i-4;

            sf::RectangleShape newBlock;
            newBlock.setSize({80,80});
            newBlock.setOrigin(40,40);
            newBlock.setOutlineColor(sf::Color::Transparent);
            newBlock.setOutlineThickness(2);

            if(colorSwitch) newBlock.setFillColor(sf::Color(250, 240, 220));
            else newBlock.setFillColor(sf::Color(118, 74, 52));

            colorSwitch = !colorSwitch;
            newBlock.setPosition(width/2 + offsetX*80, height/2 + offsetY*80);
            chessBoard.push_back(newBlock);

            sf::CircleShape newMove;
            newMove.setRadius(25);
            newMove.setOrigin(25,25);
            newMove.setFillColor(sf::Color::Transparent);
            newMove.setPosition(newBlock.getPosition());
            moveBoard.push_back(newMove);

        }
        colorSwitch = !colorSwitch;
    }
}