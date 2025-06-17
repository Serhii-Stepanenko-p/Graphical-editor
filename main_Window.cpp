#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <memory>
#include <algorithm>
#include "GraphicalEditor.h"

//class Figure {
//public:
//	virtual ~Figure()=default;
//	virtual void draw(sf::RenderWindow& window) const=0;
//	virtual bool has_been_clicked(sf::Vector2f m) const=0;
//	virtual sf::Vector2f getPosition() const = 0;         
//	virtual sf::FloatRect getGlobalBounds() const = 0;
//	virtual void move(sf::Vector2f changePos) = 0;
//	virtual std::unique_ptr<Figure> clone() const = 0;
//};
//
//class Circle : public Figure {
//private:
//	sf::CircleShape circle;
//	sf::Vector2f startPos;
//	sf::Vector2f endPos;
//	sf::Color outlineColor;
//public:
//	Circle(sf::Vector2f start, sf::Vector2f end, sf::Color color)
//		: startPos(start), endPos(end), outlineColor(color) {
//		float radius = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2)) / 2.0f;
//
//		circle.setRadius(radius);
//
//		circle.setOrigin({ radius, radius });
//
//		sf::Vector2f center = (start + end) / 2.0f;
//		circle.setPosition(center);
//
//		circle.setOutlineThickness(5);
//		circle.setOutlineColor(color);
//		circle.setFillColor(sf::Color::Transparent);
//	}
//	bool has_been_clicked(sf::Vector2f m)const override {
//		return circle.getGlobalBounds().contains(m);
//	}
//	void draw(sf::RenderWindow& window) const override {
//		window.draw(circle);
//	}
//	sf::Vector2f getPosition() const override {
//		return circle.getPosition();
//	}
//
//	sf::FloatRect getGlobalBounds() const override {
//		return circle.getGlobalBounds();
//	}
//	void move(sf::Vector2f changePos)override {
//		circle.move(changePos);
//	}
//	std::unique_ptr<Figure> clone() const override {
//		return std::make_unique<Circle>(startPos, endPos, outlineColor);
//	}
//};
//
//class Rectangle : public Figure {
//private:
//	sf::RectangleShape rectangleShape;
//	sf::Vector2f startPos;
//	sf::Vector2f endPos;
//	sf::Color outlineColor;
//public:
//	Rectangle(sf::Vector2f start, sf::Vector2f pos2, sf::Color col)
//		: startPos(start), endPos(pos2), outlineColor(col)
//	{
//		rectangleShape.setSize({ pos2.x - start.x,pos2.y - start.y });
//		rectangleShape.setOutlineColor(col);
//		rectangleShape.setFillColor(sf::Color::Transparent);
//		rectangleShape.setOutlineThickness(5);
//		rectangleShape.setPosition(start);
//	}
//	bool has_been_clicked(sf::Vector2f m)const override {
//		return rectangleShape.getGlobalBounds().contains(m);
//	}
//
//	void draw(sf::RenderWindow& window) const override {
//		window.draw(rectangleShape);
//	}
//	sf::Vector2f getPosition() const override {
//		return rectangleShape.getPosition();
//	}
//
//	sf::FloatRect getGlobalBounds() const override {
//		return rectangleShape.getGlobalBounds();
//	}
//	void move(sf::Vector2f changePos)override {
//		rectangleShape.move(changePos);
//	}
//	std::unique_ptr<Figure> clone() const override {
//		return std::make_unique<Rectangle>(startPos, endPos, outlineColor);
//	}
//};

