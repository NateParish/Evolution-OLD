#include "graphics_processor.h"


GraphicsProcessor::GraphicsProcessor(sf::RenderWindow* inputWindow)
{
	window = inputWindow;
	zoom = 1;
	xOffset = 0;
	yOffset = 0;
    
    groundClicked = false;
    setPositionFlag = true;

}

GraphicsProcessor::~GraphicsProcessor()
{

}

bool GraphicsProcessor::GroundClicked(sf::Vector2i mousePosition, std::vector<Critter*> critterList, std::vector<Sector*> sectorList)
{

    groundClicked = true;
    //std::cout << "ground has been clicked";

    for (Sector* sector : sectorList)
    {

        sector->clickedOffsetX = mousePosition.x - sector->originX;
        sector->clickedOffsetY = mousePosition.y - sector->originY;
        sector->SetupGridlines();
    }

    //std::cout << "Set Position is TRUE";
    //xOffset = mousePosition.x - sectorPtr->originX;
    //yOffset = mousePosition.y - sectorPtr->originY;

    for (Critter* critter : critterList)
    {
        critter->clickedOffsetX = mousePosition.x - critter->x;
        critter->clickedOffsetY = mousePosition.y - critter->y;
    }



    return groundClicked;

}

bool GraphicsProcessor::GroundUnClicked()
{
    groundClicked = false;

    //std::cout << "ground has been unclicked";

    return groundClicked;
}

void GraphicsProcessor::MoveScreen(sf::Vector2i mousePosition, std::vector<Critter*> critterList, std::vector<Sector*> sectorList)
{


    if (groundClicked == true)
    {

        for (Critter* critter : critterList)
        {

            critter->clicked = true;
            //critter->clickedOffsetX = mousePosition.x - critter->x;
            //critter->clickedOffsetY = mousePosition.y - critter->y;
            critter->MoveCritterWithMouse(mousePosition);
            critter->clicked = false;
        }
        
        for (Sector* sector : sectorList)
        {
            int x = mousePosition.x - sector->clickedOffsetX;
            int y = mousePosition.y - sector->clickedOffsetY;
            sector->originX = x;
            sector->originY = y;
            sector->UpdatePosition();
            //sector->UpdateGridlinePosition();

        }

        //int x = mousePosition.x - xOffset;
        //int y = mousePosition.y - yOffset;

        //sectorPtr->originX = x;
        //sectorPtr->originY = y;
        //sectorPtr->UpdatePosition();
        //sectorPtr->UpdateGridlinePosition();

    }

}

void GraphicsProcessor::RenderGraphics()
{


}

void GraphicsProcessor::UpdateItemPositions(Sector* targetSector)
{

	sf::Vector2i mousePosition(sf::Mouse::getPosition(*window));
	targetSector->CalculateNewOrigin(mousePosition);
	targetSector->UpdatePosition();


}