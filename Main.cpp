#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Menu.h"
#include "Game.h"
#include "Score.h"
#include "About.h"

using namespace sf;
using namespace std;

int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(1080, 720), "MerTales", Style::Default);
    Menu menu(window.getSize().x, window.getSize().y);
    Game game;
    Score score;
    About about;

    bool menuState = true;
    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::KeyReleased:
                switch (event.key.code)
                {
                case Keyboard::Up:
                    menu.MoveUp();
                    break;
                case Keyboard::Down:
                    menu.MoveDown();
                    break;
                }
                break;
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                if (Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    window.close();
                }
            default:
                break;
            }
        }
        if (menuState) 
        {
            menu.Draw(window);
        }
        if (menu.gameState) 
        {
            game.Draw(window);
        }
        if (menu.scoreState) 
        {
            score.Draw(window);
            if (score.Back(window))
            {
                menu.scoreState = false;
                menuState = true;
            }
        }
        if (menu.aboutState) 
        {
            about.Draw(window);
            if (about.Back(window))
            {
                menu.aboutState = false;
                menuState = true;
            }
        }
        
        window.display();
        window.clear();
    }
    return 0;
}