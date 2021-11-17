#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemy.h"

using namespace sf;

class Player
{
public:
	Player(Vector2u imageCount, float switchTime, float speed);
	~Player();

	void Update();
	void Draw(RenderWindow& window);
	
	IntRect uvRect;
	//Vector2f GetPosition() { return body.getPosition(); }
	//FloatRect GetBounds() { return body.getGlobalBounds(); }
	
	RectangleShape body;

private:
	Texture playerTexture;
	Clock pclock;
	long double ptime;
	Clock clock;
	long double time;
	
	unsigned int row;
	float speed;
	int animationFrame;
};
