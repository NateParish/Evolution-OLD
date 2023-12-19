#pragma once
#include <iostream>
#include "tile.h"



class Sector
{

public:

	sf::RenderWindow* windowPtr;
	int originX;
	int originY;
	int cellSize;


	Tile tile1;
	Tile tile2;
	Tile tile3;
	Tile tile4;
	Tile tile5;
	Tile tile6;
	Tile tile7;
	Tile tile8;
	Tile tile9;
	Tile tile10;
	Tile tile11;
	Tile tile12;
	Tile tile13;
	Tile tile14;
	Tile tile15;
	Tile tile16;
	Tile tile17;
	Tile tile18;
	Tile tile19;
	Tile tile20;
	Tile tile21;
	Tile tile22;
	Tile tile23;
	Tile tile24;
	Tile tile25;
	Tile tile26;
	Tile tile27;
	Tile tile28;
	Tile tile29;
	Tile tile30;
	Tile tile31;
	Tile tile32;
	Tile tile33;
	Tile tile34;
	Tile tile35;
	Tile tile36;

	std::vector<Tile*> tileList;

	sf::RectangleShape verticalGridline1;
	sf::RectangleShape verticalGridline2;
	sf::RectangleShape verticalGridline3;
	sf::RectangleShape verticalGridline4;
	sf::RectangleShape verticalGridline5;
	sf::RectangleShape verticalGridline6;
	sf::RectangleShape verticalGridline7;

	sf::RectangleShape horizontalGridline1;
	sf::RectangleShape horizontalGridline2;
	sf::RectangleShape horizontalGridline3;
	sf::RectangleShape horizontalGridline4;
	sf::RectangleShape horizontalGridline5;
	sf::RectangleShape horizontalGridline6;
	sf::RectangleShape horizontalGridline7;

	Sector(sf::RenderWindow* window);
	~Sector();


	void CreateTiles();
	void SetAllTilePosition();
	void DrawAllTiles();
	void SetupGridlines();
	void DrawGridlines();
	void CalculateNewOrigin(sf::Vector2i mousePosition);
	void UpdatePosition();



};

