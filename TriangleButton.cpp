#include "TriangleButton.h"

TriangleButton::TriangleButton(sf::Vector2f pos1, sf::Texture& text3) : ButtonFigure(pos1, text3) {
}

std::unique_ptr<Figure> TriangleButton::createFigure(sf::Vector2f start1, sf::Vector2f end1, std::vector<std::unique_ptr<Figure>>& allFigures) const {
	return std::make_unique<Triangle>(start1, end1, sf::Color::Black);
}