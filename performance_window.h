#pragma once
#include "SFML/Graphics.hpp"


class PerformanceWindow
{

public:


	sf::RenderWindow* window;
	sf::Font font1;
	sf::Text FPSText;
	sf::Text critterCountText;



	PerformanceWindow(sf::RenderWindow* windowPtr);
	~PerformanceWindow();

	void PollEvents();
	void SetupFPSDisplay();
	void DisplayFPSData(float duration);
	void DisplayCritterCount(int critterCount);
	void UpdateAll(float duration, int critterCount);


};