//class Group : public Figure {
//private:
//	sf::RectangleShape groupBox;
//	std::vector<std::unique_ptr<Figure>> figures;
//	sf::Vector2f startPos;
//	sf::Vector2f endPos;
//public:
//	Group(sf::Vector2f start, sf::Vector2f end, std::vector<std::unique_ptr<Figure>>& allFigures)
//	:startPos(start),endPos(end)
//	{
//		sf::FloatRect bounds(start, end - start);
//		groupBox.setPosition(start);
//		groupBox.setSize(end - start);
//		groupBox.setOutlineColor(sf::Color::Blue);
//		groupBox.setFillColor(sf::Color::Transparent);
//		groupBox.setOutlineThickness(1);
//
//		auto it = allFigures.begin();
//		while (it != allFigures.end()) {
//			if (bounds.contains((*it)->getPosition())) {
//				figures.push_back(std::move(*it));
//				it = allFigures.erase(it);
//			}
//			else {
//				++it;
//			}
//		}
//	}
//	bool has_been_clicked(sf::Vector2f m) const override {
//		return groupBox.getGlobalBounds().contains(m);
//	}
//	void draw(sf::RenderWindow& window) const override {
//		window.draw(groupBox);
//		for (const auto& fig : figures) {
//			fig->draw(window);
//		}
//	}
//	sf::Vector2f getPosition() const override {
//		return groupBox.getPosition();
//	}
//	sf::FloatRect getGlobalBounds() const override {
//		return groupBox.getGlobalBounds();
//	}
//	void move(sf::Vector2f changePos) override{
//		groupBox.move(changePos);
//		auto it = figures.begin();
//		for (auto& fig: figures) {
//			fig->move(changePos);
//		}
//	}
//	bool removeFigure(const Figure* figureToRemove) {
//		auto it = std::find_if(
//			figures.begin(),
//			figures.end(),
//			[figureToRemove](const std::unique_ptr<Figure>& fig) {
//				return fig.get() == figureToRemove;
//			}
//		);
//
//		if (it != figures.end()) {
//			figures.erase(it);
//			return true;
//		}
//		return false; 
//	}
//	std::unique_ptr<Figure> clone() const override {
//		std::vector<std::unique_ptr<Figure>> clonedFigures;
//		for (const auto& fig : figures) {
//			clonedFigures.push_back(fig->clone());
//		}
//
//		return std::make_unique<Group>(startPos, endPos, clonedFigures);
//	}
//};

//class Triangle : public Figure {
//private:
//	sf::ConvexShape triangle;
//	sf::Vector2f startPos;
//	sf::Vector2f endPos;
//	sf::Color outlineColor;
//public:
//	Triangle(sf::Vector2f start, sf::Vector2f end, sf::Color color) 
//		: startPos(start), endPos(end), outlineColor(color) {
//		triangle.setPointCount(3);
//
//		float minX = std::min(start.x, end.x);
//		float maxX = std::max(start.x, end.x);
//		float minY = std::min(start.y, end.y);
//		float maxY = std::max(start.y, end.y);
//
//		float width = maxX - minX;
//		float height = maxY - minY;
//		if (width == 0 || height == 0) return;
//		triangle.setPoint(0, { width / 2.f, 0 });       
//		triangle.setPoint(1, { 0, height });             
//		triangle.setPoint(2, { width, height });         
//
//		triangle.setOutlineColor(color);
//		triangle.setOutlineThickness(5);
//		triangle.setFillColor(sf::Color::Transparent);
//
//		triangle.setPosition({ minX, minY }); 
//	}
//	bool has_been_clicked(sf::Vector2f m)const override {
//		return triangle.getGlobalBounds().contains(m);
//	}
//
//	void draw(sf::RenderWindow& window) const override {
//		window.draw(triangle);
//	}
//	sf::Vector2f getPosition() const override {
//		return triangle.getPosition();
//	}
//
//	sf::FloatRect getGlobalBounds() const override {
//		return triangle.getGlobalBounds();
//	}
//	void move(sf::Vector2f changePos)override {
//		triangle.move(changePos);
//	}
//	std::unique_ptr<Figure> clone() const override {
//		return std::make_unique<Triangle>(startPos, endPos, outlineColor);
//	}
//};

