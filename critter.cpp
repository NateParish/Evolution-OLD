#include <iostream>
#include "critter.h"
#include <random>




Critter::Critter()
{
    firstName = "No Name Assigned";
    lastName = "No Name Assigned";
    bodyRectangle;
    bodyCircle;
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

Critter::Critter(int positionX, int positionY, std::string DNA)
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
    hydration = 25;
    fpsCounter = 0;
    reproduceCounterStart = 100;
    reproduceCounter = reproduceCounterStart;
    reproduceFlag = false;
    DNAsequence = DNA;
    
    //eye1;
    //eye2;
    eyeTexture;

    listOfCells;

    //if (!eyeTexture.loadFromFile("images/GooglyEyes2.png")) {
    //    // Handle the error if the image cannot be loaded
    //    //std::cerr << "Error loading image." << std::endl;
    //}
    
}

Critter::~Critter()
{
    for (Cell* cell : listOfCells) 
    {
        delete cell;
    }
}

void Critter::CreateCell()
{
    
    GeneticCalculator geneCalc5000;
    
    Cell* cell = new Cell();
    

    cell->SetupNewCell(DNAsequence);
    //cell->GenerateDNA(DNAsequence);
    //cell->geneticCode.CreateGenes();
    int red(stoi(geneCalc5000.ConvertToBase10(geneCalc5000.ConvertBasesToNumbers(cell->geneticCode.colorRedGene.geneSequence))));
    int green(stoi(geneCalc5000.ConvertToBase10(geneCalc5000.ConvertBasesToNumbers(cell->geneticCode.colorGreenGene.geneSequence))));
    int blue(stoi(geneCalc5000.ConvertToBase10(geneCalc5000.ConvertBasesToNumbers(cell->geneticCode.colorBlueGene.geneSequence))));
    //cell->SetColorRGB(red, green, blue);
    cell->SetDimensions(width, height);


    // CHANGE TO BE ENTIRE CRITTER
    bodyRectangle = cell->rectangle;
    bodyCircle = cell->circle;


    cell->originOffsetX = 0;
    cell->originOffsetY = 0;
    cell->rectangle.setOrigin((width / 2), height / 2);
    cell->circle.setOrigin((width / 2), height / 2);

    cell->rectangle.setPosition((x + width / 2) + cell->originOffsetX, y + width / 2 + cell->originOffsetY);
    cell->circle.setPosition((x + width / 2) + cell->originOffsetX, y + width / 2 + cell->originOffsetY);

    //Cell* cell1Ptr(&cell1);

    listOfCells.push_back(cell);

}

void Critter::DrawCritter(sf::RenderWindow* window)
{
    for (Cell* cellPtr : listOfCells)
    {
        //window->draw(cellPtr->rectangle);
        window->draw(cellPtr->circle);
    }

}

