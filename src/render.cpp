#include <SFML/Graphics.hpp>
#include "Physics/object.h"
#include "simulation.h"
#include <iostream>

void renderObjects(Object **objectList,int numOfObjects,sf::RenderWindow *window)
{
    for (int i=1;i<=numOfObjects;i++)
    {
        Object *obj = objectList[i];
        std::cout<<obj->position.x<<" "<<obj->position.y<<std::endl;
        if(obj->shape==circle)
        {
            sf::CircleShape circle;
            circle.setRadius(5);
            circle.setPosition(obj->position.x,obj->position.y);
            window->draw(circle);

        }
    }
}

void renderLoop()
{
    sf::RenderWindow window(sf::VideoMode(1000,800), "SFML Window");
    Simulation simulation;
    Vector2 pos;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        renderObjects(simulation.objectList,simulation.numOfObjects,&window);

        window.display();
    }
}
