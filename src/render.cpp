#include <SFML/Graphics.hpp>
#include "Physics/object.h"
#include "simulation.h"
#include <iostream>
#include <chrono>
#include "globals.h"
#include "ctime"

float GetCurrentTime()
{
    using namespace std::chrono;
    auto currentTime = steady_clock::now();
    return duration_cast<duration<float>>(currentTime.time_since_epoch()).count();
}

void renderObjects(Object **objectList,int numOfObjects,sf::RenderWindow *window)
{
    for (int i=1;i<=numOfObjects;i++)
    {
        Object *obj = objectList[i];
        if(obj->shape==circle)
        {
            sf::CircleShape circle;
            if(i<10)
            {
                circle.setFillColor(sf::Color(255,255,0));
            }
            circle.setRadius(obj->radius);
            circle.setPosition(obj->positionCurrent.x,obj->positionCurrent.y);
            window->draw(circle);

        }
    }
}
void render(sf::RenderWindow *window,Simulation *simulation)
{
        window->clear();

        renderObjects(simulation->objectList,simulation->numOfObjects,window);

        window->display();
}

void gameLoop()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "SFML Window");


    Simulation simulation;
    float previousTime = GetCurrentTime();
    float currentTime = GetCurrentTime();

    float fixedDeltaTime = 1.0f/75.0f;
    sf::Clock clock;
    float accumulator = 0.0f;
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        previousTime = currentTime;
        currentTime = GetCurrentTime();

        sf::Time deltaTime = clock.restart();
        accumulator += deltaTime.asSeconds();
        while (accumulator >= fixedDeltaTime)
        {
            // Update the simulation using the fixed time step
            // ...
            simulation.Update(fixedDeltaTime);
            accumulator -= fixedDeltaTime;
        }

        /*float deltaTime = currentTime-previousTime;
        if(deltaTime>0.15f)
        {
            deltaTime= 0.15f;
        }*/





        render(&window,&simulation);


    }
}
