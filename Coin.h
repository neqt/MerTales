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
	void Update(FloatRect Collision);
	void Draw(RenderWindow& window);

	RectangleShape shape[5];

private:
	Texture coinTexture;
	bool eraseCoin;
	int point;
};
