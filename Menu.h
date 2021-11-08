#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#define maxItem 4

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void Draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItem; }

	bool gameState = false;
	bool scoreState = false;
	bool aboutState = false;

private:
	int selectedItem = 0;
	Font font;
	Font fontMertales;
	Font fontDev;
	Text mertales;
	Text dev;
	Text menu[maxItem];

	RectangleShape bg;
	Texture bgTexture;
	Vector2f position;
	Vector2f size;
};

