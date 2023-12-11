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


	//sf::Texture eyeTexture;
	//if (!eyeTexture.loadFromFile("images/GooglyEyes2.png")) {
	//	// Handle the error if the image cannot be loaded
	//	std::cerr << "Error loading image." << std::endl;
	//	return 1;
	//}

	//sf::Sprite sprite(eyeTexture);
	//sprite.setPosition(245, 245);
	//sprite.setScale(.25, .25);


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
	//Gameboard gameboard;
	//gameboard.CreateTile(2, 71, cellWidth);
	//gameboard.TileListPrintout();

	Sector sector1(windowPtr);
	sector1.SetAllTilePosition();
	sector1.SetupGridlines();

	GraphicsProcessor graphicsProcessor9000(windowPtr);

	//graphicsProcessor9000.UpdateItemPositions(&sector1);


	std::cout << "Sun Output" << sun.output << std::endl;

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

	std::cout << "The critter to display is:  " << critterToDisplayPtr->name;


	sf::Text text;
	text.setFont(font);
	//text.setString(particle1.geneticCode.geneSequence);
	text.setCharacterSize(15);
	text.setFillColor(sf::Color::White);
	text.setPosition(windowSize.x - 100, 10);
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2i mouseAnchor(0, 0);
	bool mouseAnchorSet = false;
	std::cout << "**BOOGA** " << mouseAnchorSet << std::endl;

	while (window.isOpen())
	{

		//std::cout << critter1.isAlive << "     " << critterList.size() << std::endl;

		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		critterOldList.clear();
		critterOldList = critterList;
		critterList.clear();





		

		

		//std::cout << critterOldList.size() << "  /   " << critterList.size() << std::endl;

		//critterList.push_back(&critter1);




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
				moveTerrainFlag = true;
				mouseAnchor = sf::Mouse::getPosition(window);

				mousePosition = sf::Mouse::getPosition(window);

				for (Critter* critterPtr : critterList)
				{
					isCritterClickedFlag = false;

					isCritterClickedFlag = critterPtr->CritterClicked(mousePosition);

					if (isCritterClickedFlag == true)
					{
						critterToDisplayPtr = critterPtr;
						moveTerrainFlag = false;
					}

				}

				
			}
			if (e.type == sf::Event::MouseButtonReleased)
			{
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
					graphicsProcessor9000.UpdateItemPositions(&sector1);
				}
			}

		}



		if (mouseClickedFlag == true)
		{
			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

			if (mouseAnchorSet == false);
			{
				mouseAnchor = sf::Mouse::getPosition(window);
				mouseAnchorSet = true;
				std::cout << "mouse Anchor has been set!" << std::endl;
			}

			std::cout << "mouseClickedFlag: " << mouseClickedFlag <<  " mouseAnchorSet: " << mouseAnchorSet << "  anchorx:  " << mouseAnchor.x << " anchorY : " << mouseAnchor.y << " mousex : " << mousePosition.x << " mousey : " << mousePosition.y << " diff : " << mouseAnchor.x - mousePosition.x << ", " << mouseAnchor.y - mousePosition.y << std::endl;

		}


		critterStats.DrawBox(windowPtr, critterToDisplayPtr);
		//ground1.DrawGround(windowPtr);
		//newGround.DrawGround(windowPtr);

		//gameboard.TileHovered(mousePosition);
		//gameboard.DrawTile(windowPtr);
		sector1.DrawAllTiles();
		sector1.DrawGridlines();
		//gameboard.DrawGrid(windowPtr);
		

		for (Critter* critterPtr : critterList)
		{

			critterPtr->GrimReaper();
			critterPtr->MoveCritterWithMouse(mousePosition);
			critterPtr->UpdateCritter(FPS);
			critterPtr->DrawCritter(windowPtr);
		}

		//window.draw(sprite);
		//ground.DrawGrid(windowPtr);
		//window.draw(text);
		window.display();

	}






}