#include "Coin.h"

Coin::Coin()
{
	coinTexture.loadFromFile("Textures/coins.png");
	uvRect.width = coinTexture.getSize().x / 8;
	uvRect.height = coinTexture.getSize().y / 1;
	shape.setSize(Vector2f(30.f, 30.f));
	shape.setTexture(&coinTexture);

	animationFrame = 0;

	/*
	shape[1].setSize(Vector2f(30.f, 30.f));
	shape[1].setPosition(200.f, 500.f);
	shape[1].setTexture(&coinTexture);

	shape[2].setSize(Vector2f(30.f, 30.f));
	shape[2].setPosition(200.f, 500.f);
	shape[2].setTexture(&coinTexture);

	shape[3].setSize(Vector2f(30.f, 30.f));
	shape[3].setPosition(200.f, 500.f);
	shape[3].setTexture(&coinTexture);

	shape[4].setSize(Vector2f(30.f, 30.f));
	shape[4].setPosition(200.f, 500.f);
	shape[4].setTexture(&coinTexture);
	*/
	Spawn();
}

Coin::~Coin()
{
}

void Coin::Spawn()
{
	for (size_t i = 0; i < 5; i++)
	{
		shape.setPosition(float(rand() % (1030 - 50 + 1) + 50), float(rand() % (600 - 300 + 1) + 300));
	}
}

void Coin::Update()
{
	time = clock.getElapsedTime().asMilliseconds();
	if (time > 150)
	{
		animationFrame++;
		clock.restart();
	}
	if (animationFrame >= 8)
	{
		animationFrame = 0;
	}
	shape.setTextureRect(IntRect(uvRect.width * animationFrame, 0, uvRect.width, uvRect.height));

}

void Coin::Draw(RenderWindow& window)
{
	window.draw(shape);
}