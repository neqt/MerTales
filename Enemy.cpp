#include "Enemy.h"

Enemy::Enemy(Vector2u imageCount, float switchTime) :
	animation(imageCount, switchTime)
{
	speed = 0.3f;
	row = 1;
	faceRight = true;

	sharkTexture.loadFromFile("Textures/shark5.png");

	shark.setSize(Vector2f(190.f, 120.f));
	shark.setTexture(&sharkTexture);
	Spawn();
}

Enemy::~Enemy()
{
}

void Enemy::Spawn()
{
	shark.setPosition(-250, float(rand() % (475 - 225 + 1) + 225));
}

void Enemy::Update()
{
	time = clock.getElapsedTime().asSeconds();
	if (faceRight)
	{
		shark.move(speed, 0.f);
		if (shark.getPosition().x > 1100)
		{
			shark.setPosition(shark.getPosition().x, float(rand() % (500 - 200 + 1) + 200));
			faceRight = false;
		}
	}
	else
	{
		shark.move(-speed, 0.f);
		if (shark.getPosition().x < -250)
		{
			shark.setPosition(shark.getPosition().x, float(rand() % (500 - 200 + 1) + 200));
			faceRight = true;
		}
	}

	animation.Update(row, time, faceRight);
	shark.setTextureRect(animation.uvRect);
}

void Enemy::Draw(RenderWindow& window)
{
	window.draw(shark);
}
