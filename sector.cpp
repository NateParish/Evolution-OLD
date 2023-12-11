#include "sector.h"


Sector::Sector(sf::RenderWindow* window)
{
	windowPtr = window;
	originX = 755;
	originY = 250;
	cellSize = 25;
	

	tile1.Setup(originX + (0 * cellSize), originY + (0 * cellSize), 1, 1, cellSize, cellSize);
	tile2.Setup(originX + (1 * cellSize), originY + (0 * cellSize), 2, 1, cellSize, cellSize);
	tile3.Setup(originX + (2 * cellSize), originY + (0 * cellSize), 3, 1, cellSize, cellSize);
	tile4.Setup(originX + (3 * cellSize), originY + (0 * cellSize), 4, 1, cellSize, cellSize);
	tile5.Setup(originX + (4 * cellSize), originY + (0 * cellSize), 5, 1, cellSize, cellSize);
	tile6.Setup(originX + (5 * cellSize), originY + (0 * cellSize), 6, 1, cellSize, cellSize);
	
	tile7.Setup(originX + (0 * cellSize), originY + (1 * cellSize), 1, 2, cellSize, cellSize);
	tile8.Setup(originX + (1 * cellSize), originY + (1 * cellSize), 2, 2, cellSize, cellSize);
	tile9.Setup(originX + (2 * cellSize), originY + (1 * cellSize), 3, 2, cellSize, cellSize);
	tile10.Setup(originX + (3 * cellSize), originY + (1 * cellSize), 4, 2, cellSize, cellSize);
	tile11.Setup(originX + (4 * cellSize), originY + (1 * cellSize), 5, 2, cellSize, cellSize);
	tile12.Setup(originX + (5 * cellSize), originY + (1 * cellSize), 6, 2, cellSize, cellSize);

	tile13.Setup(originX + (0 * cellSize), originY + (2 * cellSize), 1, 3, cellSize, cellSize);
	tile14.Setup(originX + (1 * cellSize), originY + (2 * cellSize), 2, 3, cellSize, cellSize);
	tile15.Setup(originX + (2 * cellSize), originY + (2 * cellSize), 3, 3, cellSize, cellSize);
	tile16.Setup(originX + (3 * cellSize), originY + (2 * cellSize), 4, 3, cellSize, cellSize);
	tile17.Setup(originX + (4 * cellSize), originY + (2 * cellSize), 5, 3, cellSize, cellSize);
	tile18.Setup(originX + (5 * cellSize), originY + (2 * cellSize), 6, 3, cellSize, cellSize);

	tile19.Setup(originX + (0 * cellSize), originY + (3 * cellSize), 1, 4, cellSize, cellSize);
	tile20.Setup(originX + (1 * cellSize), originY + (3 * cellSize), 2, 4, cellSize, cellSize);
	tile21.Setup(originX + (2 * cellSize), originY + (3 * cellSize), 3, 4, cellSize, cellSize);
	tile22.Setup(originX + (3 * cellSize), originY + (3 * cellSize), 4, 4, cellSize, cellSize);
	tile23.Setup(originX + (4 * cellSize), originY + (3 * cellSize), 5, 4, cellSize, cellSize);
	tile24.Setup(originX + (5 * cellSize), originY + (3 * cellSize), 6, 4, cellSize, cellSize);

	tile25.Setup(originX + (0 * cellSize), originY + (4 * cellSize), 1, 5, cellSize, cellSize);
	tile26.Setup(originX + (1 * cellSize), originY + (4 * cellSize), 2, 5, cellSize, cellSize);
	tile27.Setup(originX + (2 * cellSize), originY + (4 * cellSize), 3, 5, cellSize, cellSize);
	tile28.Setup(originX + (3 * cellSize), originY + (4 * cellSize), 4, 5, cellSize, cellSize);
	tile29.Setup(originX + (4 * cellSize), originY + (4 * cellSize), 5, 5, cellSize, cellSize);
	tile30.Setup(originX + (5 * cellSize), originY + (4 * cellSize), 6, 5, cellSize, cellSize);

	tile31.Setup(originX + (0 * cellSize), originY + (5 * cellSize), 1, 6, cellSize, cellSize);
	tile32.Setup(originX + (1 * cellSize), originY + (5 * cellSize), 2, 6, cellSize, cellSize);
	tile33.Setup(originX + (2 * cellSize), originY + (5 * cellSize), 3, 6, cellSize, cellSize);
	tile34.Setup(originX + (3 * cellSize), originY + (5 * cellSize), 4, 6, cellSize, cellSize);
	tile35.Setup(originX + (4 * cellSize), originY + (5 * cellSize), 5, 6, cellSize, cellSize);
	tile36.Setup(originX + (5 * cellSize), originY + (5 * cellSize), 6, 6, cellSize, cellSize);

	tileList.push_back(&tile1);
	tileList.push_back(&tile2);
	tileList.push_back(&tile3);
	tileList.push_back(&tile4);
	tileList.push_back(&tile5);
	tileList.push_back(&tile6);
	tileList.push_back(&tile7);
	tileList.push_back(&tile8);
	tileList.push_back(&tile9);
	tileList.push_back(&tile10);
	tileList.push_back(&tile11);
	tileList.push_back(&tile12);
	tileList.push_back(&tile13);
	tileList.push_back(&tile14);
	tileList.push_back(&tile15);
	tileList.push_back(&tile16);
	tileList.push_back(&tile17);
	tileList.push_back(&tile18);
	tileList.push_back(&tile19);
	tileList.push_back(&tile20);
	tileList.push_back(&tile31);
	tileList.push_back(&tile32);
	tileList.push_back(&tile33);
	tileList.push_back(&tile34);
	tileList.push_back(&tile35);
	tileList.push_back(&tile36);



	verticalGridline1;
	verticalGridline2;
	verticalGridline3;
	verticalGridline4;
	verticalGridline5;
	verticalGridline6;
	verticalGridline7;

	horizontalGridline1;
	horizontalGridline2;
	horizontalGridline3;
	horizontalGridline4;
	horizontalGridline5;
	horizontalGridline6;
	horizontalGridline7;


}

