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
	sf::Text secondsPer60FramesText;
	sf::Text critterCountText;

	CritterStatsBox();
	~CritterStatsBox();

	void DrawBox(sf::RenderWindow* window,Critter* critterToDisplayPtr, float duration, int currentCritterCount);
	void SetupFonts();


};

