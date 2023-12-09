#include "loadTextures.hpp"

void loadTextures(){
    Collision::CreateTextureAndBitmask(whiteKingTexture, "../src/sprites/whiteKingSprite.png");
    Collision::CreateTextureAndBitmask(whiteQueenTexture, "../src/sprites/whiteQueenSprite.png");
    Collision::CreateTextureAndBitmask(whiteRookTexture, "../src/sprites/whiteRookSprite.png");
    Collision::CreateTextureAndBitmask(whiteBishopTexture, "../src/sprites/whiteBishopSprite.png");
    Collision::CreateTextureAndBitmask(whiteKnightTexture, "../src/sprites/whiteKnightSprite.png");
    Collision::CreateTextureAndBitmask(whitePawnTexture, "../src/sprites/whitePawnSprite.png");
    Collision::CreateTextureAndBitmask(blackKingTexture, "../src/sprites/blackKingSprite.png");
    Collision::CreateTextureAndBitmask(blackQueenTexture, "../src/sprites/blackQueenSprite.png");
    Collision::CreateTextureAndBitmask(blackRookTexture, "../src/sprites/blackRookSprite.png");
    Collision::CreateTextureAndBitmask(blackBishopTexture, "../src/sprites/blackBishopSprite.png");
    Collision::CreateTextureAndBitmask(blackKnightTexture, "../src/sprites/blackKnightSprite.png");
    Collision::CreateTextureAndBitmask(blackPawnTexture, "../src/sprites/blackPawnSprite.png");
}