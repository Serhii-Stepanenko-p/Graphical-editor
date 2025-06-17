#include "RectangleButton.h"

RectangleButton::RectangleButton(sf::Vector2f pos1, sf::Texture& text2) : ButtonFigure(pos1, text2) {
}

std::unique_ptr<Figure> RectangleButton::createFigure(sf::Vector2f start1, sf::Vector2f end1, std::vector<std::unique_ptr<Figure>>& allFigures) const {
	return std::make_unique<Rectangle>(start1, end1, sf::Color::Black);
}