#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Lastanimation
{
public:
	Lastanimation(Vector2u imageCount, float switchTime);
	~Lastanimation();

	void Update(int row, float time, bool faceRight);

	IntRect uvRect;

private:
	Vector2u imageCount;
	Vector2u currentImage;
	Texture lastTexture;

	float totalTime;
	float switchTime;
};

