#include "ButtonReport.h"

ButtonReport::ButtonReport(sf::Vector2f pos, sf::Texture& text) : icon(text) {
	icon.setPosition(pos);
}

void ButtonReport::createReport(sf::RenderWindow& window) {
	sf::Texture texture(sf::Vector2u(window.getSize().x, window.getSize().y));
	texture.update(window);
	sf::Image screenshot = texture.copyToImage();
	if (!screenshot.saveToFile("screenshot.png")) {
		std::cerr << "Failed to save screenshot!" << std::endl;
	}
}

bool ButtonReport::isClicked(sf::Vector2f mousePos) const {
	return icon.getGlobalBounds().contains(mousePos);
}

void ButtonReport::draw(sf::RenderWindow& window) const {
	window.draw(icon);
}