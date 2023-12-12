#include "gameboard.h"


Gameboard::Gameboard(sf::RenderWindow* windowPtr)
{

	cellInitialSize = 25;
	zoom = 1;
	cellSize = cellInitialSize * zoom;
	gameBoardX = 10;
	gameBoardY = 150;
	//sectorColumnCount = 13;
	//sectorRowCount = 7;
	sectorColumnCount = 2;
	sectorRowCount = 2;
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
			sector->row = k + 1;
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
	std::cout << "MOUSE SIGNAL" << mouseSignal << std::endl;

	int i = 0;
	int k = 0;

	Sector* firstSector = sectorList.at(0);

	int startX = firstSector->originX;
	int startY = firstSector->originY;
	



	if (mouseSignal > 0)
	{
		std::cout << "UP DAWG" << std::endl;
		zoom++;
		cellSize = cellSize * zoom;
		//std::cout << cellSize << std::endl;

		Sector* firstSector = sectorList.at(0);

		int startX = firstSector->originX;
		int startY = firstSector->originY;
		std::cout << startX << " " << startY << std::endl;

		for (Sector* sector : sectorList)
		{
			sector->cellSize = cellSize;
			//std::cout << sector->originX << std::endl;
			int sectorStartX = startX + (sector->column - 1) * 6 * cellSize;
			std::cout << sector->column << std::endl;
			int sectorStartY = startY + (sector->row - 1) * 6 * cellSize;
			std::cout << "sectorStartY: " << sectorStartY << " startY " << startY << " curRow " << sector->row << std::endl;
			//std::cout << sector->originX << std::endl;
			std::cout << "StartY " << sectorStartY << std::endl;
			//std::cout << sector->row << std::endl;


			sector->UpdateOrigin(sectorStartX, sectorStartY);
			sector->UpdatePosition();
		}


	}
	else
	{
		//std::cout << "Down DAWG" << std::endl;
		if (zoom > 1)
		{
			zoom--;
		}

		Sector* firstSector = sectorList.at(0);

		int startX = firstSector->originX;

		for (Sector* sector : sectorList)
		{
			sector->cellSize = cellSize;
			std::cout << sector->originX << std::endl;

			sector->UpdateOrigin(startX + (sector->column - 1) * 6 * cellSize, sector->originY);
			sector->UpdatePosition();
		}

	}

	cellSize = cellInitialSize * zoom;

	//for (Sector* sector : sectorList)
	//{
	//	sector->cellSize = cellSize;
	//	//sector->UpdateOrigin(sector->originX + (sector->column-1)*sector->cellSize*6, sector->originY);
	//	sector->UpdatePosition();
	//	//sector->UpdateGridlinePosition();
	//}

	//std::cout << "ZOOM: " << zoom << std::endl;
}

