#include "Circle.h"
#include <cmath>

Circle::Circle(sf::Vector2f start, sf::Vector2f end, sf::Color color)
	: startPos(start), endPos(end), outlineColor(color) {
	float radius = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2)) / 2.0f;
	circle.setRadius(radius);
	circle.setOrigin({ radius, radius });
	sf::Vector2f center = (start + end) / 2.0f;
	circle.setPosition(center);
	circle.setOutlineThickness(5);
	circle.setOutlineColor(color);
	circle.setFillColor(sf::Color::Transparent);
}

bool Circle::has_been_clicked(sf::Vector2f m) const {
	return circle.getGlobalBounds().contains(m);
}

void Circle::draw(sf::RenderWindow& window) const {
	window.draw(circle);
}

sf::Vector2f Circle::getPosition() const {
	return circle.getPosition();
}

sf::FloatRect Circle::getGlobalBounds() const {
	return circle.getGlobalBounds();
}

void Circle::move(sf::Vector2f changePos) {
	circle.move(changePos);
}

std::unique_ptr<Figure> Circle::clone() const {
	return std::make_unique<Circle>(startPos, endPos, outlineColor);
}