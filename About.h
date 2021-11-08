#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class About
{
public:
	About();
	~About();

	void Shark();
	void Item();
	void Draw(RenderWindow& window);

private:
	Font font;
	Text main;

	RectangleShape bg;
	Texture bgTexture;
};