Sector::~Sector()
{

}

void Sector::CreateTiles()
{
	


}

void Sector::SetAllTilePosition()
{
	tile1.SetPosition();
	tile2.SetPosition();
	tile3.SetPosition();
	tile4.SetPosition();
	tile5.SetPosition();
	tile6.SetPosition();
	tile7.SetPosition();
	tile8.SetPosition();
	tile9.SetPosition();
	tile10.SetPosition();
	tile10.SetPosition();
	tile11.SetPosition();
	tile12.SetPosition();
	tile13.SetPosition();
	tile14.SetPosition();
	tile15.SetPosition();
	tile16.SetPosition();
	tile17.SetPosition();
	tile18.SetPosition();
	tile19.SetPosition();
	tile20.SetPosition();
	tile21.SetPosition();
	tile22.SetPosition();
	tile23.SetPosition();
	tile24.SetPosition();
	tile25.SetPosition();
	tile26.SetPosition();;
	tile27.SetPosition();
	tile28.SetPosition();
	tile29.SetPosition();
	tile30.SetPosition();
	tile31.SetPosition();
	tile32.SetPosition();
	tile33.SetPosition();
	tile34.SetPosition();
	tile35.SetPosition();
	tile36.SetPosition();
}


void Sector::DrawAllTiles()
{
	//std::cout << "x:  " << tile1.x << "  " "y: " << tile1.y << "color " << std::endl;
	//std::cout << "x:  " << tile2.x << "  " "y: " << tile2.y << "color " << std::endl;
	//std::cout << "x:  " << tile3.x << "  " "y: " << tile3.y << "color " << std::endl;

	tile1.DrawTile(windowPtr);
	tile2.DrawTile(windowPtr);
	tile3.DrawTile(windowPtr);
	tile4.DrawTile(windowPtr);
	tile5.DrawTile(windowPtr);
	tile6.DrawTile(windowPtr);
	tile7.DrawTile(windowPtr);
	tile8.DrawTile(windowPtr);
	tile9.DrawTile(windowPtr);
	tile10.DrawTile(windowPtr);
	tile10.DrawTile(windowPtr);
	tile11.DrawTile(windowPtr);
	tile12.DrawTile(windowPtr);
	tile13.DrawTile(windowPtr);
	tile14.DrawTile(windowPtr);
	tile15.DrawTile(windowPtr);
	tile16.DrawTile(windowPtr);
	tile17.DrawTile(windowPtr);
	tile18.DrawTile(windowPtr);
	tile19.DrawTile(windowPtr);
	tile20.DrawTile(windowPtr);
	tile21.DrawTile(windowPtr);
	tile22.DrawTile(windowPtr);
	tile23.DrawTile(windowPtr);
	tile24.DrawTile(windowPtr);
	tile25.DrawTile(windowPtr);
	tile26.DrawTile(windowPtr);
	tile27.DrawTile(windowPtr);
	tile28.DrawTile(windowPtr);
	tile29.DrawTile(windowPtr);
	tile30.DrawTile(windowPtr);
	tile31.DrawTile(windowPtr);
	tile32.DrawTile(windowPtr);
	tile33.DrawTile(windowPtr);
	tile34.DrawTile(windowPtr);
	tile35.DrawTile(windowPtr);
	tile36.DrawTile(windowPtr);

}

