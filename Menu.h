#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Score.h"
#include "About.h"
#include "Song.h"

using namespace sf;
#define maxItem 4

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void MoveUp();
	void MoveDown();
	void GetName(string name);
	void Draw(RenderWindow& window);
	int GetPressedItem() { return selectedItem; }
	
	bool menuState;
	bool userState;
	bool gameState;
	bool scoreState;
	bool aboutState;

private:
	Game game;
	Score score;
	About about;
	Song song;

	RectangleShape menubox;
	Texture menuTexture;
	int selectedItem = 0;
	Font fontMenu;
	Font fontMain;
	Font font;
	Text main;
	Text dev;
	Text menu[maxItem];

	RectangleShape bg;
	Texture bgTexture;
	Vector2f position;
	Vector2f size;
};

