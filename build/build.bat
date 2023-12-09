g++ -s -w -I"C:\SFML-2.6.0\include" -L"C:\SFML-2.6.0\lib" ^
../src/main.cpp ^
../src/helperFunctions/bots/minCccpBot.cpp ^
../src/helperFunctions/bots/minMovesBot.cpp ^
../src/helperFunctions/getEval.cpp ^
../src/helperFunctions/generateFen.cpp ^
../src/helperFunctions/bots/randomBot.cpp ^
../src/helperFunctions/bots/cccpBot.cpp ^
../src/helperFunctions/bots/botMovement.cpp ^
../src/helperFunctions/mov/kingMovement.cpp ^
../src/helperFunctions/mov/rookMovement.cpp ^
../src/helperFunctions/mov/bishopMovement.cpp ^
../src/helperFunctions/mov/queenMovement.cpp ^
../src/helperFunctions/mov/pawnMovement.cpp ^
../src/helperFunctions/mov/knightMovement.cpp ^
../src/helperFunctions/checkIfMate.cpp ^
../src/helperFunctions/Collision.cpp ^
../src/helperFunctions/loadTextures.cpp ^
../src/helperFunctions/generateDangerMaps.cpp ^
../src/helperFunctions/getIdatCoord.cpp ^
../src/helperFunctions/checkNotCheck.cpp ^
../src/helperFunctions/checkInCheck.cpp ^
../src/helperFunctions/redrawBoard.cpp ^
../src/helperFunctions/movePiece.cpp ^
../src/helperFunctions/drawChessBoard.cpp ^
../src/helperFunctions/initializeBoard.cpp ^
../src/helperFunctions/chessPiece.cpp ^
-o chess -lsfml-graphics -lsfml-window -lsfml-system