#include "About.h"

About::About()
{
	bgTexture.loadFromFile("Textures/island2.jpg");
	bg.setSize(Vector2f(1080.f, 720.f));
	bg.setPosition(0.0f, 0.0f);
	bg.setTexture(&bgTexture);

	//fontdExplain.loadFromFile("Fonts/editundo.ttf");
	//fontMain.loadFromFile("Fonts/Fipps-Regular.otf");
	fontMain.loadFromFile("Fonts/editundo.ttf");
	main.setFont(fontMain);
	main.setFillColor(Color::Black);
	main.setCharacterSize(80);
	main.setString("How to Play");
	main.setOrigin(Vector2f(main.getGlobalBounds().width / 2, 0));
	main.setPosition(540, 45);

	fontBack.loadFromFile("Fonts/hachicro.ttf"); //พิกเซลกลมดอกไม้
	back.setFont(fontBack);
	back.setFillColor(Color::Black);
	back.setCharacterSize(60);
	back.setString("<   >");
	back.setPosition(900, 625);
}

About::~About()
{
}

bool About::Back(RenderWindow& window)
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

void About::Draw(RenderWindow& window)
{
	window.draw(bg);
	window.draw(main);
	window.draw(back);
}
