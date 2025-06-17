#include "Triangle.h"
#include <algorithm>

Triangle::Triangle(sf::Vector2f start, sf::Vector2f end, sf::Color color)
	: startPos(start), endPos(end), outlineColor(color) {
	triangle.setPointCount(3);
	float minX = std::min(start.x, end.x);
	float maxX = std::max(start.x, end.x);
	float minY = std::min(start.y, end.y);
	float maxY = std::max(start.y, end.y);
	float width = maxX - minX;
	float height = maxY - minY;

	if (width == 0 || height == 0) return;

	triangle.setPoint(0, { width / 2.f, 0 });
	triangle.setPoint(1, { 0, height });
	triangle.setPoint(2, { width, height });
	triangle.setOutlineColor(color);
	triangle.setOutlineThickness(5);
	triangle.setFillColor(sf::Color::Transparent);
	triangle.setPosition({ minX, minY });
}

bool Triangle::has_been_clicked(sf::Vector2f m) const {
	return triangle.getGlobalBounds().contains(m);
}

void Triangle::draw(sf::RenderWindow& window) const {
	window.draw(triangle);
}

sf::Vector2f Triangle::getPosition() const {
	return triangle.getPosition();
}

sf::FloatRect Triangle::getGlobalBounds() const {
	return triangle.getGlobalBounds();
}

void Triangle::move(sf::Vector2f changePos) {
	triangle.move(changePos);
}

std::unique_ptr<Figure> Triangle::clone() const {
	return std::make_unique<Triangle>(startPos, endPos, outlineColor);
}