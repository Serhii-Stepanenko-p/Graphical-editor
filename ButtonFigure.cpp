#include "ButtonFigure.h"

ButtonFigure::ButtonFigure(sf::Vector2f pos, sf::Texture& text) : icon(text) {
	icon.setPosition(pos);
}

bool ButtonFigure::isClicked(sf::Vector2f mousePos) const {
	return icon.getGlobalBounds().contains(mousePos);
}

void ButtonFigure::draw(sf::RenderWindow& window) const {
	window.draw(icon);
}