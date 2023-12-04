#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "cell.h"
//#include "DNA.h"


int main()
{



	sf::RenderWindow window(sf::VideoMode(1300, 800, 32), "SFML Graphics");
	sf::RenderWindow* windowPtr(&window);
	sf::Event e;
	window.setFramerateLimit(60);


	sf::Font font;
	if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
		std::cout << "couldn't Load Font" << std::endl;
		return 1;
	}

	sf::Vector2u windowSize = window.getSize();


	GeneticCalculator geneCalc5000;


	Cell newCell(100, 100, 100, 100);
	newCell.GenerateDNA("TAGGTATACACCCCCCCCCC");
	newCell.geneticCode.CreateGenes();

	std::cout << newCell.geneticCode.colorRedGene.geneSequence << std::endl;
	std::cout << newCell.geneticCode.colorGreenGene.geneSequence << std::endl;
	std::cout << newCell.geneticCode.colorBlueGene.geneSequence << std::endl;

	int red(stoi(geneCalc5000.ConvertToBase10(geneCalc5000.ConvertBasesToNumbers(newCell.geneticCode.colorRedGene.geneSequence))));
	int green(stoi(geneCalc5000.ConvertToBase10(geneCalc5000.ConvertBasesToNumbers(newCell.geneticCode.colorGreenGene.geneSequence))));
	int blue(stoi(geneCalc5000.ConvertToBase10(geneCalc5000.ConvertBasesToNumbers(newCell.geneticCode.colorBlueGene.geneSequence))));

	std::cout << "Red RGB:  " << red << std::endl;
	std::cout << "Green RGB:  " << green << std::endl;
	std::cout << "Blue RGB:  " << blue << std::endl;


	std::cout << newCell.geneticCode.DNAsequence << "Did it work?" << std::endl;


	//newCell.color = sf::Color(red,green,blue);
	newCell.SetColorRGB(red, green, blue);
	newCell.SetRectangleDimensions(std::stoi(geneCalc5000.ConvertToBase10(geneCalc5000.ConvertBasesToNumbers(newCell.geneticCode.widthGene.geneSequence))), std::stoi(geneCalc5000.ConvertToBase10(geneCalc5000.ConvertBasesToNumbers(newCell.geneticCode.heightGene.geneSequence))));
	std::cout << newCell.width << std::endl;
	std::cout << newCell.height << std::endl;

	sf::Text text;
	text.setFont(font);
	//text.setString(particle1.geneticCode.geneSequence);
	text.setCharacterSize(15);
	text.setFillColor(sf::Color::White);
	text.setPosition(windowSize.x - 100, 10);



	while (window.isOpen())
	{

		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);



		window.clear();

		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
			if (e.type == sf::Event::Resized)
				window.setView(sf::View(sf::FloatRect(0, 0, e.size.width, e.size.height)));
			//if (e.type == sf::Event::MouseButtonPressed)
				//critter1.MoveCell(5, 5);
		}

		//text.setString(particle1.geneticCode.geneSequence);

		//window.draw(testCircle);
		//critter1.DrawCell(windowPtr);
		newCell.DrawCell(windowPtr);
		window.draw(text);

		window.display();

	}






}