void Sector::SetupGridlines()
{
	verticalGridline1.setPosition(originX, originY);
	verticalGridline1.setSize(sf::Vector2f(1, cellSize * 6));
	verticalGridline1.setFillColor(sf::Color(255, 255, 255));

	verticalGridline2.setPosition(originX + cellSize, originY);
	verticalGridline2.setSize(sf::Vector2f(1, cellSize * 6));
	verticalGridline2.setFillColor(sf::Color(255, 255, 255));

	verticalGridline3.setPosition(originX + cellSize*2, originY);
	verticalGridline3.setSize(sf::Vector2f(1, cellSize * 6));
	verticalGridline3.setFillColor(sf::Color(255, 255, 255));

	verticalGridline4.setPosition(originX + cellSize * 3, originY);
	verticalGridline4.setSize(sf::Vector2f(1, cellSize * 6));
	verticalGridline4.setFillColor(sf::Color(255, 255, 255));

	verticalGridline5.setPosition(originX + cellSize * 4, originY);
	verticalGridline5.setSize(sf::Vector2f(1, cellSize * 6));
	verticalGridline5.setFillColor(sf::Color(255, 255, 255));

	verticalGridline6.setPosition(originX + cellSize * 5, originY);
	verticalGridline6.setSize(sf::Vector2f(1, cellSize * 6));
	verticalGridline6.setFillColor(sf::Color(255, 255, 255));

	verticalGridline7.setPosition(originX + cellSize * 6, originY);
	verticalGridline7.setSize(sf::Vector2f(1, cellSize * 6));
	verticalGridline7.setFillColor(sf::Color(255, 255, 255));


	horizontalGridline1.setPosition(originX, originY);
	horizontalGridline1.setSize(sf::Vector2f(1, cellSize * 6));
	horizontalGridline1.rotate(-90);
	horizontalGridline1.setFillColor(sf::Color(255, 255, 255));

	horizontalGridline2.setPosition(originX, originY + cellSize);
	horizontalGridline2.setSize(sf::Vector2f(1, cellSize * 6));
	horizontalGridline2.rotate(-90);
	horizontalGridline2.setFillColor(sf::Color(255, 255, 255));

	horizontalGridline3.setPosition(originX, originY + cellSize * 2);
	horizontalGridline3.setSize(sf::Vector2f(1, cellSize * 6));
	horizontalGridline3.rotate(-90);
	horizontalGridline3.setFillColor(sf::Color(255, 255, 255));

	horizontalGridline4.setPosition(originX, originY + cellSize * 3);
	horizontalGridline4.setSize(sf::Vector2f(1, cellSize * 6));
	horizontalGridline4.rotate(-90);
	horizontalGridline4.setFillColor(sf::Color(255, 255, 255));

	horizontalGridline5.setPosition(originX, originY + cellSize * 4);
	horizontalGridline5.setSize(sf::Vector2f(1, cellSize * 6));
	horizontalGridline5.rotate(-90);
	horizontalGridline5.setFillColor(sf::Color(255, 255, 255));

	horizontalGridline6.setPosition(originX, originY + cellSize * 5);
	horizontalGridline6.setSize(sf::Vector2f(1, cellSize * 6));
	horizontalGridline6.rotate(-90);
	horizontalGridline6.setFillColor(sf::Color(255, 255, 255));

	horizontalGridline7.setPosition(originX, originY + cellSize * 6);
	horizontalGridline7.setSize(sf::Vector2f(1, cellSize * 6));
	horizontalGridline7.rotate(-90);
	horizontalGridline7.setFillColor(sf::Color(255, 255, 255));

	std::cout << verticalGridline1.getPosition().x << " " << verticalGridline2.getPosition().x << " " << verticalGridline3.getPosition().x << " " << verticalGridline4.getPosition().x << " " << verticalGridline5.getPosition().x << " " << verticalGridline6.getPosition().x << std::endl;


}


