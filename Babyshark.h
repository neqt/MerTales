#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Babyanimation.h"
using namespace sf;

class Babyshark
{
public:
	Babyshark(Vector2u imageCount, float switchTime);
	~Babyshark();

	void Update();
	void Reset();
	void Draw(RenderWindow& window);

	IntRect uvRect;
	RectangleShape baby;
	unsigned int row;
	float speed;
	bool babyState;
	bool babyCheck;

private:
	Babyanimation babyanimation;
	Texture babyTexture;
	Clock clock;
	float time;
	int animationFrame;
	bool faceRight;
	bool moveRight;

};

