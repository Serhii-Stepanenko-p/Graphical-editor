#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Figure {
public:
	virtual ~Figure() = default;
	virtual void draw(sf::RenderWindow& window) const = 0;
	virtual bool has_been_clicked(sf::Vector2f m) const = 0;
	virtual sf::Vector2f getPosition() const = 0;
	virtual sf::FloatRect getGlobalBounds() const = 0;
	virtual void move(sf::Vector2f changePos) = 0;
	virtual std::unique_ptr<Figure> clone() const = 0;
};