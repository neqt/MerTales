#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class About
{
public:
	About();
	~About();

	bool Back();
	void Draw(RenderWindow& window);

	Text back;

private:
	Font fontMain;
	Font font;
	Text main;
	
	RectangleShape bg;
	Texture bgTexture;
	
	RectangleShape box;
	Texture boxTexture;

	RectangleShape wasd;
	Texture wasdTexture;
	Text wasdText;

	RectangleShape space;
	Texture spaceTexture;
	Text spaceText;

	RectangleShape shark;
	Texture sharkTexture;
	Text sharkText;

	RectangleShape coin;
	Texture coinTexture;
	Text coinText;

	RectangleShape shield;
	Texture shieldTexture;
	Text shieldText;

	RectangleShape heal;
	Texture healTexture;
	Text healText;

	RectangleShape bonus;
	Texture bonusTexture;
	Text bonusText;
	
};

