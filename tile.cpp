
#include "tile.h"


Tile::Tile()
{
	x = 10;
	y = 150;
	row = 0;
	column = 0;
	width = 25;
	height = 25;
	moisture = 100;
	clicked = false;
	hovered = false;
	rectangle = sf::RectangleShape(sf::Vector2f(25, 25));
	tileBaseColor.r = (25);
	tileBaseColor.g = (25);
	tileBaseColor.b = (25);
	rectangle.setFillColor(tileBaseColor);
	

}

Tile::Tile(int inputX, int inputY, int inputRow, int inputColumn, int inputWidth, int inputHeight)
{
	x = inputX;
	y = inputY;
	row = inputRow;
	column = inputColumn;
	width = inputWidth;
	height = inputHeight;
	moisture = 100;
	clicked = false;
	hovered = false;
	rectangle = sf::RectangleShape(sf::Vector2f(inputWidth, inputHeight));
	rectangle.setPosition(inputX, inputY);
	rectangle.setFillColor(sf::Color(255, 0, 0));

}

Tile::~Tile()
{

}

void Tile::DrawTile(sf::RenderWindow* window)
{
	window->draw(rectangle);
	//std::cout << "ground drawn  - X:  " << x << "  Y:  " << y <<"  width:  " << width << "  height:  " << height << std::endl;
}

void Tile::Setup(int xInput, int yInput, int columnInput, int rowInput, int widthInput, int heightInput)
{
	x = xInput;
	y = yInput;
	column = columnInput;
	row = rowInput;
	width = widthInput;
	height = heightInput;

	//std::cout << "ground drawn  - X:  " << x << "  Y:  " << y <<"  width:  " << width << "  height:  " << height << std::endl;
}

void Tile::SetPosition()
{
	rectangle.setPosition(x, y);
}

void Tile::setTileColor()
{
	int red(0);
	int green(round(35 * moisture / 100));
	int blue(round(245 * moisture / 100));
	//sf::Color groundColor(red, green, blue);
	sf::Color groundColor(0, 255, 255);
	rectangle.setFillColor(groundColor);
	
}

