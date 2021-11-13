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

	void Update(float deltaTime, FloatRect bounds, Vector2f position);
	void Draw(RenderWindow& window);
	
	IntRect uvRect;
	Vector2f GetPosition() { return body.getPosition(); }
	FloatRect GetBounds() { return body.getGlobalBounds(); }
	
	RectangleShape body;
	int hp, hpMax;

private:
	RectangleShape heart[5];
	Texture playerTexture;
	Texture playerHeart;
	Clock clock;
	long double time;
	unsigned int row;
	float speed;
	int animationFrame;
	bool eraseHeart;
};
