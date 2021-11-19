#include "Specialshark.h"

int randBoss(int start, int stop) {
	int n = (rand() % (stop - start + 1)) + start;
	return int(n);
}

Specialshark::Specialshark(Vector2u imageCount, float switchTime) :
	spcanimation(imageCount, switchTime)
{
	dir = randBoss(1, 6);
	speed = 0.3f;
	row = 1;
	faceRight = true;
	bossState = false;
	bossCheck = false;

	bossTexture.loadFromFile("Textures/shark11.png");
	boss.setTexture(&bossTexture);
	boss.setSize(Vector2f(140.f, 100.f));
	boss.setPosition(randBoss(0, 980), randBoss(200, 600));
}

Specialshark::~Specialshark()
{
}

void Specialshark::Update()
{
	time = clock.getElapsedTime().asMilliseconds();
	/*
	if (dir = 1) { baby.move(-speed, 0); }
	else if (dir = 2) { baby.move(speed, 0); }
	else if (dir = 5) { baby.move(-speed, -speed); }
	else if (dir = 6) { baby.move(-speed, speed); }
	else if (dir = 7) { baby.move(speed, -speed); }
	else if (dir = 8) { baby.move(speed, speed); }
	*/

	if (faceRight)
	{
		boss.move(speed, 0.f);
		if (boss.getPosition().x > 1100)
		{
			boss.setPosition(boss.getPosition().x, randBoss(200, 500));
			faceRight = false;
		}
	}
	else
	{
		boss.move(-speed, 0.f);
		if (boss.getPosition().x < -250)
		{
			boss.setPosition(boss.getPosition().x, randBoss(200, 500));
			faceRight = true;
		}
	}

	spcanimation.Update(row, time, faceRight);
	boss.setTextureRect(spcanimation.uvRect);

	/*
	if (time > 200)
	{
		animationFrame++;
		clock.restart();
	}
	if (animationFrame >= 3)
	{
		animationFrame = 0;
	}
	if (bossCheck)
	{
		row = 0;
	}
	else
	{
		row = 1;
	}
	boss.setTextureRect(IntRect(uvRect.width * animationFrame, uvRect.height * row, uvRect.width, uvRect.height));
	*/
}

void Specialshark::Draw(RenderWindow& window)
{
	window.draw(boss);
}
