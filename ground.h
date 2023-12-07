#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Ground
{

	public:

		int x;
		int y;
		int row;
		int column;
		int width;
		int height;
		float moisture;
		bool clicked;
		bool hovered;
		sf::RectangleShape rectangle;

		Ground();
		Ground(int inputX, int inputY, int inputRow, int inputColumn, int inputWidth, int inputHeight);
		~Ground();
		void DrawGround(sf::RenderWindow* window);
		void Setup(int xInput, int yInput, int columnInput, int rowInput, int widthInput, int heightInput);
		void SetPosition();
		void setGroundColor();





};

