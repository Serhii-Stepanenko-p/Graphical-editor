#pragma once
#include "ButtonFigure.h"
#include "Group.h"

class GroupButton : public ButtonFigure {
public:
	GroupButton(sf::Vector2f pos1, sf::Texture& text2);
	std::unique_ptr<Figure> createFigure(sf::Vector2f start1, sf::Vector2f end1, std::vector<std::unique_ptr<Figure>>& allFigures) const override;
};

