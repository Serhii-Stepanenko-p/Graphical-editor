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
├── main.cpp              # Main file with program code
├── GraphicalEditor.h     # Header file (if exists)
├── images/               # Folder with icons
│   ├── icon.png
│   ├── circle.png
│   ├── rectangle.png
│   ├── triangle.png
│   ├── group.png
│   └── report.png
└── fonts/                # Folder with fonts
    └── roboto.ttf
```

## Installation and Compilation

### Installing SFML

**Ubuntu/Debian:**
```bash
sudo apt-get install libsfml-dev
```

**macOS:**
```bash
brew install sfml
```

**Windows:**
Download SFML from the official website and configure in your IDE.

### Compilation

```bash
g++ -std=c++17 main.cpp -lsfml-graphics -lsfml-window -lsfml-system -o graphical_editor
```

Or use Makefile:
```makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

graphical_editor: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp $(LIBS) -o graphical_editor

clean:
	rm -f graphical_editor
```

## Usage

### Running the Program
```bash
./graphical_editor
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
