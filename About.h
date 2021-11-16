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
	bool Back(RenderWindow& window);
	void Draw(RenderWindow& window);
	Text back;

private:
	Font fontMain;
	Text main;
	Font fontBack;
	
	Event event;

	RectangleShape bg;
	Texture bgTexture;
};