void Sector::DrawGridlines()
{
	windowPtr->draw(verticalGridline1);
	windowPtr->draw(verticalGridline2);
	windowPtr->draw(verticalGridline3);
	windowPtr->draw(verticalGridline4);
	windowPtr->draw(verticalGridline5);
	windowPtr->draw(verticalGridline6);
	windowPtr->draw(verticalGridline7);

	windowPtr->draw(horizontalGridline1);
	windowPtr->draw(horizontalGridline2);
	windowPtr->draw(horizontalGridline3);
	windowPtr->draw(horizontalGridline4);
	windowPtr->draw(horizontalGridline5);
	windowPtr->draw(horizontalGridline6);
	windowPtr->draw(horizontalGridline7);
	

	//std::cout << verticalGridline1.getOrigin().x << " " << verticalGridline2.getOrigin().x << " " << verticalGridline3.getOrigin().x << " " << verticalGridline4.getOrigin().x << " " << verticalGridline5.getOrigin().x << " " << verticalGridline6.getOrigin().x << std::endl;
}


void Sector::CalculateNewOrigin(sf::Vector2i mousePosition)
{
	std::cout << originX << "   " << originY << std::endl;

	//std::cout << "old origin: " << originX << " " << originY << std::endl;
	int clickedOffsetX(mousePosition.x - originX);
	int clickedOffsetY(mousePosition.y - originY);
	

	std::cout << "originX:  " << originX << "  mousePosX:  " << mousePosition.x << "  Offsetx:  " << clickedOffsetX << "  originY:  " << originY << "  mousePosY : " << mousePosition.y << "  offsetY: " << clickedOffsetY << std::endl;

	originX = mousePosition.x + clickedOffsetX;
	originY = mousePosition.y + clickedOffsetY;

	//originX = mousePosition.x;
	//originY = mousePosition.y;
	
	//std::cout << "old origin: " << clickedOffsetX << " " << clickedOffsetY << std::endl;
	//std::cout << "new origin: " << originX << "  " << originY << std::endl;
	//SetupGridlines();

}

