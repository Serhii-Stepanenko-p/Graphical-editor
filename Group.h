#pragma once
#include <SFML/Graphics.hpp>
#include "Figure.h"
#include <memory>
#include <vector>
#include <algorithm>

class Group : public Figure {
private:
	sf::RectangleShape groupBox;
	std::vector<std::unique_ptr<Figure>> figures;
	sf::Vector2f startPos;
	sf::Vector2f endPos;

public:
	Group(sf::Vector2f start, sf::Vector2f end, std::vector<std::unique_ptr<Figure>>& allFigures);

	bool has_been_clicked(sf::Vector2f m) const override;
	void draw(sf::RenderWindow& window) const override;
	sf::Vector2f getPosition() const override;
	sf::FloatRect getGlobalBounds() const override;
	void move(sf::Vector2f changePos) override;
	bool removeFigure(const Figure* figureToRemove);
	std::unique_ptr<Figure> clone() const override;
};

