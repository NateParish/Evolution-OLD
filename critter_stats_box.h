#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "critter.h"


class CritterStatsBox
{

public:

	int x;
	int y;
	int height;
	int width;
	sf::Vector2f size;
	sf::Color bgColor;
	sf::RectangleShape rectangle;
	sf::Font font1;
	sf::Text nameText;
	sf::Text hydrationText;
	sf::Text counterText;
	sf::Text repCounterText;

	CritterStatsBox();
	~CritterStatsBox();

	void DrawBox(sf::RenderWindow* window,Critter* critterToDisplayPtr);
	void SetupFonts();


};

