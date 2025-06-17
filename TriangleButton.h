#pragma once
#include "ButtonFigure.h"
#include "Triangle.h"

class TriangleButton : public ButtonFigure {
public:
	TriangleButton(sf::Vector2f pos1, sf::Texture& text3);
	std::unique_ptr<Figure> createFigure(sf::Vector2f start1, sf::Vector2f end1, std::vector<std::unique_ptr<Figure>>& allFigures) const override;
};
