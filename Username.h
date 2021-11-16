#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include <vector>
using namespace sf;
using namespace std;

class Username
{
public:
	Username();
	~Username();

	bool Next();
	bool Back();
	void Draw(RenderWindow& window);
	Text enter;
	vector<char> name;

private:
	Event event;
	Font font;
	Texture userTexture;
	RectangleShape userbox;
	string userName;
	
	Text user;

	RectangleShape bg;
	Texture bgTexture;
};

