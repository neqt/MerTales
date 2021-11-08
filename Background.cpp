#include "Background.h"

Background::Background()
{
	bgTexture.loadFromFile("Texture/underwater.jpg");

	bg.setSize(Vector2f(1080.f, 720.f));
	bg.setPosition(0.0f, 0.0f);
	bg.setTexture(&bgTexture);
}

Background::~Background()
{
}

void Background::Draw(RenderWindow& window)
{
	window.draw(bg);
}