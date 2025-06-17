#include "Rectangle.h"

Rectangle::Rectangle(sf::Vector2f start, sf::Vector2f pos2, sf::Color col)
	: startPos(start), endPos(pos2), outlineColor(col) {
	rectangleShape.setSize({ pos2.x - start.x, pos2.y - start.y });
	rectangleShape.setOutlineColor(col);
	rectangleShape.setFillColor(sf::Color::Transparent);
	rectangleShape.setOutlineThickness(5);
	rectangleShape.setPosition(start);
}

bool Rectangle::has_been_clicked(sf::Vector2f m) const {
	return rectangleShape.getGlobalBounds().contains(m);
}

void Rectangle::draw(sf::RenderWindow& window) const {
	window.draw(rectangleShape);
}

sf::Vector2f Rectangle::getPosition() const {
	return rectangleShape.getPosition();
}

sf::FloatRect Rectangle::getGlobalBounds() const {
	return rectangleShape.getGlobalBounds();
}

void Rectangle::move(sf::Vector2f changePos) {
	rectangleShape.move(changePos);
}

std::unique_ptr<Figure> Rectangle::clone() const {
	return std::make_unique<Rectangle>(startPos, endPos, outlineColor);
}