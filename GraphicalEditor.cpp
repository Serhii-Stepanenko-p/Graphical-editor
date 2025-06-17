#include "GraphicalEditor.h"
#include "Figure.h"
#include "ButtonFigure.h"
#include "ButtonReport.h"
#include "CircleButton.h"
#include "RectangleButton.h"
#include "TriangleButton.h"
#include "GroupButton.h"
#include <algorithm>

GraphicalEditor::GraphicalEditor() : window(sf::VideoMode({ 1440, 920 }), "Graphical Editor") {
    circleText.loadFromFile("images/circle.png");
    rectangleText.loadFromFile("images/rectangle.png");
    triangleText.loadFromFile("images/triangle.png");
    groupText.loadFromFile("images/group.png");
    reportText.loadFromFile("images/report.png");

    buttonFigure.push_back(std::make_unique<CircleButton>(sf::Vector2f(525, 40), circleText));
    buttonFigure.push_back(std::make_unique<RectangleButton>(sf::Vector2f(613, 26), rectangleText));
    buttonFigure.push_back(std::make_unique<TriangleButton>(sf::Vector2f(738, 33), triangleText));
    buttonFigure.push_back(std::make_unique<GroupButton>(sf::Vector2f(1034, 14), groupText));

    if (!font.openFromFile("fonts/roboto.ttf")) {
        std::cerr << "The mistake has been occurred!\n";
    }

    rep_but = std::make_unique<ButtonReport>(sf::Vector2f(59, 54), reportText);

    sf::Text fig_text(font, "Figuries");
    fig_text.setCharacterSize(21);
    fig_text.setFillColor(sf::Color::Black);
    fig_text.setPosition({ 613, 137 });
    text.push_back(fig_text);

    fig_text.setString("Instruments");
    fig_text.setPosition({ 244, 132 });
    text.push_back(fig_text);

    fig_text.setString("Saving");
    fig_text.setPosition({ 45, 132 });
    text.push_back(fig_text);

    fig_text.setString("Colors");
    fig_text.setPosition({ 876, 135 });
    text.push_back(fig_text);

    fig_text.setString("Grouping");
    fig_text.setPosition({ 1031, 132 });
    text.push_back(fig_text);

    fig_text.setString("Insertion");
    fig_text.setPosition({ 1235, 132 });
    text.push_back(fig_text);
}

