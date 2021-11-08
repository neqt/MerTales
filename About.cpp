#include "About.h"

About::About()
{
	bgTexture.loadFromFile("Texture/island2.jpg");
	bg.setSize(Vector2f(1080.f, 720.f));
	bg.setPosition(0.0f, 0.0f);
	bg.setTexture(&bgTexture);

	font.loadFromFile("Fonts/editundo.ttf");
	Text ttext(" ", font, 50);
	main.setCharacterSize(80);
	main.setFillColor(sf::Color::White);
	main.setStyle(sf::Text::Style::Bold);
	main.setPosition(340, 0);
	main.setFont(font);
	main.setString("HOW TO PLAY");
}

About::~About()
{
}

void About::Draw(RenderWindow& window)
{
	window.draw(bg);
	window.draw(main);
}
