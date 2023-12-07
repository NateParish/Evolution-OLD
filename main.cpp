#include <iostream>
#include <string>
#include <vector>
#include "SFML/Graphics.hpp"
#include "cell.h"
#include "critter.h"
#include "critter_stats_box.h"
#include "sun.h"
#include "ground.h"
#include "gameboard.h"
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


	sf::RenderWindow window(sf::VideoMode(1800, 950, 32), "SFML Graphics");
	sf::RenderWindow* windowPtr(&window);
	sf::Event e;
	window.setFramerateLimit(FPS);
	bool isClickedFlag(false);


	sf::Font font;
	if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
		std::cout << "couldn't Load Font" << std::endl;
		return 1;
	}

	sf::Vector2u windowSize = window.getSize();


	GeneticCalculator geneCalc5000;


	Sun sun;
	Gameboard gameboard;
	gameboard.CreateGround(2, 71, cellWidth);
	gameboard.GroundListPrintout();

	//Ground ground1;

	//std::vector<Ground*> groundList;

	//int columnCount = gameboard.columnCount;

	//	for (int i = 0; i <= gameboard.columnCount; ++i)
	//	{
	//		
	//		groundList.emplace_back();

	//		Ground* ground = new Ground();
	//		//newGround.Setup(xPad + cellWidth * i, menuHeight + cellWidth, i, 0, cellWidth, cellWidth);

	//		groundList.push_back(ground);

	//		std::cout << groundList->back().x << std::endl;
	//	}

	//	std::cout << "*********************** SIZE **************" << groundList.size() << std::endl;

	//	int k(0);

	//	std::cout << groundList[0]->x << std::endl;
	//	std::cout << groundList[1]->x << std::endl;
	//	std::cout << groundList[2]->x << std::endl;

	//	
	//	for (Ground* ground : groundList)
	{
		//std::cout << k << std::endl;
		//k++;
		
			//std::cout << ground->x << std::endl;
			//groundPtr->DrawGround(windowPtr);

	}

	//Ground newGround(xPad + cellWidth, menuHeight + cellWidth, 5, 5, cellWidth, cellWidth);


	//ground1.column = 2;
	//ground1.row = 2;
	//ground1.x = gameboard.gameBoardX + ground1.row * gameboard.cellSize;
	//ground1.x = gameboard.gameBoardY + ground1.row * gameboard.cellSize;


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
				mousePosition = sf::Mouse::getPosition(window);

				for (Critter* critterPtr : critterList)
				{
					isClickedFlag = false;

					isClickedFlag = critterPtr->CritterClicked(mousePosition);

					if (isClickedFlag == true)
					{
						critterToDisplayPtr = critterPtr;
					}

				}
				
			}
			if (e.type == sf::Event::MouseButtonReleased)
			{
				for (Critter* critterPtr : critterList)
				{
					critterPtr->CritterUnClicked();
				}

			}

			if (e.type == sf::Event::KeyPressed) {
				if (e.key.code == sf::Keyboard::Space) {
					//critter1.Kill();
					critter1.RotateCritter();
				}
			}

		}


		critterStats.DrawBox(windowPtr, critterToDisplayPtr);
		//ground1.DrawGround(windowPtr);
		//newGround.DrawGround(windowPtr);

		gameboard.GroundHovered(mousePosition);
		gameboard.DrawGround(windowPtr);
		gameboard.DrawGrid(windowPtr);
		

		for (Critter* critterPtr : critterList)
		{

			critterPtr->GrimReaper();
			critterPtr->MoveCritterWithMouse(mousePosition);
			critterPtr->UpdateCritter(FPS);
			critterPtr->DrawCritter(windowPtr);
		}

		//window.draw(sprite);
		//ground.DrawGrid(windowPtr);
		window.draw(text);
		window.display();

	}






}