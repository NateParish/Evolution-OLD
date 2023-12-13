#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "tile.h"
#include "sector.h"


class Gameboard
{


public:

	float cellInitialSize;
	float zoom;
	float cellSize;
	float gameBoardX;
	float gameBoardY;
	float sectorColumnCount;
	float sectorRowCount;
	sf::RenderWindow* window;
	std::vector<Sector*> sectorList;


	Gameboard(sf::RenderWindow* windowPtr);
	~Gameboard();
	void SpawnSectors();
	void RepositionSectors();
	void Zoom(int mouseSignal);

};

