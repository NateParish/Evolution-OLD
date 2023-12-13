#include "gameboard.h"


Gameboard::Gameboard(sf::RenderWindow* windowPtr)
{

	cellInitialSize = 25;
	zoom = 1;
	cellSize = cellInitialSize * zoom;
	gameBoardX = 10;
	gameBoardY = 150;
	sectorColumnCount = 20;
	sectorRowCount = 20;
	//sectorColumnCount = 2;
	//sectorRowCount = 2;
	window = windowPtr;
	sectorList;
	

}

Gameboard::~Gameboard()
{
	for (Sector* sector : sectorList) {
		delete sector;
	}

}


void Gameboard::SpawnSectors()
{

	for (int i = 0; i < sectorRowCount; i++)
	{



		for (int k = 0; k < sectorColumnCount; k++)
		{
			Sector* sector = new Sector(window);
			sector->originX = sector->originX + (6 * sector->cellSize * k);
			sector->originY = sector->originY + (6 * sector->cellSize * i);
			sector->column = k + 1;
			sector->row = i + 1;
			sector->SetAllTilePosition();
			sector->UpdatePosition();
			sector->SetupGridlines();
			sectorList.push_back(sector);


		}

	}

	
}

void Gameboard::RepositionSectors()
{
	Sector* firstSectorPointer(sectorList.at(0));

	gameBoardX = firstSectorPointer->originX;
	gameBoardY = firstSectorPointer->originY;


	for (Sector* sector : sectorList)
	{
		sector->originX = gameBoardX + (sector->column - 1);
		sector->originY = gameBoardY + (sector->row - 1);
	}

}

void Gameboard::Zoom(int mouseSignal)
{
	//std::cout << "MOUSE SIGNAL" << mouseSignal << std::endl;

	int i = 0;
	int k = 0;

	Sector* firstSector = sectorList.at(0);

	int startX = firstSector->originX;
	int startY = firstSector->originY;
	
	if (mouseSignal > 0)
	{
		zoom++;
	}
	if (mouseSignal < 0)
	{

		if (zoom > 1)

		{
			zoom--;
		}

	}

	
	cellSize = cellInitialSize * zoom;

	for (Sector* sector : sectorList)
	{
		sector->cellSize = cellSize;
		int sectorStartX = startX + (sector->column - 1) * 6 * cellSize;
		int sectorStartY = startY + (sector->row - 1) * 6 * cellSize;

		sector->UpdateOrigin(sectorStartX, sectorStartY);
		sector->UpdatePosition();
	}

}