bool Critter::CritterClicked(sf::Vector2i mousePosition)
{
    
    clicked = false;

    for (Cell* cellPtr : listOfCells)
    {

        int xPos = cellPtr->rectangle.getPosition().x - width/2;
        int yPos = cellPtr->rectangle.getPosition().y - height/2;

        if (mousePosition.x >= xPos)
        {
            if (mousePosition.x <= (xPos + width))
            {
                if (mousePosition.y >= yPos)
                {
                    if (mousePosition.y <= (yPos + height))
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

        x = mousePosition.x - clickedOffsetX;
        y = mousePosition.y - clickedOffsetY;

        for (Cell* cell : listOfCells) 
        {
            cell->rectangle.setPosition(float(x) + float(width) / 2, float(y) + float(width) / 2);
            cell->circle.setPosition(float(x) + float(width) / 2, float(y) + float(width) / 2);

        }

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
    bodyRectangle.setOrigin((width/2)-200, height/2);

    for (Cell* cell : listOfCells) 
    {
        cell->rectangle.rotate(20);
    }
    //cell1.rectangle.rotate(20);
    //cell2.rectangle.rotate(20);

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
    std::uniform_int_distribution<int> distribution(100, 5000);
    int random_number = distribution(generator);
    reproduceCounter = random_number;

}

void Critter::DNArandomMutate()
{
    int length(DNAsequence.size());
    std::string oldDNAsequence;
    std::string newDNAsequence;
    char newChar('0');


    std::cout << length << std::endl;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 10);
    std::uniform_int_distribution<int> distrib2(0, 3);

    int randomNumber = distrib(gen);
    int randomNumber2 = 0;
    std::cout << randomNumber;
    
    for (int i = 0; i < length; i++)
    {
        randomNumber = distrib(gen);

        if (randomNumber == 1)


        {
            randomNumber2 = distrib2(gen);

            if (randomNumber2 == 0)
            {
                newChar = 'A';
            }
            else if (randomNumber2 == 1)
            {
                newChar = 'G';
            }
            else if (randomNumber2 == 2)
            {
                newChar = 'T';
            }
            else if (randomNumber2 == 3)
            {
                newChar = 'C';
            }
                        

            std::cout << "Random 2:    " << randomNumber2 << "New Character:  " << newChar << std::endl;

            newDNAsequence = newDNAsequence + newChar;


            

        }
        else

        {
            newDNAsequence = newDNAsequence + DNAsequence[i];
        }

  

        //std::cout << DNAsequence[i] << std::endl;
    }

    std::cout << randomNumber << std::endl;
    std::cout << "NEW DNA SEQUENCE " << newDNAsequence << std::endl;


}

std::string Critter::CreateNewMutatedDNA()
{
    int length(DNAsequence.size());
    std::string oldDNAsequence;
    std::string newDNAsequence;
    char newChar('0');


    //std::cout << length << std::endl;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 10);
    std::uniform_int_distribution<int> distrib2(0, 3);

    int randomNumber = distrib(gen);
    int randomNumber2 = 0;
    //std::cout << randomNumber;

    for (int i = 0; i < length; i++)
    {
        randomNumber = distrib(gen);

        if (randomNumber == 1)


        {
            randomNumber2 = distrib2(gen);

            if (randomNumber2 == 0)
            {
                newChar = 'A';
            }
            else if (randomNumber2 == 1)
            {
                newChar = 'G';
            }
            else if (randomNumber2 == 2)
            {
                newChar = 'T';
            }
            else if (randomNumber2 == 3)
            {
                newChar = 'C';
            }


            //std::cout << "Random 2:    " << randomNumber2 << "New Character:  " << newChar << std::endl;

            newDNAsequence = newDNAsequence + newChar;




        }
        else

        {
            newDNAsequence = newDNAsequence + DNAsequence[i];
        }



        //std::cout << DNAsequence[i] << std::endl;
    }

    return newDNAsequence;
}

float Critter::CalculateDistance(float objX, float objY)
{

    

    float distance= sqrt(pow((x + width/2) - objX, 2) + pow((y+ height/2) - objY, 2));
    //std::cout << distance << std::endl;
        


    return distance;
}

void Critter::DistanceToOtherCritters(std::vector<Critter*> critterList)
{
    //float distance(2500);

    for (Critter* critterPtr : critterList)
    {
        float otherCritterX(critterPtr->x + critterPtr->width / 2);
        float otherCritterY(critterPtr->x + critterPtr->width / 2);

        float distance(CalculateDistance(otherCritterX, otherCritterY));

        std::cout << "Distance " << distance << std::endl;


        if (distance > 0)
        {
            if (distance < width)
            {
                std::cout << "YES" << std::endl;

                if (x < otherCritterX)
                {
                    x = x - 1;

                    for (Cell* cell : critterPtr->listOfCells)
                    {
                        bodyCircle.setPosition(float(x) + float(width) / 2, float(y) + float(width) / 2);
                        cell->rectangle.setPosition(float(x) + float(width) / 2, float(y) + float(width) / 2);
                        cell->circle.setPosition(float(x) + float(width) / 2, float(y) + float(width) / 2);

                    }


                };
                if (x > otherCritterX)
                {
                    x = (x + 1);


                    for (Cell* cell : critterPtr->listOfCells)
                    {
                        bodyCircle.setPosition(float(x) + float(width) / 2, float(y) + float(width) / 2);
                        cell->rectangle.setPosition(float(x) + float(width) / 2, float(y) + float(width) / 2);
                        cell->circle.setPosition(float(x) + float(width) / 2, float(y) + float(width) / 2);

                    }

                };

            }
            //std::cout << distance << std::endl;
        }   
        
    }


}