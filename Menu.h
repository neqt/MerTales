#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Score.h"
#include "About.h"

using namespace sf;
#define maxItem 4

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void MoveUp();
	void MoveDown();
	void UserName();
	void Draw(RenderWindow& window);
	int GetPressedItem() { return selectedItem; }
	
	bool userState = false;
	bool gameState = false;
	bool scoreState = false;
	bool aboutState = false;

private:
	Game game;
	Score score;
	About about;

	int selectedItem = 0;
	Font fontMenu;
	Font fontMain;
	Font font;
	Text main;
	Text dev;
	Text menu[maxItem];

	string userName;
	vector<char> name;
	Text user;

	RectangleShape bg;
	Texture bgTexture;
	Vector2f position;
	Vector2f size;
};

