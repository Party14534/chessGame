#ifndef DRAWBOARD_HPP
#define DRAWBOARD_HPP
#include <SFML/Graphics.hpp>
#include <vector>

inline std::vector<sf::RectangleShape> chessBoard;
inline std::vector<sf::CircleShape> moveBoard;
void drawChessBoard(float width, float height);


#endif