#include <iostream>
#include <stdlib.h>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <cstdlib>
#include <stdint.h>
#include <vector>
#include <math.h>
#include "res/initializeBoard.hpp"
#include "res/chessPiece.hpp"
#include "res/drawChessBoard.hpp"
#include "res/movePiece.hpp"
#include "res/checkInCheck.hpp"
#include "res/getIdatCoord.hpp"
#include "res/checkIfMate.hpp"
#include "res/bots/botMovement.hpp"

// en passant bug

int main(int argc, char ** argv){
    float width = sf::VideoMode::getDesktopMode().width;
    float height = sf::VideoMode::getDesktopMode().height;
    int clickedId = -1;
    bool holding = false;
    int roundCount = 1;
    int roundCheck = 0;
    int botColor = 1;
    int botType = 0;

    if(argc > 1 && isdigit(*argv[1])) botType = int(*argv[1]) - 48;
    std::cout << botType << "\n";

    srand((unsigned) time(NULL));

    sf::RenderWindow window(sf::VideoMode(width, height, 32), "Chess Game", sf::Style::Default);
    window.setFramerateLimit(60);

    font.loadFromFile("fonts/scoreFont.ttf");

    drawChessBoard(width, height);

    /*std::vector<std::vector<char>> testBoard(8, std::vector<char> (8));
    testBoard  = {
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', 'q', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'}
    };*/

    std::vector<std::vector<char>> board(8, std::vector<char> (8));
    std::string boardString = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR/8";
    //boardString = "rnb1kbnr/pp1ppppp/2p5/3P4/2P1P3/8/PP2KPPP/RNBQqBNR";
    initializeBoard(board, boardString);

    sf::Font font;
    font.loadFromFile("fonts/scoreFont.ttf");
    sf::Text roundDisplay;
    roundDisplay.setCharacterSize(40);
    roundDisplay.setFillColor(sf::Color::White);
    roundDisplay.setFont(font);
    std::string turnString;
    if(roundCheck == 0) turnString = "White Turn";
    else turnString = "Black Turn";
    roundDisplay.setString(turnString);
    roundDisplay.setOrigin(roundDisplay.getLocalBounds().width/2,roundDisplay.getLocalBounds().height/2);
    roundDisplay.setPosition(width/2, 50);

    sf::CircleShape mouseCircle;
    mouseCircle.setFillColor(sf::Color::Cyan);
    mouseCircle.setRadius(0.1f);

    std::vector<std::string> allValidMoves;
    for(int i = 0; i < chessPieces.size(); i++){
        if(abs(roundCheck - !!isupper(chessPieces[i].type))){
            chessPieces[i].getValidMoves(board);
            for(int j = 0; j < chessPieces[i].validMoves.size(); j++){
                allValidMoves.push_back(chessPieces[i].validMoves[j]);
            }
        }
    }
    for(int i = 0; i < allValidMoves.size(); i++){
                        sf::Vector2i prevCoords = {int(allValidMoves[i][0]) - 48, int(allValidMoves[i][1]) - 48};
                        sf::Vector2i newCoords = {int(allValidMoves[i][2]) - 48, int(allValidMoves[i][3]) - 48};
                        if(checkNotCheck(board, getIdatCoord(prevCoords), prevCoords, newCoords)){
                            allValidMoves.erase(allValidMoves.begin()+i);
                            i--;
                        }
                    }

    checkInCheck(board, 2);

    while(window.isOpen()){

        const sf::Vector2i mousePosition{ sf::Mouse::getPosition(window) };
        const sf::Vector2f mouseCoords{ window.mapPixelToCoords(mousePosition) };
        mouseCircle.setPosition(mouseCoords);

        if(roundCheck == 2){
            roundCount++;
            roundCheck = 0;
        }


        //random bot movement
        if(roundCheck == botColor && botType != 0){

            std::string move = moveBot(board, allValidMoves, botColor, botType);
            sf::Vector2i newCoords = {int(move[2]) - 48, int(move[3]) - 48};
            int oldId = getIdatCoord({int(move[0]) - 48, int(move[1]) - 48});
            int boardId = newCoords.y*8 + newCoords.x;

            movePiece(board, allValidMoves, oldId, boardId, oldId, roundCheck);

                    if(roundCheck == 2) roundCheck = 0;
                    checkInCheck(board,0);
                    allValidMoves.clear();
                    for(int i = 0; i < chessPieces.size(); i++){
                        if(abs(roundCheck - !!isupper(chessPieces[i].type))){
                            chessPieces[i].getValidMoves(board);
                            for(int j = 0; j < chessPieces[i].validMoves.size(); j++){
                                allValidMoves.push_back(chessPieces[i].validMoves[j]);
                            }
                        }
                    }
                    for(int i = 0; i < allValidMoves.size(); i++){
                        sf::Vector2i prevCoords = {int(allValidMoves[i][0]) - 48, int(allValidMoves[i][1]) - 48};
                        sf::Vector2i newCoords = {int(allValidMoves[i][2]) - 48, int(allValidMoves[i][3]) - 48};
                        if(checkNotCheck(board, getIdatCoord(prevCoords), prevCoords, newCoords)){
                            allValidMoves.erase(allValidMoves.begin()+i);
                            i--;
                        }
                    }
                    checkInCheck(board, 2);
                    if(allValidMoves.size() == 0){std::cout << "player " << !roundCheck + 1 << "!wins "; window.close();}

        }

        sf::Event event;
        while(window.pollEvent(event)){

            if(event.type == sf::Event::Closed) window.close();

            else if (event.type == sf::Event::Resized){
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }

            else if (event.type == sf::Event::MouseButtonPressed && clickedId == -1){
                for(int i = 0; i < chessPieces.size(); i++){
                    if(mouseCircle.getGlobalBounds().intersects(chessPieces[i].sprite.getGlobalBounds()) &&
                    abs(roundCheck - !!isupper(chessPieces[i].type))){
                        clickedId = i;
                        chessPieces[i].clicked = true;
                    }
                }
                
            }

            else if (event.type == sf::Event::MouseButtonReleased && clickedId != -1){

                int prevId = chessPieces[clickedId].coords.y*8 + chessPieces[clickedId].coords.x;
                int boardId = prevId;

                for(int i = 0; i < chessBoard.size(); i++){
                    if(mouseCircle.getGlobalBounds().intersects(chessBoard[i].getGlobalBounds())){
                        boardId = i;
                    }
                }

                int prevRoundCheck = roundCheck;

                movePiece(board, allValidMoves, clickedId, boardId, prevId, roundCheck);
                
                if(prevRoundCheck != roundCheck){
                    
                    if(roundCheck == 2) roundCheck = 0;
                    if(prevRoundCheck == 0) checkInCheck(board,1);
                    else checkInCheck(board,0);
                    allValidMoves.clear();
                    for(int i = 0; i < chessPieces.size(); i++){
                        if(abs(roundCheck - !!isupper(chessPieces[i].type))){
                            chessPieces[i].getValidMoves(board);
                            for(int j = 0; j < chessPieces[i].validMoves.size(); j++){
                                allValidMoves.push_back(chessPieces[i].validMoves[j]);
                            }
                        }
                    }
                    for(int i = 0; i < allValidMoves.size(); i++){
                        sf::Vector2i prevCoords = {int(allValidMoves[i][0]) - 48, int(allValidMoves[i][1]) - 48};
                        sf::Vector2i newCoords = {int(allValidMoves[i][2]) - 48, int(allValidMoves[i][3]) - 48};
                        if(checkNotCheck(board, getIdatCoord(prevCoords), prevCoords, newCoords)){
                            allValidMoves.erase(allValidMoves.begin()+i);
                            i--;
                        }
                    }
                    checkInCheck(board, 2);
                    if(allValidMoves.size() == 0){std::cout << "player " << !roundCheck + 1 << "!wins "; window.close();}

                }
                

                clickedId = -1;
            }

        }



        //Going through every chess piece
        for(int i = 0; i < chessPieces.size(); i++){

            if(abs(roundCheck - !!isupper(chessPieces[i].type))){
                //Getting mouse position
                if(mouseCircle.getGlobalBounds().intersects(chessPieces[i].sprite.getGlobalBounds())){
                    chessPieces[i].hovered = true;
                } else {
                    chessPieces[i].hovered = false;
                }
            }


            //Setting chess piece outline
            
            if(chessPieces[i].hovered &&
            abs(roundCheck - !!isupper(chessPieces[i].type))) chessPieces[i].sprite.setOutlineColor(sf::Color::Cyan);
            else if(chessPieces[i].type == 'K' && whiteInCheck) chessPieces[i].sprite.setOutlineColor(sf::Color::Red);
            else if(chessPieces[i].type == 'k' && blackInCheck) chessPieces[i].sprite.setOutlineColor(sf::Color::Red);
            else {
                if(chessPieces[i].sprite.getFillColor() == sf::Color::White) chessPieces[i].sprite.setOutlineColor(sf::Color::Black);
                else chessPieces[i].sprite.setOutlineColor(sf::Color::White);
            }

        }



        //Going through every board piece
        for(int i = 0; i < moveBoard.size(); i++){

            moveBoard[i].setFillColor(sf::Color::Transparent);
            if(clickedId != -1){

                for(int j = 0; j < chessPieces[clickedId].validMoves.size(); j++){
                    int id = -1;
                    for(int k = 0; k < allValidMoves.size(); k++){
                        if(allValidMoves[k] == chessPieces[clickedId].validMoves[j]) {id = k; break;}
                    }
                    if(id != -1){
                        sf::Vector2i boardCoords = {int(allValidMoves[id][2] - 48), int(allValidMoves[id][3] - 48)};
                        moveBoard[boardCoords.y*8 + boardCoords.x].setFillColor(sf::Color(0,0,0,50));
                    }

                }

            }

        }

        //Updating position of clicked piece
        if(clickedId != -1) chessPieces[clickedId].sprite.setPosition(mouseCoords);


        //Updating round text
        if(roundCheck == 0) turnString = "White Turn";
        else turnString = "Black Turn";
        roundDisplay.setString(turnString);
        roundDisplay.setOrigin(roundDisplay.getLocalBounds().width/2,roundDisplay.getLocalBounds().height/2);
        roundDisplay.setPosition(width/2 - 40, 40);


        //Drawing to screen
        window.clear(sf::Color::Black);
        window.draw(roundDisplay);
        for(int i = 0; i < chessBoard.size(); i++) window.draw(chessBoard[i]);
        for(int i = 0; i < moveBoard.size(); i++) window.draw(moveBoard[i]);
        for(int i = 0; i < chessPieces.size(); i++) window.draw(chessPieces[i].sprite);
        window.display();
    }

}