void Sector::UpdatePosition()
{
	tile1.x = originX + (0 * cellSize);
	tile1.y = originY + (0 * cellSize);
	tile1.rectangle.setPosition(tile1.x, tile1.y);

	tile2.x = originX + (1 * cellSize);
	tile2.y = originY + (0 * cellSize);
	tile2.rectangle.setPosition(tile2.x, tile2.y);

	tile3.x = originX + (2 * cellSize); 
	tile3.y = originY + (0 * cellSize);
	tile3.rectangle.setPosition(tile3.x, tile3.y);

	tile4.x = originX + (3 * cellSize);
	tile4.y = originY + (0 * cellSize);
	tile4.rectangle.setPosition(tile4.x, tile4.y);

	tile5.x = originX + (4 * cellSize);
	tile5.y = originY + (0 * cellSize);
	tile5.rectangle.setPosition(tile5.x, tile5.y);

	tile6.x = originX + (5 * cellSize);
	tile6.y = originY + (0 * cellSize);
	tile6.rectangle.setPosition(tile6.x, tile6.y);

	tile7.x = originX + (0 * cellSize);
	tile7.y = originY + (1 * cellSize);
	tile7.rectangle.setPosition(tile7.x, tile7.y);

	tile8.x = originX + (1 * cellSize);
	tile8.y = originY + (1 * cellSize);
	tile8.rectangle.setPosition(tile8.x, tile8.y);

	tile9.x = originX + (2 * cellSize);
	tile9.y = originY + (1 * cellSize);
	tile9.rectangle.setPosition(tile9.x, tile9.y);

	tile10.x = originX + (3 * cellSize);
	tile10.y = originY + (1 * cellSize);
	tile10.rectangle.setPosition(tile10.x, tile10.y);

	tile11.x = originX + (4 * cellSize);
	tile11.y = originY + (1 * cellSize);
	tile11.rectangle.setPosition(tile11.x, tile11.y);

	tile12.x = originX + (5 * cellSize);
	tile12.y = originY + (1 * cellSize);
	tile12.rectangle.setPosition(tile12.x, tile12.y);

	tile13.x = originX + (0 * cellSize);
	tile13.y = originY + (2 * cellSize);
	tile13.rectangle.setPosition(tile13.x, tile13.y);

	tile14.x = originX + (1 * cellSize);
	tile14.y = originY + (2 * cellSize);
	tile14.rectangle.setPosition(tile14.x, tile14.y);

	tile15.x = originX + (2 * cellSize);
	tile15.y = originY + (2 * cellSize);
	tile15.rectangle.setPosition(tile15.x, tile15.y);

	tile16.x = originX + (3 * cellSize);
	tile16.y = originY + (2 * cellSize);
	tile16.rectangle.setPosition(tile16.x, tile16.y);

	tile17.x = originX + (4 * cellSize);
	tile17.y = originY + (2 * cellSize);
	tile17.rectangle.setPosition(tile17.x, tile17.y);

	tile18.x = originX + (5 * cellSize);
	tile18.y = originY + (2 * cellSize);
	tile18.rectangle.setPosition(tile18.x, tile18.y);

	tile19.x = originX + (0 * cellSize);
	tile19.y = originY + (3 * cellSize);
	tile19.rectangle.setPosition(tile19.x, tile19.y);

	tile20.x = originX + (1 * cellSize);
	tile20.y = originY + (3 * cellSize);
	tile20.rectangle.setPosition(tile20.x, tile20.y);

	tile21.x = originX + (2 * cellSize);
	tile21.y = originY + (3 * cellSize);
	tile21.rectangle.setPosition(tile21.x, tile21.y);

	tile22.x = originX + (3 * cellSize);
	tile22.y = originY + (3 * cellSize);
	tile22.rectangle.setPosition(tile22.x, tile22.y);

	tile23.x = originX + (4 * cellSize);
	tile23.y = originY + (3 * cellSize);
	tile23.rectangle.setPosition(tile23.x, tile23.y);

	tile24.x = originX + (5 * cellSize);
	tile24.y = originY + (3 * cellSize);
	tile24.rectangle.setPosition(tile24.x, tile24.y);

	tile25.x = originX + (0 * cellSize);
	tile25.y = originY + (4 * cellSize);
	tile25.rectangle.setPosition(tile25.x, tile25.y);

	tile26.x = originX + (1 * cellSize);
	tile26.y = originY + (4 * cellSize);
	tile26.rectangle.setPosition(tile26.x, tile26.y);

	tile27.x = originX + (2 * cellSize);
	tile27.y = originY + (4 * cellSize);
	tile27.rectangle.setPosition(tile27.x, tile27.y);

	tile28.x = originX + (3 * cellSize);
	tile28.y = originY + (4 * cellSize);
	tile28.rectangle.setPosition(tile28.x, tile28.y);

	tile29.x = originX + (4 * cellSize);
	tile29.y = originY + (4 * cellSize);
	tile29.rectangle.setPosition(tile29.x, tile29.y);

	tile30.x = originX + (5 * cellSize);
	tile30.y = originY + (4 * cellSize);
	tile30.rectangle.setPosition(tile30.x, tile30.y);

	tile31.x = originX + (0 * cellSize);
	tile31.y = originY + (5 * cellSize);
	tile31.rectangle.setPosition(tile31.x, tile31.y);

	tile32.x = originX + (1 * cellSize);
	tile32.y = originY + (5 * cellSize);
	tile32.rectangle.setPosition(tile32.x, tile32.y);

	tile33.x = originX + (2 * cellSize);
	tile33.y = originY + (5 * cellSize);
	tile33.rectangle.setPosition(tile33.x, tile33.y);

	tile34.x = originX + (3 * cellSize);
	tile34.y = originY + (5 * cellSize);
	tile34.rectangle.setPosition(tile34.x, tile34.y);

	tile35.x = originX + (4 * cellSize);
	tile35.y = originY + (5 * cellSize);
	tile35.rectangle.setPosition(tile35.x, tile35.y);

	tile36.x = originX + (5 * cellSize);
	tile36.y = originY + (5 * cellSize);
	tile36.rectangle.setPosition(tile36.x, tile36.y);


}


