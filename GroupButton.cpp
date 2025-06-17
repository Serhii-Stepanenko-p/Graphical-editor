#include "GroupButton.h"

GroupButton::GroupButton(sf::Vector2f pos1, sf::Texture& text2) : ButtonFigure(pos1, text2) {
}

std::unique_ptr<Figure> GroupButton::createFigure(sf::Vector2f start1, sf::Vector2f end1, std::vector<std::unique_ptr<Figure>>& allFigures) const {
	return std::make_unique<Group>(start1, end1, allFigures);
}
