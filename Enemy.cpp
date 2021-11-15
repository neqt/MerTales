#include "Enemy.h"

Enemy::Enemy(Vector2u imageCount, float switchTime, float speed) :
	animation(imageCount, switchTime)
{
	this->speed = speed;
	row = 1;
	faceRight = true;

	sharkTexture.loadFromFile("Textures/shark5.png");

	shark.setSize(Vector2f(200.f, 125.f));
	shark.setTexture(&sharkTexture);
	Spawn();
}

Enemy::~Enemy()
{
}

void Enemy::Spawn()
{
	shark.setPosition(-250, float(rand() % (500 - 200 + 1) + 200));
}

void Enemy::Update()
{
	time = clock.getElapsedTime().asSeconds();
	if (faceRight)
	{
		shark.move(0.5f, 0.f);
		if (shark.getPosition().x == 1100)
		{
			shark.setPosition(shark.getPosition().x, float(rand() % (500 - 200 + 1) + 200));
			faceRight = false;
		}
	}
	else
	{
		shark.move(-0.5f, 0.f);
		if (shark.getPosition().x == -250)
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
