#include "Specialshark.h"

int randBoss(int start, int stop) {
	int n = (rand() % (stop - start + 1)) + start;
	return int(n);
}

Specialshark::Specialshark(Vector2u imageCount, float switchTime) :
	spcanimation(imageCount, switchTime)
{
	speed = 0.2f;
	row = 1;
	faceRight = true;

	bossTexture.loadFromFile("Textures/shark11.png");
	boss.setTexture(&bossTexture);
	boss.setSize(Vector2f(140.f, 100.f));
	boss.setPosition(-50, randBoss(200, 600));
}

Specialshark::~Specialshark()
{
}

void Specialshark::Update()
{
	time = clock.getElapsedTime().asMilliseconds();

	if (faceRight)
	{
		boss.move(speed, 0.f);
		if (boss.getPosition().x > 1100)
		{
			boss.setPosition(boss.getPosition().x, randBoss(200, 600));
			faceRight = false;
		}
	}
	else
	{
		boss.move(-speed, 0.f);
		if (boss.getPosition().x < -250)
		{
			boss.setPosition(boss.getPosition().x, randBoss(200, 600));
			faceRight = true;
		}
	}

	spcanimation.Update(row, time, faceRight);
	boss.setTextureRect(spcanimation.uvRect);
}

void Specialshark::Draw(RenderWindow& window)
{
	window.draw(boss);
}
