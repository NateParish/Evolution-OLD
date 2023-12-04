#include "cell.h"
#include "SFML/Graphics.hpp"
#include <iostream>


Cell::Cell(float originalX, float originalY, float originalWidth, float originalHeight)
{
    // Additional initialization code can go here if needed
    x = originalX;
    y = originalY;
    width = originalWidth;
    height = originalHeight;
    circle = sf::CircleShape(10);

    rectangle = sf::RectangleShape(sf::Vector2f(width, height));
    int red = 255;
    color = sf::Color(red, 0, 0);
    rectangle.setFillColor(color);
    rectangle.setPosition(sf::Vector2f(originalX, originalY));
    DNA geneticCode();


}

Cell::~Cell()
{

}

void Cell::GenerateDNA(std::string DNAsequence)

{

    geneticCode.setDNAsequence(DNAsequence);


}

void Cell::SetColorRGB(int red, int green, int blue)
{
    color = sf::Color(red, green, blue);
    rectangle.setFillColor(color);
}

void Cell::SetRectangleDimensions(int width, int height)
{
    rectangle.setSize(sf::Vector2f(width, height));
}

void Cell::DrawCell(sf::RenderWindow* window)
{
    //window->draw(circle);
    window->draw(rectangle);
}

void Cell::MoveCell(float dx, float dy)
{
    x = x + dx;
    y = y + dy;
    rectangle.setPosition(x, y);
}