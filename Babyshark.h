#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Babyshark
{
public:
	Babyshark();
	~Babyshark();

	void Update();
	void Draw(RenderWindow& window);

	IntRect uvRect;
	RectangleShape baby;

private:
	Texture babyTexture;
	Clock clock;
	long double time;

	unsigned int row;
	bool faceRight = true;
	bool moveRight;
	int dir;
	float speed;
};

