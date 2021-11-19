#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#define STD_WANT_LIB_EXIT 1
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
#include "Song.h"
using namespace sf;
using namespace std;

bool Next();
bool Back();
void UserName();

Text enter;
vector<char> name;
string userName;
Font font;
Texture userTexture;
RectangleShape userbox;
Text user;
RectangleShape bg;
Texture bgTexture;

RenderWindow window(VideoMode(1080, 720), "MerTales", Style::Default);

int main()
{
    bool userState = false;

    srand(time(NULL));

    Menu menu(window.getSize().x, window.getSize().y);
    Game game;
    Score score;
    About about;
    Song song;

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
                    if (menu.menuState)
                    {
                        song.Choose();
                        menu.MoveUp();
                    }
                    break;
                case Keyboard::Down:
                    if (menu.menuState)
                    {
                        song.Choose();
                        menu.MoveDown();
                    }
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

            if (menu.userState)
            {
                if (event.type == sf::Event::TextEntered) {
                    name.push_back(event.text.unicode);
                }
                if (!name.empty() && name.back() == 8)
                {
                    name.pop_back();
                    if (!name.empty())
                        name.pop_back();
                }
                if (name.size() != 1 && !name.empty() && name.back() == 13)
                {
                    name.pop_back();
                }
                if (!name.empty() && !((name.back() >= 'a' && name.back() <= 'z') || (name.back() >= 'A' && name.back() <= 'Z') || (name.back() >= '0' && name.back() <= '9') || name.back() == '_'))
                {
                    name.pop_back();
                }
                if (name.size() > 15)
                {
                    name.pop_back();
                }
                if (Keyboard::isKeyPressed(Keyboard::Enter) && name.size() != 0) 
                {
                    song.Click();
                    score.playerName = userName;
                    menu.userState = false;
                    menu.gameState = true;
                }
            }
        }
        if (menu.menuState)
        {
            song.Menu();
            menu.Draw(window);
        }
        if (menu.userState)
        {
            song.Menu();
            UserName();
            if (Back())
            {
                song.Click();
                menu.userState = false;
                menu.menuState = true;
            }
        }
        if (menu.gameState)
        {
            song.Menu();
            song.menuSong = false;
            song.gameSong = true;
            game.Draw(window);
            if (game.GameOver() && Keyboard::isKeyPressed(Keyboard::Right))
            {
                score.playerScore = game.point;
                song.Click();
                score.WriteFile();
                game.Reset();
                menu.gameState = false;
                menu.userState = false;
                menu.menuState = true;
                song.gameSong = false;
            }
        }
        if (menu.scoreState)
        {
            song.Menu();
            score.Draw(window);
            if (score.Back())
            {
                song.Click();
                menu.scoreState = false;
                menu.menuState = true;
            }
        }
        if (menu.aboutState)
        {
            song.Menu();
            about.Draw(window);
            if (about.Back())
            {
                song.Click();
                menu.aboutState = false;
                menu.menuState = true;
            }
        }
        window.display();
        window.clear();
    }
    return 0;
}

bool Next()
{
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Back()
{
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void UserName()
{
    font.loadFromFile("Fonts/editundo.ttf");

    bgTexture.loadFromFile("Textures/island2.jpg");
    bg.setSize(Vector2f(1080.f, 720.f));
    bg.setPosition(0.0f, 0.0f);
    bg.setTexture(&bgTexture);

    userTexture.loadFromFile("Textures/username.png");
    userbox.setSize(Vector2f(540.f, 180.f));
    userbox.setOrigin(userbox.getGlobalBounds().width / 2, userbox.getGlobalBounds().height / 2);
    userbox.setPosition(540.f, 360.f);
    userbox.setTexture(&userTexture);

    userName = "";
    for (int i = 0; i < name.size(); i++)
    {
        userName += name[i];
    }
    user.setFont(font);
    user.setFillColor(Color::Black);
    user.setCharacterSize(50);

    if (name.empty())
    {
        user.setFillColor(sf::Color(255, 255, 255, 100));
        user.setString("Enter your name");
    }
    else
    {
        user.setFillColor(sf::Color::Black);
        user.setString(userName);
    }
    user.setOrigin(user.getGlobalBounds().width / 2, user.getGlobalBounds().height / 2);
    user.setPosition(540, 340);

    window.draw(bg);
    window.draw(userbox);
    window.draw(user);
}