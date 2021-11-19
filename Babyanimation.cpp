#include "Babyanimation.h"

Babyanimation::Babyanimation(Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.f;
	currentImage.x = 0;

	sharkTexture.loadFromFile("Textures/sharkbaby.png");

	uvRect.width = sharkTexture.getSize().x / 3;
	uvRect.height = sharkTexture.getSize().y / 2;
}

Babyanimation::~Babyanimation()
{
}

void Babyanimation::Update(int row, float time, bool faceRight)
{
	currentImage.y = row;
	totalTime += time;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;

		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}

	uvRect.top = currentImage.y * uvRect.height;

	if (faceRight)
	{
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}
