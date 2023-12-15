#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>
#include "SFML/Graphics.hpp"
#include "cell.h"
#include "critter.h"
#include "critter_stats_box.h"
#include "sun.h"
#include "tile.h"
#include "gameboard.h"
#include "sector.h"
#include "graphics_processor.h"
#include "critter_manager.h"
#include "performance_window.h"
//#include "DNA.h"


int main()
{
	int FPS(60);
	int xPad(10);
	int yPad(10);
	int menuHeight(125);

	int cellWidth(25);

	sf::RenderWindow performanceWindow(sf::VideoMode(1000, 500, 32), "Performance Window");
	sf::RenderWindow window(sf::VideoMode(1000, 500, 32), "SFML Graphics");
	sf::RenderWindow* performanceWindowPtr(&performanceWindow);
	sf::RenderWindow* windowPtr(&window);

	sf::Event e;
	window.setFramerateLimit(FPS);
	performanceWindow.setFramerateLimit(FPS);


	bool isCritterClickedFlag(false);
	bool moveTerrainFlag(false);
	bool mouseClickedFlag(false);

	PerformanceWindow performanceWindow3000(performanceWindowPtr);


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

	CritterManager critterManager2000;
	CritterManager* critterManagerPtr(&critterManager2000);
	critterManager2000.PopulateNameGenerator();
	//critterManager2000.GenerateName();






	critterManager2000.SpawnFirstCritter();









	std::vector<Critter*> critterList;

	std::vector<Critter*> critterOldList;

	CritterStatsBox critterStats;
	critterStats.SetupFonts();

	Critter* critterToDisplayPtr(critterManagerPtr->livingCritters->at(0));

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
	
	auto start_time = std::chrono::high_resolution_clock::now();
	auto end_time = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::duration<float>>(end_time - start_time);
	float durationExtracted = 1;
	
	//float durationToSend = duration;
	int fpsCounter(0);

	critterList = *critterManager2000.listOfAllCritters;

	while (window.isOpen())
	{
		//start_time = std::chrono::high_resolution_clock::now();

		//critterList = *critterManager2000.listOfAllCritters;
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		critterOldList.clear();
		critterOldList = critterList;
		critterList.clear();
		//critterList = *critterManager2000.listOfAllCritters;

		//std::cout << critterManager2000.listOfNewCritters;

		critterList = *critterManager2000.listOfNewCritters;
		critterManager2000.listOfNewCritters->clear();

		if (fpsCounter > 59)
		{
			end_time = std::chrono::high_resolution_clock::now();
			duration = std::chrono::duration_cast<std::chrono::duration<float>>(end_time - start_time);
			durationExtracted = duration.count();

			fpsCounter = 0;
			start_time = std::chrono::high_resolution_clock::now();
		}



		for (Critter* critterPtr : critterOldList)
		{
			if (critterPtr->isAlive == true)
			{
				critterList.push_back(critterPtr);

			}

		}



		for (Critter* critter : critterList)
		{

			//std::cout << critterManagerPtr->livingCritters.size();

			if (critter->reproduceFlag == true)
			{
				critter->reproduceFlag = false;
				critterManager2000.SpawnNewCritter(critter);

			}

		}



		window.clear();
		performanceWindow.clear();

		//mouseClickedFlag = false;

		performanceWindow3000.PollEvents();


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

				//graphicsProcessor9000.GroundClicked(mousePosition, critterList, sectorList);

				
			}
			if (e.type == sf::Event::MouseButtonReleased)
			{

				//graphicsProcessor9000.GroundUnClicked();

				for (Critter* critterPtr : critterList)
				{
					critterPtr->CritterUnClicked();
					mouseClickedFlag = false;
				}

			}

			if (e.type == sf::Event::KeyPressed) {
				if (e.key.code == sf::Keyboard::Space) {
					//critter1.Kill();
					critterList.at(0)->RotateCritter();
					//graphicsProcessor9000.UpdateItemPositions(&sector1);
				}
			}

			if (e.type == sf::Event::MouseWheelMoved)
			{
				gameboard.Zoom(e.mouseWheel.delta);

			}

		}





		graphicsProcessor9000.MoveScreen(mousePosition, *critterManagerPtr->livingCritters, sectorList);

		for (Sector* sector : sectorList)
		{
			sector->DrawAllTiles();
			sector->UpdateGridlinePosition();
			//sector->TileHovered(mousePosition);
			sector->DrawGridlines();
		}


		for (Critter* critterPtr : critterList)
		{
			//critterPtr->GrimReaper();
			critterPtr->MoveCritterWithMouse(mousePosition);
			critterPtr->UpdateCritter(FPS);
			critterPtr->DrawCritter(windowPtr);
		}

		critterStats.DrawBox(windowPtr, critterToDisplayPtr, durationExtracted, critterList.size());

		//performanceWindow3000.DisplayFPSData(durationExtracted);
		performanceWindow3000.UpdateAll(durationExtracted, critterList.size());

		performanceWindow.display();
		window.display();

		//std::cout << critterList.size() << std::endl;

		//end_time = std::chrono::high_resolution_clock::now();
		//duration = std::chrono::duration_cast<std::chrono::duration<float>>(end_time - start_time);
		//std::cout << "Time taken: " << std::fixed << std::setprecision(2) << duration.count()*60 << " seconds" << std::endl;

		fpsCounter++;

	}



}