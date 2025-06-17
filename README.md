# Graphical Editor

A simple graphical editor built with C++ using the SFML library. Allows drawing basic geometric shapes, grouping them, and performing basic editing operations.

## Key Features

- **Shape Drawing**: Circle, Rectangle, Triangle
- **Grouping**: Combine multiple shapes into a single group
- **Movement**: Drag shapes with mouse
- **Copy/Paste**: Copy and paste shapes (Ctrl+C, Ctrl+V)
- **Deletion**: Delete selected shapes (Delete key)
- **Screenshot**: Create a screenshot of the current editor state

## System Requirements

- **Compiler**: C++17 or newer
- **Library**: SFML 2.5+
- **OS**: Windows, Linux, macOS

## Project Structure

```
├── Header Files/
│   ├── ButtonFigure.h
│   ├── ButtonReport.h
│   ├── Circle.h
│   ├── CircleButton.h
│   ├── Figure.h
│   ├── GraphicalEditor.h
│   ├── Group.h
│   ├── GroupButton.h
│   ├── Rectangle.h
│   ├── RectangleButton.h
│   ├── resource.h
│   ├── Triangle.h
│   └── TriangleButton.h
├── Source Files/
│   ├── ButtonFigure.cpp
│   ├── ButtonReport.cpp
│   ├── Circle.cpp
│   ├── CircleButton.cpp
│   ├── GraphicalEditor.cpp
│   ├── Group.cpp
│   ├── GroupButton.cpp
│   ├── main_Window.cpp
│   ├── Rectangle.cpp
│   ├── RectangleButton.cpp
│   ├── Triangle.cpp
│   └── TriangleButton.cpp
├── Resource Files/
│   └── laba_OOP.rc
├── External Dependencies/
└── images/               # Folder with icons (if exists)
└── fonts/                # Folder with fonts (if exists)
```

### Toolbar

The program has a toolbar at the top with the following sections:

1. **Saving** - Button to create a screenshot
2. **Instruments** - Basic editing tools  
3. **Figuries** - Buttons for creating shapes
4. **Colors** - Color settings
5. **Grouping** - Grouping tools
6. **Insertion** - Additional tools

### Controls

#### Creating Shapes:
1. Select the desired shape from the toolbar
2. Left-click in the drawing area
3. Drag the mouse to the end point
4. Release the mouse button

#### Selection and Movement:
- Click on a shape to select it
- Drag the selected shape to move it

#### Grouping:
1. Select the "Group" tool
2. Select an area containing shapes to group
3. All shapes in this area will be combined into a group

#### Hotkeys:
- **Delete** - Delete selected shape
- **Ctrl+C** - Copy selected shape
- **Ctrl+V** - Paste copied shape

## Program Architecture

The project follows a modular architecture with separate header and source files for each class:

### Class Structure

#### Core Classes
- **Figure.h/.cpp** - Abstract base class for all shapes
- **Circle.h/.cpp** - Circle shape implementation
- **Rectangle.h/.cpp** - Rectangle shape implementation  
- **Triangle.h/.cpp** - Triangle shape implementation
- **Group.h/.cpp** - Shape grouping functionality

#### Button Classes
- **ButtonFigure.h/.cpp** - Abstract base class for tool buttons
- **ButtonReport.h/.cpp** - Screenshot functionality button
- **CircleButton.h/.cpp** - Circle creation tool
- **RectangleButton.h/.cpp** - Rectangle creation tool
- **TriangleButton.h/.cpp** - Triangle creation tool
- **GroupButton.h/.cpp** - Grouping tool

#### Main Application
- **GraphicalEditor.h/.cpp** - Main application class
- **main_Window.cpp** - Application entry point

#### Resources
- **resource.h** - Resource definitions
- **laba_OOP.rc** - Resource file

### Main Classes

#### Figure (Abstract Base Class)
Base class for all shapes with virtual methods:
- `draw()` - Display the shape
- `has_been_clicked()` - Check for clicks
- `move()` - Move the shape
- `clone()` - Create a copy

#### Concrete Shapes
- **Circle** - Circle with outline
- **Rectangle** - Rectangle with outline
- **Triangle** - Triangle with outline
- **Group** - Group of shapes with joint management

#### Buttons
- **ButtonFigure** - Base class for shape creation buttons
- **ButtonReport** - Button for creating screenshots
- Specialized buttons: CircleButton, RectangleButton, TriangleButton, GroupButton

#### GraphicalEditor
Main program class that manages:
- Window display
- Event handling
- Shape management
- User interface

### Design Patterns

- **Factory Method** - Creating shapes through buttons
- **Composite** - Grouping shapes
- **Prototype** - Cloning shapes for copying

## Functional Features

### Shape Creation
- All shapes have transparent fill with black outline
- Shape size is determined by start and end points
- Live preview while drawing

### Grouping
- Shapes within the selection area are automatically grouped
- Groups can be moved as a single unit
- Groups have blue outline for visual distinction

### Interactivity
- Shape selection with mouse clicks
- Dragging with mouse position tracking
- Copying with offset to avoid overlapping

## Possible Improvements

- Add more shape types (ellipse, line, polygon)
- Implement color selection
- Add undo/redo functionality
- Save/load projects
- Outline thickness settings
- Shape fill colors
- Shape scaling
- Shape rotation

## Author

This project was created as an educational example of working with SFML and basic OOP principles in C++.

## License

Project is available under open license for educational purposes.
