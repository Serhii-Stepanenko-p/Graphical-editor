#pragma once
#include "ButtonFigure.h"
#include "Circle.h"

class CircleButton : public ButtonFigure {
public:
	CircleButton(sf::Vector2f pos1, sf::Texture& text1);
	std::unique_ptr<Figure> createFigure(sf::Vector2f start1, sf::Vector2f end1, std::vector<std::unique_ptr<Figure>>& allFigures) const override;
};
