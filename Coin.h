#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include "Player.h"
using namespace sf;
using namespace std;
#define maxHeart 5

class Coin
{
public:
	Coin();
	~Coin();

	void Spawn();
	void Update();
	void Draw(RenderWindow& window);
	
	IntRect uvRect;
	RectangleShape shape;

private:
	Clock clock;
	long double time;
	Texture coinTexture;
	bool eraseCoin;
	int point;
	int animationFrame;

};
