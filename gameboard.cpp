#include "gameboard.h"


Gameboard::Gameboard()
{

	cellSize = 25;
	gameBoardX = 10;
	gameBoardY = 150;
	gameBoardWidth = 1780;
	gameBoardHeight = 750;
	columnCount = std::floor(gameBoardWidth / cellSize);
	rowCount = std::floor(gameBoardHeight / cellSize);
	groundList;
	waterView = true;

}

Gameboard::~Gameboard()
{
	for (const auto& ground : groundList) {
		delete ground; 
	}

}


void Gameboard::DrawGrid(sf::RenderWindow* window)
{
	//std::vector<sf::RectangleShape> gridlines;
	//int n = 25;
	

	//gridlines.push_back(line);
	for (int i = 0; i <= columnCount; ++i)
	{
		sf::RectangleShape verticalLine(sf::Vector2f(1, rowCount*cellSize));
		verticalLine.setPosition(gameBoardX + (cellSize*i), gameBoardY);
		verticalLine.setFillColor(sf::Color(60, 60, 60));
		window->draw(verticalLine);

	}

	for (int i = 0; i <= rowCount; ++i)
	{
		sf::RectangleShape horizontalLine(sf::Vector2f(1, columnCount*cellSize));
		horizontalLine.setPosition(gameBoardX, gameBoardY + (cellSize * i));
		horizontalLine.rotate(-90);
		horizontalLine.setFillColor(sf::Color(60, 60, 60));
		window->draw(horizontalLine);
	}


}

void Gameboard::CreateGround(int inputRowCount, int inputColumnCount, int cellWidth)
{
	
	std::cout << "groundCreated" << std::endl;
	//int colAdj = columnCount - 1;
	int m(100);

	for (int k = 0; k < rowCount; ++k)
	{

		for (int i = 0; i < columnCount; ++i)
		{
			if (m < 1)
			{
				m = 100;
			}

			Ground* ground = new Ground(); 
			ground->row = k + 1;
			ground->column = i + 1;
			ground->moisture = m;
			ground->x = gameBoardX + cellWidth * i;
			ground->y = gameBoardY + cellWidth * k;
			ground->rectangle.setPosition(ground->x, ground->y);
			groundList.push_back(ground); 
			m--;
		}

	}

}

void Gameboard::GroundListPrintout()
{
	for (int i = 0; i < groundList.size(); ++i)
	{
		std::cout << groundList[i]->x << std::endl;
	}
}

void Gameboard::DrawGround(sf::RenderWindow* window)
{


	for (int i = 0; i < groundList.size(); ++i)
	{

		groundList[i]->setGroundColor();
		groundList[i]->DrawGround(window);

	}


}

void Gameboard::GroundHovered(sf::Vector2i mousePosition)
{
	bool switchOff(false);
	bool groundHighlightLastFrame;

	for (Ground* ground : groundList)

	{
		groundHighlightLastFrame = ground->hovered;

		ground->hovered = false;



		int xPos = ground->rectangle.getPosition().x;
		int yPos = ground->rectangle.getPosition().y;

		if (mousePosition.x >= xPos)
		{
			if (mousePosition.x <= (xPos + cellSize))
			{
				if (mousePosition.y >= yPos)
				{
					if (mousePosition.y <= (yPos + cellSize))
					{
						ground->hovered = true;
						
					}
				}
			}
		}

		if (ground->hovered == true)
		{
			if (groundHighlightLastFrame == false)
			{
				ground->rectangle.setFillColor(sf::Color(60, 60, 60));
			}
		}
		else
		{
			if (groundHighlightLastFrame == true)
			{
				ground->rectangle.setFillColor(sf::Color(40, 40, 40));
			}
		}
	}
}


void Gameboard::setGroundColors()
{
	float red();


}