//class ButtonReport {
//protected:
//	sf::Sprite icon;
//public:
//	ButtonReport(sf::Vector2f pos, sf::Texture& text) :icon(text) {
//		icon.setPosition(pos);
//	}
//	void createReport(sf::RenderWindow& window) {
//		sf::Texture texture(sf::Vector2u(window.getSize().x, window.getSize().y));
//		texture.update(window);
//		sf::Image screenshot = texture.copyToImage();
//		if (!screenshot.saveToFile("screenshot.png")) {
//			std::cerr << "Failed to save screenshot!" << std::endl;
//		}
//	}
//
//	bool isClicked(sf::Vector2f mousePos)const {
//		return icon.getGlobalBounds().contains(mousePos);
//	}
//	void draw(sf::RenderWindow& window)const {
//		window.draw(icon);
//	}
//};

//class ButtonFigure {
//protected:
//	sf::Sprite icon;
//public:
//	ButtonFigure(sf::Vector2f pos, sf::Texture& text):icon(text) {
//		icon.setPosition(pos);
//	}
//	virtual ~ButtonFigure()=default;
//	virtual std::unique_ptr<Figure> createFigure(sf::Vector2f start, sf::Vector2f end, std::vector<std::unique_ptr<Figure>>& allFigures) const = 0;
//
//	bool isClicked(sf::Vector2f mousePos)const {
//		return icon.getGlobalBounds().contains(mousePos);
//	}
//	void draw(sf::RenderWindow& window)const {
//		window.draw(icon);
//	}
//};


