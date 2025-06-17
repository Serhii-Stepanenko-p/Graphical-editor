#include "CircleButton.h"

CircleButton::CircleButton(sf::Vector2f pos1, sf::Texture& text1) : ButtonFigure(pos1, text1) {
}

std::unique_ptr<Figure> CircleButton::createFigure(sf::Vector2f start1, sf::Vector2f end1, std::vector<std::unique_ptr<Figure>>& allFigures) const {
	return std::make_unique<Circle>(start1, end1, sf::Color::Black);
}