void GraphicalEditor::handleEvents() {
    const float TOOLBAR_HEIGHT = 137.f;
    const float CLICK_TOLERANCE = 25.f;

    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
        else if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
            if (mousePressed->button == sf::Mouse::Button::Left) {
                sf::Vector2f mousePos(float(mousePressed->position.x), float(mousePressed->position.y));

                if (rep_but->isClicked(mousePos)) {
                    rep_but->createReport(window);
                    return;
                }

                for (auto& btn : buttonFigure) {
                    if (btn->isClicked(mousePos)) {
                        if (std::abs(mousePos.x - first_click.x) < CLICK_TOLERANCE &&
                            std::abs(mousePos.y - first_click.y) < CLICK_TOLERANCE) {
                            activeButton = nullptr;
                            first_click = { 0,0 };
                        }
                        else {
                            activeButton = btn.get();
                            first_click = mousePos;
                        }
                        return;
                    }
                }

                if (activeButton && mousePos.y > TOOLBAR_HEIGHT) {
                    startPos = mousePos;
                    isDrawing = true;

                    if (dynamic_cast<GroupButton*>(activeButton)) {
                        isSelectingGroupArea = true;
                        isDrawing = false;

                        selectionRectangle = std::make_unique<sf::RectangleShape>();
                        selectionRectangle->setFillColor(sf::Color(0, 0, 255, 40));
                        selectionRectangle->setOutlineColor(sf::Color::Blue);
                        selectionRectangle->setOutlineThickness(1);
                        selectionRectangle->setPosition(mousePos);
                        selectionRectangle->setSize({ 0, 0 });
                    }
                }
                else if (!activeButton && mousePos.y > TOOLBAR_HEIGHT) {
                    for (auto it = figuries.rbegin(); it != figuries.rend(); ++it) {
                        if ((*it)->has_been_clicked(mousePos)) {
                            selectedFigure = it->get();
                            previousMousePos = mousePos;
                            isDragging = true;
                            break;
                        }
                    }
                }
            }
        }
        else if (const auto* mouseReleased = event->getIf<sf::Event::MouseButtonReleased>()) {
            if (mouseReleased->button == sf::Mouse::Button::Left) {
                endPos = { float(mouseReleased->position.x), float(mouseReleased->position.y) };

                if (isDrawing && activeButton && endPos.y > TOOLBAR_HEIGHT) {
                    figuries.push_back(activeButton->createFigure(startPos, endPos, figuries));
                }
                else if (isSelectingGroupArea && activeButton) {
                    if (endPos.y > TOOLBAR_HEIGHT) {
                        figuries.push_back(activeButton->createFigure(startPos, endPos, figuries));
                    }
                }

                isDrawing = false;
                isSelectingGroupArea = false;
                selectionRectangle.reset();
                preview_figure.reset();

                isDragging = false;
                //selectedFigure = nullptr;
            }
        }
        else if (const auto* mouseMove = event->getIf<sf::Event::MouseMoved>()) {
            sf::Vector2f currentPos(float(mouseMove->position.x), float(mouseMove->position.y));

            if (isDrawing && activeButton && !dynamic_cast<GroupButton*>(activeButton)) {
                preview_figure = activeButton->createFigure(startPos, currentPos, figuries);
            }
            else if (isSelectingGroupArea) {
                sf::Vector2f size = currentPos - startPos;
                (*selectionRectangle).setPosition(startPos);
                (*selectionRectangle).setSize(size);
            }
            else if (isDragging && selectedFigure) {
                sf::Vector2f delta = currentPos - previousMousePos;
                selectedFigure->move(delta);
                previousMousePos = currentPos;
            }
        }
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Delete) {
                if (selectedFigure) {
                    auto it = std::find_if(
                        figuries.begin(),
                        figuries.end(),
                        [this](const std::unique_ptr<Figure>& fig) {
                            return fig.get() == selectedFigure;
                        }
                    );

                    if (it != figuries.end()) {
                        figuries.erase(it);
                    }
                    selectedFigure = nullptr;
                }
            }
            else if (keyPressed->scancode == sf::Keyboard::Scancode::C && keyPressed->control) {
                if (selectedFigure) {
                    copiedFigure = selectedFigure->clone();
                }
            }
            else if (keyPressed->scancode == sf::Keyboard::Scancode::V && keyPressed->control) {
                if (copiedFigure) {
                    auto newFigure = copiedFigure->clone();
                    newFigure->move({ 20.f, 20.f });
                    figuries.push_back(std::move(newFigure));
                }
            }
        }
    }
}

void GraphicalEditor::render() {
    window.clear(sf::Color::White);

    for (auto& figr : figuries) {
        figr->draw(window);
    }
    if (preview_figure) {
        preview_figure->draw(window);
    }
    if (isSelectingGroupArea && selectionRectangle) {
        window.draw(*selectionRectangle);
    }

    sf::RectangleShape toolBar(sf::Vector2f(window.getSize().x, 167));
    toolBar.setFillColor(sf::Color(230, 230, 230));
    window.draw(toolBar);

    const sf::Texture icon1("images/icon.png");
    sf::Sprite sprite_icon(icon1);
    sprite_icon.setPosition({ 0,0 });
    window.draw(sprite_icon);

    for (auto& btn : buttonFigure) {
        btn->draw(window);
    }
    rep_but->draw(window);
    for (auto& tx : text) {
        window.draw(tx);
    }
    window.display();
}

void GraphicalEditor::run() {
    while (window.isOpen()) {
        handleEvents();
        render();
    }
}
