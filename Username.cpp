#include "Username.h"

Username::Username()
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

}

Username::~Username()
{
}

bool Username::Next()
{
	//if (name.size() != 0 && Keyboard::isKeyPressed(Keyboard::Right))
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Username::Back()
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

void Username::Draw(RenderWindow& window)
{
	window.draw(bg);
	window.draw(userbox);
	window.draw(user);
}
