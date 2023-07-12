#include <SFML/Graphics.hpp>

void renderObjects()
{

}

void renderLoop()
{
    sf::RenderWindow window(sf::VideoMode(1000,800), "SFML Window");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }
}
