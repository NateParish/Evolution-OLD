#include "critter_stats_box.h"
#include <iomanip>



CritterStatsBox::CritterStatsBox()
{
	x = 0;
	y = 0;
	height = 125;
	width = 500;
	bgColor = sf::Color(30, 30, 30);
	size.x = width;
	size.y = height;
	rectangle.setFillColor(bgColor);
	rectangle.setPosition(x, y);
	rectangle.setSize(size);
	
	font1.loadFromFile("C:/Windows/Fonts/arial.ttf");

	nameText;
	hydrationText;
	counterText;

}


CritterStatsBox::~CritterStatsBox()
{

}

void CritterStatsBox::DrawBox(sf::RenderWindow* window, Critter* critterToDisplayPtr)
{

	nameText.setString("Critter Name:     " + critterToDisplayPtr->name);

	std::string formattedHydration = "Hydration:         " + std::to_string(critterToDisplayPtr->hydration);
	formattedHydration = formattedHydration.substr(0, formattedHydration.find('.') + 3);



	hydrationText.setString(formattedHydration);
	counterText.setString("FPS Counter:     " + std::to_string(critterToDisplayPtr->fpsCounter));




	window->draw(rectangle);
	window->draw(nameText);
	window->draw(hydrationText);
	window->draw(counterText);

}

void CritterStatsBox::SetupFonts()
{


	nameText.setFont(font1);
	nameText.setCharacterSize(14);
	nameText.setFillColor(sf::Color::White);
	nameText.setPosition(x + 10, y + 10);

	hydrationText.setFont(font1);
	hydrationText.setCharacterSize(14);
	hydrationText.setFillColor(sf::Color::White);
	hydrationText.setPosition(x + 10, y + 28);

	counterText.setFont(font1);
	counterText.setCharacterSize(14);
	counterText.setFillColor(sf::Color::White);
	counterText.setPosition(x + 10, y + 46);

}



