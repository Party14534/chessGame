#include "movePiece.hpp"

void movePiece(std::vector<std::vector<char>> &board, std::vector<std::string>& allValidMoves, int clickedId, int boardId, int prevId, int &roundCheck){

                bool valid = false;

                sf::Vector2i newCoords = {(boardId % 8), (int)floor((boardId)/8)};

                std::string checkString = "    ";
                checkString[0] = char(chessPieces[clickedId].coords.x) + '0';
                checkString[1] = char(chessPieces[clickedId].coords.y) + '0';
                checkString[2] = char(newCoords.x) + '0';
                checkString[3] = char(newCoords.y) + '0';

                for(int i = 0; i < allValidMoves.size(); i++){
                    if (allValidMoves[i] == checkString){
                        valid = true;
                        chessPieces[clickedId].hasMoved = true;
                    }
                }

                if(valid){

                    board[chessPieces[clickedId].coords.y][chessPieces[clickedId].coords.x] = '\0';
                    if(newCoords.y == 0 && chessPieces[clickedId].type == 'P') board[newCoords.y][newCoords.x] = 'Q';
                    else if(newCoords.y == 7 && chessPieces[clickedId].type == 'p') board[newCoords.y][newCoords.x] = 'q';
                    else board[newCoords.y][newCoords.x] = chessPieces[clickedId].type;

                    if(chessPieces[clickedId].type == 'K' && (newCoords.x - chessPieces[clickedId].coords.x == 2)){
                        board[7][7] = '\0';
                        chessPieces[getIdatCoord({7,7})].hasMoved = true;
                        board[7][5] = 'R';
                    } else if(chessPieces[clickedId].type == 'K' && (newCoords.x - chessPieces[clickedId].coords.x == -2)){
                        board[7][0] = '\0';
                        chessPieces[getIdatCoord({7,0})].hasMoved = true;
                        board[7][3] = 'R';
                    }
                    else if(chessPieces[clickedId].type == 'k' && (newCoords.x - chessPieces[clickedId].coords.x == 2)){
                        board[0][7] = '\0';
                        chessPieces[getIdatCoord({0,7})].hasMoved = true;
                        board[0][5] = 'r';
                    } else if(chessPieces[clickedId].type == 'k' && (newCoords.x - chessPieces[clickedId].coords.x == -2)){
                        board[0][0] = '\0';
                        chessPieces[getIdatCoord({0,0})].hasMoved = true;
                        board[0][3] = 'r';
                    } else if(chessPieces[clickedId].type == 'p' && (newCoords.x - chessPieces[clickedId].coords.x == -2)){
                        board[0][0] = '\0';
                        chessPieces[getIdatCoord({0,0})].hasMoved = true;
                        board[0][3] = 'r';
                    } else if(chessPieces[clickedId].type == 'P' && (newCoords.x - chessPieces[clickedId].coords.x != 0)
                    && (newCoords.y - chessPieces[clickedId].coords.y != 0) && (justPassant.x != -1)){
                        board[newCoords.y + 1][newCoords.x] = '\0';
                    } else if(chessPieces[clickedId].type == 'p' && (newCoords.x - chessPieces[clickedId].coords.x != 0)
                    && (newCoords.y - chessPieces[clickedId].coords.y != 0) && (justPassant.x != -1)){
                        board[newCoords.y - 1][newCoords.x] = '\0';
                    }
                    int prevCoordY = chessPieces[clickedId].coords.y;
                    chessPieces[clickedId].coords = newCoords;
                    redrawBoard(board);
                    if(chessPieces[clickedId].type == 'p' && ((newCoords.y - prevCoordY) == 2)){
                        justPassant = newCoords;
                    } else if(chessPieces[clickedId].type == 'P' && (newCoords.y - prevCoordY == -2)){
                        justPassant = newCoords;
                    } else { justPassant = {-1,-1};}

                    roundCheck++;
                    

                } else chessPieces[clickedId].sprite.setPosition(chessBoard[prevId].getPosition());

                chessPieces[clickedId].clicked = false;
                clickedId = -1;

}