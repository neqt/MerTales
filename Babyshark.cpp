#include "Babyshark.h"

int randBaby(int start, int stop) {
	int n = (rand() % (stop - start + 1)) + start;
	return int(n);
}

Babyshark::Babyshark(Vector2u imageCount, float switchTime) :
	babyanimation(imageCount, switchTime)
{
	speed = 0.2f;
	row = 1;
	faceRight = true;

	babyTexture.loadFromFile("Textures/sharkbaby.png");
	baby.setTexture(&babyTexture);
	baby.setSize(Vector2f(110.f, 80.f));
	baby.setPosition(1100, randBaby(200, 600));

}

Babyshark::~Babyshark()
{
}

void Babyshark::Update()
{
	time = clock.getElapsedTime().asMilliseconds();

	if (faceRight)
	{
		baby.move(speed, 0.f);
		if (baby.getPosition().x > 1100)
		{
			baby.setPosition(baby.getPosition().x, randBaby(200, 600));
			faceRight = false;
		}
	}
	else
	{
		baby.move(-speed, 0.f);
		if (baby.getPosition().x < -250)
		{
			baby.setPosition(baby.getPosition().x, randBaby(200, 600));
			faceRight = true;
		}
	}

	babyanimation.Update(row, time, faceRight);
	baby.setTextureRect(babyanimation.uvRect);
}

void Babyshark::Draw(RenderWindow& window)
{
	//if (babyState)
	//{
		window.draw(baby);
	//}
}
