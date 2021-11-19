#include "Lastshark.h"

int randLast(int start, int stop) {
	int n = (rand() % (stop - start + 1)) + start;
	return int(n);
}

Lastshark::Lastshark(Vector2u imageCount, float switchTime) :
	lastanimation(imageCount, switchTime)
{
	speed = 0.2f;
	row = 1;
	faceRight = true;

	lastTexture.loadFromFile("Textures/shark10.png");
	last.setTexture(&lastTexture);
	last.setSize(Vector2f(125.f, 95.f));
	last.setPosition(1200, randLast(200, 600));
}

Lastshark::~Lastshark()
{
}

void Lastshark::Update()
{
	time = clock.getElapsedTime().asMilliseconds();

	if (faceRight)
	{
		last.move(speed, 0.f);
		if (last.getPosition().x > 1100)
		{
			last.setPosition(last.getPosition().x, randLast(200, 600));
			faceRight = false;
		}
	}
	else
	{
		last.move(-speed, 0.f);
		if (last.getPosition().x < -250)
		{
			last.setPosition(last.getPosition().x, randLast(200, 600));
			faceRight = true;
		}
	}

	lastanimation.Update(row, time, faceRight);
	last.setTextureRect(lastanimation.uvRect);
}

void Lastshark::Draw(RenderWindow& window)
{
	window.draw(last);
}
