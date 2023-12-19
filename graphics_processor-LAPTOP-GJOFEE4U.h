#pragma once
#include "SFML/Graphics.hpp"
#include "sector.h"


class GraphicsProcessor
{

public:

	int zoom;
	int xOffset;
	int yOffset;
	sf::RenderWindow* window;

	GraphicsProcessor(sf::RenderWindow* inputWindow);
	~GraphicsProcessor();

	void UpdateItemPositions(Sector* targetSector);
	void RenderGraphics();


};



