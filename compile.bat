g++ -g -c main.cpp -I"C:\SFML-2.5.1\include" res/bots/randomBot.cpp res/bots/cccpBot.cpp res/bots/botMovement.cpp res/mov/kingMovement.cpp res/mov/rookMovement.cpp res/mov/bishopMovement.cpp res/mov/queenMovement.cpp res/mov/pawnMovement.cpp res/mov/knightMovement.cpp res/checkIfMate.cpp res/Collision.cpp res/loadTextures.cpp res/generateDangerMaps.cpp res/getIdatCoord.cpp res/checkNotCheck.cpp res/checkInCheck.cpp res/redrawBoard.cpp res/movePiece.cpp res/drawChessBoard.cpp res/initializeBoard.cpp res/chessPiece.cpp
g++ main.o randomBot.o cccpBot.o botMovement.o kingMovement.o rookMovement.o bishopMovement.o queenMovement.o pawnMovement.o knightMovement.o checkIfMate.o Collision.o loadTextures.o generateDangerMaps.o getIdatCoord.o checkNotCheck.o checkInCheck.o redrawBoard.o movePiece.o drawChessBoard.o initializeBoard.o chessPiece.o -o chess -L"C:\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
del *.o