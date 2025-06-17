#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <iostream>

#include "Figure.h"
#include "ButtonFigure.h"
#include "ButtonReport.h"
#include "GroupButton.h"
#include "CircleButton.h"
#include "RectangleButton.h"
#include "TriangleButton.h"


class GraphicalEditor {
private:
    sf::RenderWindow window;
    std::vector<std::unique_ptr<Figure>> figuries;
    std::vector<std::unique_ptr<ButtonFigure>> buttonFigure;
    std::unique_ptr<ButtonReport> rep_but;
    sf::Texture circleText, rectangleText, triangleText, groupText, reportText;
    std::vector<sf::Text> text;
    ButtonFigure* activeButton = nullptr;
    sf::Font font;
    sf::Vector2f startPos;
    sf::Vector2f endPos;
    sf::Vector2f first_click;
    std::unique_ptr<Figure> preview_figure;
    bool isDrawing = false;
    bool isSelectingGroupArea = false;
    std::unique_ptr<sf::RectangleShape> selectionRectangle;
    Figure* selectedFigure = nullptr;
    sf::Vector2f previousMousePos;
    std::unique_ptr<Figure> copiedFigure = nullptr;
    bool isDragging = false;

    void handleEvents();
    void render();

public:
    GraphicalEditor();
    void run();
};