#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Animation
{
public:
	Animation(Vector2u imageCount, float switchTime);
	~Animation();

	void Update(int row, float deltaTime, bool faceRight);

	IntRect uvRect;

private:
	Vector2u imageCount;
	Vector2u currentImage;
	Texture sharkTexture;

	float totalTime;
	float switchTime;
};
