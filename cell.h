#pragma once


#include "SFML/Graphics.hpp"
#include "DNA.h"
#pragma once



class Cell
{

public:
	
	
	Cell();
	Cell(float x, float y, float originalWidth, float originalHeight);
	~Cell();

	float x;
	float y;
	float width;
	float height;
	int originOffsetX;
	int originOffsetY;
	sf::CircleShape circle;
	sf::Color color;
	sf::RectangleShape rectangle;
	DNA geneticCode;

	void DrawCell(sf::RenderWindow* window);
	void MoveCell(float dx, float dy);
	void GenerateDNA(std::string DNAsequence);
	std::string GetColorRGB(std::string desiredColor);
	void SetColorRGB(int red, int green, int blue);
	void SetRectangleDimensions(int newWidth, int newHeight);

private:


};