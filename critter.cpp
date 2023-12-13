#include <iostream>
#include "critter.h"
#include <random>




Critter::Critter()
{
    firstName = "No Name Assigned";
    lastName = "No Name Assigned";
    bodyRectangle;
    x = 500;
    y = 500;
    width = 75;
    height = 75;
    clicked = false;
    isAlive = true;
    clickedOffsetX = 0;
    clickedOffsetY = 0;
    hydration = 100;
    fpsCounter = 0;
    //cell1;
    //eye1;
    //eye2;
    
}

Critter::Critter(int positionX, int positionY)
{
    firstName = "No Name Assigned";
    lastName = "No Name Assigned";
    bodyRectangle;
    bodyRectangle2;
    x = positionX;
    y = positionY;
    width = 25;
    height = 25;
    clicked = false;
    isAlive = true;
    clickedOffsetX = 0;
    clickedOffsetY = 0;
    hydration = 100;
    fpsCounter = 0;
    reproduceCounterStart = 100;
    reproduceCounter = reproduceCounterStart;
    reproduceFlag = false;
    
    //eye1;
    //eye2;
    eyeTexture;

    listOfCells;

    if (!eyeTexture.loadFromFile("images/GooglyEyes2.png")) {
        // Handle the error if the image cannot be loaded
        std::cerr << "Error loading image." << std::endl;
    }
    
}

Critter::~Critter()
{

}



void Critter::generateBody()
{
    Cell newCell(x,y,width,height);
    GeneticCalculator geneCalc5000;

   

    cell1.GenerateDNA("TAGGTATACACCCCCCCCCC");
    cell1.geneticCode.CreateGenes();
    int red(stoi(geneCalc5000.ConvertToBase10(geneCalc5000.ConvertBasesToNumbers(cell1.geneticCode.colorRedGene.geneSequence))));
    int green(stoi(geneCalc5000.ConvertToBase10(geneCalc5000.ConvertBasesToNumbers(cell1.geneticCode.colorGreenGene.geneSequence))));
    int blue(stoi(geneCalc5000.ConvertToBase10(geneCalc5000.ConvertBasesToNumbers(cell1.geneticCode.colorBlueGene.geneSequence))));
    cell1.SetColorRGB(red, green, blue);
    cell1.SetRectangleDimensions(width, height);

    //bodyRectangle = cell1.rectangle;
    bodyRectangle2 = cell1.rectangle;
    //bodyRectangle2.setFillColor(sf::Color(255, 0, 0));
    
    cell1.originOffsetX = 0;
    cell1.originOffsetY = 0;
    cell1.rectangle.setOrigin((width / 2), height / 2);


    //int boxX = bodyRectangle.getOrigin().x;
   // int boxY = bodyRectangle.getOrigin().y;


    cell1.rectangle.setPosition((x + width / 2) + cell1.originOffsetX, y + width / 2 + cell1.originOffsetY);
    
    //bodyRectangle2.setPosition(x,y);

    cell2.GenerateDNA("TAGGTATACACCCCCCCCCC");
    cell2.geneticCode.CreateGenes();
    red = stoi(geneCalc5000.ConvertToBase10(geneCalc5000.ConvertBasesToNumbers(cell2.geneticCode.colorRedGene.geneSequence)));
    green = stoi(geneCalc5000.ConvertToBase10(geneCalc5000.ConvertBasesToNumbers(cell2.geneticCode.colorGreenGene.geneSequence)));
    blue = stoi(geneCalc5000.ConvertToBase10(geneCalc5000.ConvertBasesToNumbers(cell2.geneticCode.colorBlueGene.geneSequence)));
    cell2.SetColorRGB(red, green, blue);
    cell2.SetRectangleDimensions(width, height);
    cell2.rectangle.setFillColor(sf::Color(200, 200, 100));

    cell2.originOffsetX = (width / 2);
    cell2.originOffsetY = (height / 2 - height);

    cell2.rectangle.setOrigin((cell2.originOffsetX), cell2.originOffsetY);
    cell2.rectangle.setPosition(x + width / 2, y + width / 2);

    Cell* cell1Ptr(&cell1);
    Cell* cell2Ptr(&cell2);

    listOfCells.push_back(cell1Ptr);
    listOfCells.push_back(cell2Ptr);

    //eye1.setTexture(eyeTexture);
    //eye1.setPosition(x + float(width)/20, y + float(height)/2.2);
    //eye1.setScale((float(width) / 2200), -1 * float(width) / 2200);

   // eye2.setTexture(eyeTexture);
    //eye2.setPosition(x + float(width) / 20 + float(width) / 2, y + float(height) / 2.2);

   // eye2.setScale(float(width)/2200, -1 * float(width) / 2200);


}

void Critter::DrawCritter(sf::RenderWindow* window)
{
    for (Cell* cellPtr : listOfCells)
    {
        window->draw(cellPtr->rectangle);
    }

}

bool Critter::CritterClicked(sf::Vector2i mousePosition)
{
    
    clicked = false;

    for (Cell* cellPtr : listOfCells)
    {

        int xPos = cellPtr->rectangle.getPosition().x - width/2;
        int yPos = cellPtr->rectangle.getPosition().y;

        if (mousePosition.x >= xPos)
        {
            if (mousePosition.x <= (xPos + width))
            {
                if (mousePosition.y >= yPos + cellPtr->originOffsetY)
                {
                    if (mousePosition.y <= (yPos + height) - cellPtr->originOffsetY)
                    {
                        clicked = true;
                        clickedOffsetX = mousePosition.x - x;
                        clickedOffsetY = mousePosition.y - y;
                    }
                }
            }
        }

    }

    return clicked;
    
}

void Critter::CritterUnClicked()
{
    clicked = false;
}

void Critter::MoveCritterWithMouse(sf::Vector2i mousePosition)
{

    if (clicked == true)
    {
        //std::cout << mousePosition.x << " " << mousePosition.y << " " << x << " " << y;

        x = mousePosition.x - clickedOffsetX;
        y = mousePosition.y - clickedOffsetY;

        cell1.rectangle.setPosition(float(x) + float(width)/2, float(y) + float(width)/2);
        cell2.rectangle.setPosition(cell1.rectangle.getPosition().x, cell1.rectangle.getPosition().y);
        //bodyRectangle2.setPosition(x, y);

       // std::cout << cell1.rectangle.getPosition().x << " " << cell1.rectangle.getPosition().y << "    |      " << cell2.rectangle.getPosition().x << " " << cell2.rectangle.getPosition().y << std::endl;



    }

}

void Critter::UpdateCritter(int FPS)
{

    fpsCounter++;

    if (fpsCounter > FPS)
    {
        fpsCounter = 0;
    }

    hydration = hydration - (1 / float(FPS));

    if (reproduceCounter < 1)
    {
        reproduceCounter = reproduceCounterStart;
        reproduceFlag = true;
        //std::cout << "reproduce!";
    }
    else
    {
        reproduceCounter--;
    }

}

void Critter::Kill()
{
    isAlive = false;
}

void Critter::RotateCritter()
{
    //bodyRectangle.setOrigin((width/2)-200, height/2);
    cell1.rectangle.rotate(20);
    cell2.rectangle.rotate(20);

}

void Critter::GrimReaper()
{
    if (hydration <= 0)
    {
        Kill();
    }

}

void Critter::RandomReproductionRate()
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, 255);
    int random_number = distribution(generator);
    reproduceCounterStart = random_number*5;

}