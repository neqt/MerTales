#include "Enemy.h"

Enemy::Enemy(Vector2u imageCount, float switchTime) :
	animation(imageCount, switchTime)
{
	speed = 0.2f;
	row = 1;
	faceRight = true;
	bounce = true;

	sharkTexture.loadFromFile("Textures/shark.png");

	shark.setSize(Vector2f(190.f, 120.f));
	shark.setTexture(&sharkTexture);
	shark.setPosition(-250, float(rand() % (550 - 250 + 1) + 250));
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	time = clock.getElapsedTime().asSeconds();
	if (faceRight)
	{
		shark.move(speed, 0.f);
		if (shark.getPosition().x > 1100)
		{
			shark.setPosition(shark.getPosition().x, float(rand() % (550 - 250 + 1) + 250));
			faceRight = false;
		}
		if (bounce)
		{
			shark.setPosition(shark.getPosition().x, shark.getPosition().y);
		}
	}
	else
	{
		shark.move(-speed, 0.f);
		if (shark.getPosition().x < -250)
		{
			shark.setPosition(shark.getPosition().x, float(rand() % (550 - 250 + 1) + 250));
			faceRight = true;
		}
		if (!bounce)
		{
			shark.setPosition(shark.getPosition().x, shark.getPosition().y);
		}
	}

	animation.Update(row, time, faceRight);
	shark.setTextureRect(animation.uvRect);
}

void Enemy::Draw(RenderWindow& window)
{
	window.draw(shark);
}
