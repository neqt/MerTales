#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Lastanimation.h"
using namespace sf;

class Lastshark
{
public:
	Lastshark(Vector2u imageCount, float switchTime);
	~Lastshark();

	void Update();
	void Draw(RenderWindow& window);

	IntRect uvRect;
	RectangleShape last;
	unsigned int row;
	float speed;

private:
	Lastanimation lastanimation;
	Texture lastTexture;
	Clock clock;
	long double time;
	int animationFrame;
	bool faceRight;
	bool moveRight;
};

