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
	repCounterText;
	secondsPer60FramesText;
	critterCountText;

}


CritterStatsBox::~CritterStatsBox()
{

}

void CritterStatsBox::DrawBox(sf::RenderWindow* window, Critter* critterToDisplayPtr, float duration, int currentCritterCount)
{

	nameText.setString("Critter Name:     " + critterToDisplayPtr->firstName + " " + critterToDisplayPtr->lastName);

	std::string formattedHydration = "Hydration:         " + std::to_string(critterToDisplayPtr->hydration);
	formattedHydration = formattedHydration.substr(0, formattedHydration.find('.') + 3);

	std::string formattedRepCounter = "Rep Counter:     " + std::to_string(critterToDisplayPtr->reproduceCounter);
	formattedRepCounter = formattedRepCounter.substr(0, formattedRepCounter.find('.') + 3);


	hydrationText.setString(formattedHydration);
	
	counterText.setString("FPS Counter:     " + std::to_string(critterToDisplayPtr->fpsCounter));


	formattedRepCounter = formattedRepCounter.substr(0, formattedRepCounter.find('.') + 3);

	//repCounterText.setString(formattedHydration);
	repCounterText.setString(formattedRepCounter); secondsPer60FramesText;

	std::string secondsPer60Frames = "FPS:                  " + std::to_string(60 / duration);

	std::string formattedSecondsPer60Frames = secondsPer60Frames.substr(0, secondsPer60Frames.find('.') + 3);
	secondsPer60FramesText.setString(formattedSecondsPer60Frames);



	//std::string critterCount = "Critter Count:                  " + std::to_string(currentCritterCount);


	/*std::string formattedSecondsPer60Frames = secondsPer60Frames.substr(0, secondsPer60Frames.find('.') + 3);
	secondsPer60FramesText.setString(formattedSecondsPer60Frames);*/

	std::string critterCount = "Critter Count:        " + std::to_string(currentCritterCount);
	critterCountText.setString(critterCount);


	window->draw(rectangle);
	window->draw(nameText);
	window->draw(hydrationText);
	window->draw(counterText);
	window->draw(repCounterText);
	window->draw(secondsPer60FramesText);
	window->draw(critterCountText);

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

	repCounterText.setFont(font1);
	repCounterText.setCharacterSize(14);
	repCounterText.setFillColor(sf::Color::White);
	repCounterText.setPosition(x + 10, y + 64);

	secondsPer60FramesText.setFont(font1);
	secondsPer60FramesText.setCharacterSize(14);
	secondsPer60FramesText.setFillColor(sf::Color::White);
	secondsPer60FramesText.setPosition(x + 10, y + 82);

	critterCountText.setFont(font1);
	critterCountText.setCharacterSize(14);
	critterCountText.setFillColor(sf::Color::White);
	critterCountText.setPosition(x + 10, y + 100);

}



