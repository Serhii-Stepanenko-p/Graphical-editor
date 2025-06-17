#include "Group.h"

Group::Group(sf::Vector2f start, sf::Vector2f end, std::vector<std::unique_ptr<Figure>>& allFigures)
	: startPos(start), endPos(end) {
	sf::FloatRect bounds(start, end - start);
	groupBox.setPosition(start);
	groupBox.setSize(end - start);
	groupBox.setOutlineColor(sf::Color::Blue);
	groupBox.setFillColor(sf::Color::Transparent);
	groupBox.setOutlineThickness(1);

	auto it = allFigures.begin();
	while (it != allFigures.end()) {
		if (bounds.contains((*it)->getPosition())) {
			figures.push_back(std::move(*it));
			it = allFigures.erase(it);
		}
		else {
			++it;
		}
	}
}

bool Group::has_been_clicked(sf::Vector2f m) const {
	return groupBox.getGlobalBounds().contains(m);
}

void Group::draw(sf::RenderWindow& window) const {
	window.draw(groupBox);
	for (const auto& fig : figures) {
		fig->draw(window);
	}
}

sf::Vector2f Group::getPosition() const {
	return groupBox.getPosition();
}

sf::FloatRect Group::getGlobalBounds() const {
	return groupBox.getGlobalBounds();
}

void Group::move(sf::Vector2f changePos) {
	groupBox.move(changePos);
	for (auto& fig : figures) {
		fig->move(changePos);
	}
}

bool Group::removeFigure(const Figure* figureToRemove) {
	auto it = std::find_if(
		figures.begin(),
		figures.end(),
		[figureToRemove](const std::unique_ptr<Figure>& fig) {
			return fig.get() == figureToRemove;
		}
	);
	if (it != figures.end()) {
		figures.erase(it);
		return true;
	}
	return false;
}

std::unique_ptr<Figure> Group::clone() const {
	std::vector<std::unique_ptr<Figure>> clonedFigures;
	for (const auto& fig : figures) {
		clonedFigures.push_back(fig->clone());
	}
	return std::make_unique<Group>(startPos, endPos, clonedFigures);
}