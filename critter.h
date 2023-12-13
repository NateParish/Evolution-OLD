#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "cell.h"
#include "geneticcalculator.h"

class Critter
{

public:

	std::string firstName;
	std::string lastName;
	sf::RectangleShape bodyRectangle;
	sf::RectangleShape bodyRectangle2;
	int x;
	int y;
	int width;
	int height;
	bool isAlive;
	bool clicked;
	int clickedOffsetX;
	int clickedOffsetY;
	int fpsCounter;
	//sf::Sprite eye1;
	//sf::Sprite eye2;
	sf::Texture eyeTexture;
	Cell cell1;
	Cell cell2;
	std::vector<Cell*> listOfCells;

	float hydration;
	float reproduceCounterStart;
	float reproduceCounter;
	bool reproduceFlag;

	Critter();
	~Critter();
	Critter(int positionX, int positionY);


	void generateBody();
	void DrawCritter(sf::RenderWindow* window);
	bool CritterClicked(sf::Vector2i mousePosition);
	void CritterUnClicked();
	void MoveCritterWithMouse(sf::Vector2i mousePosition);
	void UpdateCritter(int FPS);
	void Kill();
	void RotateCritter();
	void GrimReaper();
	void RandomReproductionRate();


};

