#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Animation.h"
using namespace sf;

class Enemy
{
public:
	Enemy(Vector2u imageCount, float switchTime);
	~Enemy();

	void Update();
	void Draw(RenderWindow& window);

	IntRect uvRect;
	RectangleShape shark;
	unsigned int row;
	float speed;
	bool bounce;

private:
	Animation animation;
	Texture sharkTexture;
	Clock clock;
	float time;
	bool faceRight;
	bool moveRight;
	
};
