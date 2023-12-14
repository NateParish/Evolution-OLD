#include "performance_window.h"


PerformanceWindow::PerformanceWindow(sf::RenderWindow* windowPtr)
{
	window = windowPtr;

    font1.loadFromFile("C:/Windows/Fonts/arial.ttf");
    FPSText;
    critterCountText;

    FPSText.setFont(font1);
    FPSText.setCharacterSize(14);
    FPSText.setFillColor(sf::Color::White);
    FPSText.setPosition(10, 10);

    critterCountText.setFont(font1);
    critterCountText.setCharacterSize(14);
    critterCountText.setFillColor(sf::Color::White);
    critterCountText.setPosition(10, 28);

}

PerformanceWindow::~PerformanceWindow()

{

}

void PerformanceWindow::PollEvents()
{
    sf::Event e;

    while (window->pollEvent(e)) {
        if (e.type == sf::Event::Closed)
            window->close();
    }
    if (e.type == sf::Event::Resized)

    {
        window->setView(sf::View(sf::FloatRect(0, 0, e.size.width, e.size.height)));

        FPSText.setCharacterSize(14);
        critterCountText.setCharacterSize(14);
    }
}

void PerformanceWindow::SetupFPSDisplay()

{
    FPSText.setFont(font1);
    FPSText.setCharacterSize(14);
    FPSText.setFillColor(sf::Color::White);
    FPSText.setPosition(100, 100);
}


void PerformanceWindow::DisplayFPSData(float duration)
{
    std::string secondsPer60Frames = "FPS:                  " + std::to_string(60 / duration);
    std::string formattedSecondsPer60Frames = secondsPer60Frames.substr(0, secondsPer60Frames.find('.') + 3);
    FPSText.setString(formattedSecondsPer60Frames);

    window->draw(FPSText);
}

void PerformanceWindow::DisplayCritterCount(int critterCount)
{
    std::string critterCountString = "Critter Count:        " + std::to_string(critterCount);
	critterCountText.setString(critterCountString);
    window->draw(critterCountText);
}

void PerformanceWindow::UpdateAll(float duration, int critterCount)
{
    //FPSText.setCharacterSize(14);
    //critterCountText.setCharacterSize(14);

    DisplayFPSData(duration);
    DisplayCritterCount(critterCount);
}