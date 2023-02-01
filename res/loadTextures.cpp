#include "loadTextures.hpp"

void loadTextures(){
    Collision::CreateTextureAndBitmask(kingTexture, "./sprites/kingSprite.png");
    Collision::CreateTextureAndBitmask(queenTexture, "./sprites/queenSprite.png");
    Collision::CreateTextureAndBitmask(rookTexture, "./sprites/rookSprite.png");
    Collision::CreateTextureAndBitmask(bishopTexture, "./sprites/bishopSprite.png");
    Collision::CreateTextureAndBitmask(knightTexture, "./sprites/knightSprite.png");
    Collision::CreateTextureAndBitmask(pawnTexture, "./sprites/pawnSprite.png");
}