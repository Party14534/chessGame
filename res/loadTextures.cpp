#include "loadTextures.hpp"

void loadTextures(){
    Collision::CreateTextureAndBitmask(whiteKingTexture, "./sprites/whiteKingSprite.png");
    Collision::CreateTextureAndBitmask(whiteQueenTexture, "./sprites/whiteQueenSprite.png");
    Collision::CreateTextureAndBitmask(whiteRookTexture, "./sprites/whiteRookSprite.png");
    Collision::CreateTextureAndBitmask(whiteBishopTexture, "./sprites/whiteBishopSprite.png");
    Collision::CreateTextureAndBitmask(whiteKnightTexture, "./sprites/whiteKnightSprite.png");
    Collision::CreateTextureAndBitmask(whitePawnTexture, "./sprites/whitePawnSprite.png");
    Collision::CreateTextureAndBitmask(blackKingTexture, "./sprites/blackKingSprite.png");
    Collision::CreateTextureAndBitmask(blackQueenTexture, "./sprites/blackQueenSprite.png");
    Collision::CreateTextureAndBitmask(blackRookTexture, "./sprites/blackRookSprite.png");
    Collision::CreateTextureAndBitmask(blackBishopTexture, "./sprites/blackBishopSprite.png");
    Collision::CreateTextureAndBitmask(blackKnightTexture, "./sprites/blackKnightSprite.png");
    Collision::CreateTextureAndBitmask(blackPawnTexture, "./sprites/blackPawnSprite.png");
}