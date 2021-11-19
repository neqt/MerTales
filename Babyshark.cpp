#include "Babyshark.h"

int randBaby(int start, int stop) {
	int n = (rand() % (stop - start + 1)) + start;
	return int(n);
}

Babyshark::Babyshark()
{
	babyTexture.loadFromFile("Textures/shark9.png");
	baby.setTexture(&babyTexture);
	baby.setSize(Vector2f(90.f, 110.f));
	baby.setPosition(randBaby(0, 980), randBaby(200, 600));

	uvRect.width = babyTexture.getSize().x / 9;
	uvRect.height = babyTexture.getSize().y / 6;
	baby.setTextureRect(IntRect(0, 0, uvRect.width, uvRect.height));

	dir = randBaby(1, 6);
	speed = 0.3f;
}

Babyshark::~Babyshark()
{
}

void Babyshark::Update()
{
	time = clock.getElapsedTime().asMilliseconds();
	/*
	if (dir = 1) { baby.move(-speed, 0); }
	else if (dir = 2) { baby.move(speed, 0); }
	else if (dir = 3) { baby.move(0, -speed); }
	else if (dir = 4) { baby.move(0, speed); }
	else if (dir = 5) { baby.move(-speed, -speed); }
	else if (dir = 6) { baby.move(-speed, speed); }
	else if (dir = 7) { baby.move(speed, -speed); }
	else if (dir = 8) { baby.move(speed, speed); }
	*/
}

void Babyshark::Draw(RenderWindow& window)
{
	window.draw(baby);
}
