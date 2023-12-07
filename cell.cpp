#include "cell.h"
#include "SFML/Graphics.hpp"
#include <iostream>


Cell::Cell()
{
    // Additional initialization code can go here if needed
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    circle = sf::CircleShape(10);
    originOffsetX = 0;
    originOffsetY = 0;
    rectangle = sf::RectangleShape(sf::Vector2f(width, height));
    int red = 255;
    color = sf::Color(red, 0, 0);
    rectangle.setFillColor(color);
    rectangle.setPosition(sf::Vector2f(x, y));
    DNA geneticCode();


}



Cell::Cell(float originalX, float originalY, float originalWidth, float originalHeight)
{
    // Additional initialization code can go here if needed
    x = originalX;
    y = originalY;
    width = originalWidth;
    height = originalHeight;
    circle = sf::CircleShape(10);
    originOffsetX = 0;
    originOffsetY = 0;

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

std::string Cell::GetColorRGB(std::string desiredColor = "all")
{

    std::string outputString("");
    int red = color.r;
    int green = color.g;
    int blue = color.b;
    int alpha = color.a;
   
    if (desiredColor == "r")
    {
        outputString = std::to_string(red);
    }
    if (desiredColor == "g")
    {
        outputString = std::to_string(green);
    }
    if (desiredColor == "b")
    {
        outputString = std::to_string(blue);
    }
    if (desiredColor == "a")
    {
        outputString = std::to_string(alpha);
    }
    if (desiredColor == "all")
    {
        outputString = std::to_string(red) + ", " + std::to_string(green) + ", " + std::to_string(blue);
    }

    std::cout << "Red:      " << red << std::endl;
    std::cout << "Green:      " << green << std::endl;
    std::cout << "Blue:      " << blue << std::endl;
    std::cout << "Blue:      " << alpha << std::endl;


    return outputString;

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