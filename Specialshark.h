#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Spcanimation.h"
using namespace sf;

class Specialshark
{
public:
	Specialshark(Vector2u imageCount, float switchTime);
	~Specialshark();

	void Update();
	void Draw(RenderWindow& window);

	IntRect uvRect;
	RectangleShape boss;
	unsigned int row;
	float speed;
	bool bossState;
	bool bossCheck;

private:
	Spcanimation spcanimation;
	Texture bossTexture;
	Clock clock;
	long double time;
	int animationFrame;
	bool faceRight;
	bool moveRight;
	int dir;

};

