#pragma once
#include "ButtonFigure.h"
#include "Rectangle.h"

class RectangleButton : public ButtonFigure {
public:
	RectangleButton(sf::Vector2f pos1, sf::Texture& text2);
	std::unique_ptr<Figure> createFigure(sf::Vector2f start1, sf::Vector2f end1, std::vector<std::unique_ptr<Figure>>& allFigures) const override;
};
