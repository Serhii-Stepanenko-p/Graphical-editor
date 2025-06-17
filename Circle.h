#pragma once
#include <SFML/Graphics.hpp>
#include "Figure.h"
#include <memory>

class Circle : public Figure {
private:
	sf::CircleShape circle;
	sf::Vector2f startPos;
	sf::Vector2f endPos;
	sf::Color outlineColor;

public:
	Circle(sf::Vector2f start, sf::Vector2f end, sf::Color color);

	bool has_been_clicked(sf::Vector2f m) const override;
	void draw(sf::RenderWindow& window) const override;
	sf::Vector2f getPosition() const override;
	sf::FloatRect getGlobalBounds() const override;
	void move(sf::Vector2f changePos) override;
	std::unique_ptr<Figure> clone() const override;
};