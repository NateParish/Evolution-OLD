#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "vars.cpp"
#include "tile.h"


class Gameboard
{


public:

	float cellSize;
	float gameBoardX;
	float gameBoardY;
	float gameBoardHeight;
	float gameBoardWidth;
	float columnCount;
	float rowCount;
	std::vector<Tile*> tileList;
	bool waterView;


	Gameboard();
	~Gameboard();

	void DrawGrid(sf::RenderWindow* window);
	void CreateTile(int rowCount, int columnCount, int cellWidth);
	void TileListPrintout();
	void DrawTile(sf::RenderWindow* window);
	void TileHovered(sf::Vector2i mousePosition);
	void setTileColors();




};