//class CircleButton:public ButtonFigure {
//public:
//	CircleButton(sf::Vector2f pos1,sf::Texture& text1):ButtonFigure(pos1,text1)
//	{
//	}
//	std::unique_ptr<Figure> createFigure(sf::Vector2f start1, sf::Vector2f end1, std::vector<std::unique_ptr<Figure>>& allFigures) const override {
//		return std::make_unique<Circle>(start1, end1, sf::Color::Black);
//	}
//};
//
//class RectangleButton :public ButtonFigure {
//public:
//	RectangleButton(sf::Vector2f pos1,sf::Texture& text2) :ButtonFigure(pos1,text2)
//	{
//	}
//	std::unique_ptr<Figure> createFigure(sf::Vector2f start1, sf::Vector2f end1, std::vector<std::unique_ptr<Figure>>& allFigures) const override {
//		return std::make_unique<Rectangle>(start1, end1, sf::Color::Black);
//	}
//};
//
//class GroupButton :public ButtonFigure {
//public:
//	GroupButton(sf::Vector2f pos1, sf::Texture& text2) :ButtonFigure(pos1, text2)
//	{
//	}
//	std::unique_ptr<Figure> createFigure(sf::Vector2f start1, sf::Vector2f end1, std::vector<std::unique_ptr<Figure>>& allFigures) const override {
//		return std::make_unique<Group>(start1, end1, allFigures);
//	}
//};
//
//class TriangleButton :public ButtonFigure {
//public:
//	TriangleButton(sf::Vector2f pos1, sf::Texture& text3) :ButtonFigure(pos1,text3)
//	{
//	}
//	std::unique_ptr<Figure> createFigure(sf::Vector2f start1, sf::Vector2f end1,std::vector<std::unique_ptr<Figure>>& allFigures) const override {
//		return std::make_unique<Triangle>(start1, end1, sf::Color::Black);
//	}
//};
//class GraphicalEditor {
//private:
//	sf::RenderWindow window;
//	std::vector<std::unique_ptr<Figure>> figuries;
//	std::vector<std::unique_ptr<ButtonFigure>> buttonFigure;
//	std::unique_ptr<ButtonReport> rep_but;
//	sf::Texture circleText, rectangleText, triangleText, groupText,reportText;
//	std::vector<sf::Text> text;
//	ButtonFigure* activeButton = nullptr;
//	sf::Font font;
//	sf::Vector2f startPos;
//	sf::Vector2f endPos;
//	sf::Vector2f first_click;
//	std::unique_ptr<Figure> preview_figure;
//	bool isDrawing = false;
//	bool isSelectingGroupArea = false;
//	std::unique_ptr<sf::RectangleShape> selectionRectangle;
//	Figure* selectedFigure = nullptr;
//	sf::Vector2f previousMousePos;
//	std::unique_ptr<Figure> copiedFigure = nullptr;
//	bool isDragging = false;
//
//	void handleEvents() {
//		const float TOOLBAR_HEIGHT = 137.f;
//		const float CLICK_TOLERANCE = 25.f;
//
//		while (const std::optional event = window.pollEvent()) {
//			if (event->is<sf::Event::Closed>()) {
//				window.close();
//			}
//			else if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
//				if (mousePressed->button == sf::Mouse::Button::Left) {
//					sf::Vector2f mousePos(float(mousePressed->position.x), float(mousePressed->position.y));
//
//					if (rep_but->isClicked(mousePos)) {
//						rep_but->createReport(window); 
//						return;
//					}
//
//					for (auto& btn : buttonFigure) {
//						if (btn->isClicked(mousePos)) {
//							if (std::abs(mousePos.x - first_click.x) < CLICK_TOLERANCE &&
//								std::abs(mousePos.y - first_click.y) < CLICK_TOLERANCE) {
//								activeButton = nullptr;
//								first_click = { 0,0 };
//							}
//							else {
//								activeButton = btn.get();
//								first_click = mousePos;
//							}
//							return;
//						}
//					}
//
//					if (activeButton && mousePos.y > TOOLBAR_HEIGHT) {
//						startPos = mousePos;
//						isDrawing = true;
//
//						if (dynamic_cast<GroupButton*>(activeButton)) {
//							isSelectingGroupArea = true;
//							isDrawing = false;
//
//							selectionRectangle = std::make_unique<sf::RectangleShape>();
//							selectionRectangle->setFillColor(sf::Color(0, 0, 255, 40));
//							selectionRectangle->setOutlineColor(sf::Color::Blue);
//							selectionRectangle->setOutlineThickness(1);
//							selectionRectangle->setPosition(mousePos);
//							selectionRectangle->setSize({ 0, 0 });
//						}
//					}
//					else if (!activeButton && mousePos.y > TOOLBAR_HEIGHT) {
//						for (auto it = figuries.rbegin(); it != figuries.rend(); ++it) {
//							if ((*it)->has_been_clicked(mousePos)) {
//								selectedFigure = it->get();
//								previousMousePos = mousePos;
//								isDragging = true;
//								break;
//							}
//						}
//					}
//				}
//			}
//			else if (const auto* mouseReleased = event->getIf<sf::Event::MouseButtonReleased>()) {
//				if (mouseReleased->button == sf::Mouse::Button::Left) {
//					endPos = { float(mouseReleased->position.x), float(mouseReleased->position.y) };
//
//					if (isDrawing && activeButton && endPos.y > TOOLBAR_HEIGHT) {
//						figuries.push_back(activeButton->createFigure(startPos, endPos, figuries));
//					}
//					else if (isSelectingGroupArea && activeButton) {
//						if (endPos.y > TOOLBAR_HEIGHT) {
//							figuries.push_back(activeButton->createFigure(startPos, endPos, figuries));
//						}
//					}
//
//					isDrawing = false;
//					isSelectingGroupArea = false;
//					selectionRectangle.reset();
//					preview_figure.reset();
//
//					isDragging = false;
//					//selectedFigure = nullptr;
//				}
//			}
//			else if (const auto* mouseMove = event->getIf<sf::Event::MouseMoved>()) {
//				sf::Vector2f currentPos(float(mouseMove->position.x), float(mouseMove->position.y));
//
//				if (isDrawing && activeButton && !dynamic_cast<GroupButton*>(activeButton)) {
//					preview_figure = activeButton->createFigure(startPos, currentPos, figuries);
//				}
//				else if (isSelectingGroupArea) {
//					sf::Vector2f size = currentPos - startPos;
//					(*selectionRectangle).setPosition(startPos);
//					(*selectionRectangle).setSize(size);
//				}
//				else if (isDragging && selectedFigure) {
//					sf::Vector2f delta = currentPos - previousMousePos;
//					selectedFigure->move(delta);
//					previousMousePos = currentPos;
//				}
//			}
//			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
//				if (keyPressed->scancode == sf::Keyboard::Scancode::Delete) {
//					if (selectedFigure) {
//						auto it = std::find_if(
//							figuries.begin(),
//							figuries.end(),
//							[this](const std::unique_ptr<Figure>& fig) {
//								return fig.get() == selectedFigure;
//							}
//						);
//
//						if (it != figuries.end()) {
//							figuries.erase(it);
//						}
//						selectedFigure = nullptr;
//					}
//				}
//				else if (keyPressed->scancode == sf::Keyboard::Scancode::C && keyPressed->control) {
//					if (selectedFigure) {
//						copiedFigure = selectedFigure->clone();
//					}
//				}
//				else if (keyPressed->scancode == sf::Keyboard::Scancode::V && keyPressed->control) {
//					if (copiedFigure) {
//						auto newFigure = copiedFigure->clone();
//						newFigure->move({ 20.f, 20.f });
//						figuries.push_back(std::move(newFigure));
//					}
//				}
//			}
//		}
//	}
//
//	void render() {
//		window.clear(sf::Color::White);
//
//		for (auto& figr : figuries) {
//			figr->draw(window);
//		}
//		if (preview_figure) {
//			preview_figure->draw(window);
//		}
//		if (isSelectingGroupArea && selectionRectangle) {
//			window.draw(*selectionRectangle);
//		}
//
//		sf::RectangleShape toolBar(sf::Vector2f(window.getSize().x, 167));
//		toolBar.setFillColor(sf::Color(230, 230, 230));
//		window.draw(toolBar);
//
//		const sf::Texture icon1("images/icon.png");
//		sf::Sprite sprite_icon(icon1);
//		sprite_icon.setPosition({ 0,0 });
//		window.draw(sprite_icon);
//
//		for (auto& btn : buttonFigure) {
//			btn->draw(window);
//		}
//		rep_but->draw(window);
//		for (auto& tx : text) {
//			window.draw(tx);
//		}
//		window.display();
//	}
//
//public:
//	GraphicalEditor() : window(sf::VideoMode({ 1440, 920 }), "Graphical Editor") {
//		circleText.loadFromFile("images/circle.png");
//		rectangleText.loadFromFile("images/rectangle.png");
//		triangleText.loadFromFile("images/triangle.png");
//		groupText.loadFromFile("images/group.png");
//		reportText.loadFromFile("images/report.png");
//
//		buttonFigure.push_back(std::make_unique<CircleButton>(sf::Vector2f(525, 40), circleText));
//		buttonFigure.push_back(std::make_unique<RectangleButton>(sf::Vector2f(613, 26), rectangleText));
//		buttonFigure.push_back(std::make_unique<TriangleButton>(sf::Vector2f(738, 33), triangleText));
//		buttonFigure.push_back(std::make_unique<GroupButton>(sf::Vector2f(1034, 14), groupText));
//
//		if (!font.openFromFile("fonts/roboto.ttf")) {
//			std::cerr << "The mistake has been occurred!\n";
//		}
//
//		rep_but = std::make_unique<ButtonReport>(sf::Vector2f(59, 54), reportText);
//
//		sf::Text fig_text(font, "Figuries");
//		fig_text.setCharacterSize(21);
//		fig_text.setFillColor(sf::Color::Black);
//		fig_text.setPosition({ 613, 137 });
//		text.push_back(fig_text);
//
//		fig_text.setString("Instruments");
//		fig_text.setPosition({ 244, 132 });
//		text.push_back(fig_text);
//
//		fig_text.setString("Saving");
//		fig_text.setPosition({ 45, 132 });
//		text.push_back(fig_text);
//
//		fig_text.setString("Colors");
//		fig_text.setPosition({ 876, 135 });
//		text.push_back(fig_text);
//
//		fig_text.setString("Grouping");
//		fig_text.setPosition({ 1031, 132 });
//		text.push_back(fig_text);
//
//		fig_text.setString("Insertion");
//		fig_text.setPosition({ 1235, 132 });
//		text.push_back(fig_text);
//	}
//
//	void run() {
//		while (window.isOpen()) {
//			handleEvents();
//			render();
//		}
//	}
//};

int main() {
	GraphicalEditor graphicalEditor;
	graphicalEditor.run();
	return 0;
}