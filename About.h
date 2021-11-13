#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Joystick.hpp>
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
	bool backState;
	Text back;

private:
	Font fontMain;
	Text main;
	Font fontBack;
	

	RectangleShape bg;
	Texture bgTexture;
};

