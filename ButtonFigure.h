#pragma once
#include <SFML/Graphics.hpp>
#include "Figure.h"
#include <memory>
#include <vector>

class ButtonFigure {
protected:
	sf::Sprite icon;

public:
	ButtonFigure(sf::Vector2f pos, sf::Texture& text);
	virtual ~ButtonFigure() = default;
	virtual std::unique_ptr<Figure> createFigure(sf::Vector2f start, sf::Vector2f end, std::vector<std::unique_ptr<Figure>>& allFigures) const = 0;
	bool isClicked(sf::Vector2f mousePos) const;
	void draw(sf::RenderWindow& window) const;
};