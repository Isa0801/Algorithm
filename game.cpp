#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>



int main()
{
    sf::Vector2f winodwSize(1920, 1080);
    
    sf::RenderWindow window(sf::VideoMode(winodwSize.x, winodwSize.y), "SFML works!");

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
    return 0;
}