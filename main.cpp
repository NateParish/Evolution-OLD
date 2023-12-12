#include <iostream>
#include <string>
#include <vector>
#include "SFML/Graphics.hpp"
#include "cell.h"
#include "critter.h"
#include "critter_stats_box.h"
#include "sun.h"
#include "tile.h"
#include "gameboard.h"
#include "sector.h"
#include "graphics_processor.h"
//#include "DNA.h"


int main()
{
	int FPS(60);
	int xPad(10);
	int yPad(10);
	int menuHeight(125);

	int cellWidth(25);


	sf::RenderWindow window(sf::VideoMode(1000, 500, 32), "SFML Graphics");
	sf::RenderWindow* windowPtr(&window);
	sf::Event e;
	window.setFramerateLimit(FPS);
	bool isCritterClickedFlag(false);
	bool moveTerrainFlag(false);
	bool mouseClickedFlag(false);


	sf::Font font;
	if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
		std::cout << "couldn't Load Font" << std::endl;
		return 1;
	}

	sf::Vector2u windowSize = window.getSize();


	GeneticCalculator geneCalc5000;


	Sun sun;
	Gameboard gameboard(windowPtr);
	

	std::vector<Sector*> sectorList;

	gameboard.SpawnSectors();
	sectorList = gameboard.sectorList;


	GraphicsProcessor graphicsProcessor9000(windowPtr);

	for (Sector* sector : sectorList)
	{
		sector->SetAllTilePosition();
		sector->UpdatePosition();
		sector->SetupGridlines();
	}


	Critter critter1(600,300);
	critter1.name = "Larry";
	critter1.generateBody();

	Critter critter2(800,300);
	critter2.name = "Sebastian";
	critter2.generateBody();

	critter2.cell1.rectangle.setFillColor(sf::Color(255, 30, 30));


	std::vector<Critter*> critterList;
	critterList.push_back(&critter1);
	critterList.push_back(&critter2);

	std::vector<Critter*> critterOldList;

	CritterStatsBox critterStats;
	critterStats.SetupFonts();

	Critter* critterToDisplayPtr(&critter1);

	//std::cout << "The critter to display is:  " << critterToDisplayPtr->name;


	sf::Text text;
	text.setFont(font);
	//text.setString(particle1.geneticCode.geneSequence);
	text.setCharacterSize(15);
	text.setFillColor(sf::Color::White);
	text.setPosition(windowSize.x - 100, 10);
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2i mouseAnchor(0, 0);
	bool mouseAnchorSet = false;
	
	while (window.isOpen())
	{


		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		critterOldList.clear();
		critterOldList = critterList;
		critterList.clear();




		for (Critter* critterPtr : critterOldList)
		{
			if (critterPtr->isAlive == true)
			{
				critterList.push_back(critterPtr);

			}

		}




		window.clear();

		//mouseClickedFlag = false;

		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
			if (e.type == sf::Event::Resized)
			{
				window.setView(sf::View(sf::FloatRect(0, 0, e.size.width, e.size.height)));
			}
			if (e.type == sf::Event::MouseButtonPressed)
			{
				mouseClickedFlag = true;
				//moveTerrainFlag = true;
				//mouseAnchor = sf::Mouse::getPosition(window);

				mousePosition = sf::Mouse::getPosition(window);

				for (Critter* critterPtr : critterList)
				{
					isCritterClickedFlag = false;

					isCritterClickedFlag = critterPtr->CritterClicked(mousePosition);

					if (isCritterClickedFlag == true)
					{
						critterToDisplayPtr = critterPtr;
						//moveTerrainFlag = false;
					}

				}

				graphicsProcessor9000.GroundClicked(mousePosition, critterList, sectorList);

				
			}
			if (e.type == sf::Event::MouseButtonReleased)
			{

				graphicsProcessor9000.GroundUnClicked();

				for (Critter* critterPtr : critterList)
				{
					critterPtr->CritterUnClicked();
					mouseClickedFlag = false;
				}

			}

			if (e.type == sf::Event::KeyPressed) {
				if (e.key.code == sf::Keyboard::Space) {
					//critter1.Kill();
					//critter1.RotateCritter();
					//graphicsProcessor9000.UpdateItemPositions(&sector1);
				}
			}

			if (e.type == sf::Event::MouseWheelMoved)
			{
				gameboard.Zoom(e.mouseWheel.delta);

			}

		}



		graphicsProcessor9000.MoveScreen(mousePosition, critterList, sectorList);

		for (Sector* sector : sectorList)
		{
			sector->DrawAllTiles();
			sector->UpdateGridlinePosition();
			sector->TileHovered(mousePosition);
			sector->tile1.rectangle.setFillColor(sf::Color(0, 255, 255));
			sector->tile6.rectangle.setFillColor(sf::Color(255, 0, 255));
			//sector->DrawGridlines();
		}


		for (Critter* critterPtr : critterList)
		{

			critterPtr->GrimReaper();
			critterPtr->MoveCritterWithMouse(mousePosition);
			critterPtr->UpdateCritter(FPS);
			critterPtr->DrawCritter(windowPtr);
		}

		critterStats.DrawBox(windowPtr, critterToDisplayPtr);
		window.display();

	}






}