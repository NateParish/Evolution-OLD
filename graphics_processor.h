#pragma once
#include "SFML/Graphics.hpp"
#include "sector.h"
#include "critter.h"


class GraphicsProcessor
{

public:

	int zoom;
	int xOffset;
	int yOffset;
	sf::RenderWindow* window;
	bool groundClicked;
	bool setPositionFlag;

	GraphicsProcessor(sf::RenderWindow* inputWindow);
	~GraphicsProcessor();

	bool GroundClicked(sf::Vector2i mousePosition, std::vector<Critter*> critterList, std::vector<Sector*> sectorList);
	bool GroundUnClicked();
	void MoveScreen(sf::Vector2i mousePosition, std::vector<Critter*> critterList, std::vector<Sector*> sectorList);
	void UpdateItemPositions(Sector* targetSector);
	void RenderGraphics();


};



