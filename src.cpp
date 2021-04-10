#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <thread>
#include <Windows.h>
#include <csignal>


bool Running = true;


void bubbleSort(std::vector<int> &toSort,int &first, int &scnd){
    int len = toSort.size()-1;
    int temp = 0;
    first = len;
    scnd = 0;
    
    while (first > 0 && Running)
    {
        Sleep(1);
        for (int j = 0; j < first; j++)
        {
            

            if(j%100 == 0)
                Sleep(1);

            scnd = j +1;
            
            temp = toSort.at(j);
            if (temp > toSort.at(scnd))
            {
                toSort.at(j) = toSort.at(scnd);
                toSort.at(scnd) = temp;
            }

        }
        first--;  
    }
    
}

void signalHandler( int signum ) {
   Running = false;
}


int main()
{
    // setting seed based on time so that we get different numbers each run
    srand(time(NULL));
    signal(SIGINT, signalHandler);

    sf::Vector2f winodwSize(1920, 1080);
    
    sf::RenderWindow window(sf::VideoMode(winodwSize.x, winodwSize.y), "SFML works!");

    std::vector<int> randomNumbers;

    for (int i = 0; i <= 1880; i++)
    {
        randomNumbers.push_back(rand() % 1000 + 1);
    }
    sf::Texture texture;
    sf::Sprite sprite;
    

    int first = -1;
    int scnd = -1;
    std::thread sorting(bubbleSort, std::ref(randomNumbers), std::ref(first),std::ref(scnd));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event) && !Running)
        {
            if (event.type == sf::Event::Closed || !Running)
                window.close();
        }
        sf::Image image; image.create(1920, 1080);

        // draw random number into image
        for (int x = 0; x <= 1880; x++)
        {
            int h = randomNumbers.at(x);

            for (int y = 0; y <= h; y++)
            {
                sf::Color clr(255,255,255);

                if(first == x)
                    clr = sf::Color(255,0,0);
                else if(scnd == x)
                    clr = sf::Color(0,255,0);


                image.setPixel(x+20,1070-y,clr);
            }
            
        }
        
        
        window.clear();
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        window.draw(sprite);
        window.display();
        
    }
    sorting.join();
    return 0;
}