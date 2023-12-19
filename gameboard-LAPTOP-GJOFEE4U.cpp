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
	tileList;
	waterView = true;

}

Gameboard::~Gameboard()
{
	for (const auto& Tile : tileList) {
		delete Tile;
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

void Gameboard::CreateTile(int inputRowCount, int inputColumnCount, int cellWidth)
{
	
	//std::cout << "groundCreated" << std::endl;
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

			Tile* tile = new Tile();
			tile->row = k + 1;
			tile->column = i + 1;
			tile->moisture = m;
			tile->x = gameBoardX + cellWidth * i;
			tile->y = gameBoardY + cellWidth * k;
			tile->rectangle.setPosition(tile->x, tile->y);
			tileList.push_back(tile);
			m--;
		}

	}

}

void Gameboard::TileListPrintout()
{
	for (int i = 0; i < tileList.size(); ++i)
	{
		std::cout << tileList[i]->x << std::endl;
	}
}

void Gameboard::DrawTile(sf::RenderWindow* window)
{


	for (int i = 0; i < tileList.size(); ++i)
	{

		tileList[i]->setTileColor();
		tileList[i]->DrawTile(window);

	}


}

void Gameboard::TileHovered(sf::Vector2i mousePosition)
{
	bool switchOff(false);
	bool tileHighlightLastFrame;

	for (Tile* tile : tileList)

	{
		tileHighlightLastFrame = tile->hovered;

		tile->hovered = false;



		int xPos = tile->rectangle.getPosition().x;
		int yPos = tile->rectangle.getPosition().y;

		if (mousePosition.x >= xPos)
		{
			if (mousePosition.x <= (xPos + cellSize))
			{
				if (mousePosition.y >= yPos)
				{
					if (mousePosition.y <= (yPos + cellSize))
					{
						tile->hovered = true;
						
					}
				}
			}
		}

		if (tile->hovered == true)
		{
			if (tileHighlightLastFrame == false)
			{
				tile->rectangle.setFillColor(sf::Color(60, 60, 60));
			}
		}
		else
		{
			if (tileHighlightLastFrame == true)
			{
				tile->rectangle.setFillColor(sf::Color(40, 40, 40));
			}
		}
	}
}


void Gameboard::setTileColors()
{
	float red();


}


