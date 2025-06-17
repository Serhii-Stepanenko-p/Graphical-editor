#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class ButtonReport {
protected:
	sf::Sprite icon;

public:
	ButtonReport(sf::Vector2f pos, sf::Texture& text);
	void createReport(sf::RenderWindow& window);
	bool isClicked(sf::Vector2f mousePos) const;
	void draw(sf::RenderWindow& window) const;
};