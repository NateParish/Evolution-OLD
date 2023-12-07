#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "vars.cpp"
#include "ground.h"


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
	std::vector<Ground*> groundList;
	bool waterView;


	Gameboard();
	~Gameboard();

	void DrawGrid(sf::RenderWindow* window);
	void CreateGround(int rowCount, int columnCount, int cellWidth);
	void GroundListPrintout();
	void DrawGround(sf::RenderWindow* window);
	void GroundHovered(sf::Vector2i mousePosition);
	void setGroundColors();




};

