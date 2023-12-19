#include "graphics_processor.h"


GraphicsProcessor::GraphicsProcessor(sf::RenderWindow* inputWindow)
{
	window = inputWindow;
	zoom = 1;
	xOffset = 0;
	yOffset = 0;
}

GraphicsProcessor::~GraphicsProcessor()
{

}

void GraphicsProcessor::RenderGraphics()
{


}

void GraphicsProcessor::UpdateItemPositions(Sector* targetSector)
{

	sf::Vector2i mousePosition(sf::Mouse::getPosition(*window));
	targetSector->CalculateNewOrigin(mousePosition);
	targetSector->UpdatePosition();
	std::cout << mousePosition.x << " " << mousePosition.y << std::endl;


	//for (int i = 0; i < targetSector->tileList.size(); ++i)
	//{

	//	std::cout << "GRAPHICS PROCESSOR - " << targetSector->tileList[i]->x << std::endl;
	//}

}