#include "Coin.h"

Coin::Coin()
{
	point = 0;
	coinTexture.loadFromFile("Texture/coin.png");

	shape[0].setSize(Vector2f(30.f, 30.f));
	shape[0].setPosition(200.f, 500.f);
	shape[0].setTexture(&coinTexture);

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

	Spawn();
	/*
	if (!font.loadFromFile("Fonts/editundo.ttf"))
	{
		//handle error
	}
	
	score.setFont(font);
	score.setFillColor(Color::Black);
	score.setCharacterSize(36);
	//score.setString("Score : ");
	stringstream ss;
	ss << "Score : " << point;
	score.setString(ss.str());
	score.setPosition(Vector2f(35, 75));
	*/
}

Coin::~Coin()
{
}

void Coin::Spawn()
{
	for (size_t i = 0; i < 5; i++)
	{
		shape[i].setPosition(float(rand() % (1030 - 50 + 1) + 50), float(rand() % (600 - 300 + 1) + 300));
	}
}

void Coin::Update(FloatRect Collision)
{
	//eraseCoin = false;

	for (size_t i = 0; i < 5; i++)
	{
		if (shape[i].getGlobalBounds().intersects(Collision))
		{
			point += 10;
			std::cout << " " << point;

			shape[i].setPosition(float(rand() % (1030 - 50 + 1) + 50), float(rand() % (600 - 300 + 1) + 300));
			//eraseCoin = true;
		}
	}
}

void Coin::Draw(RenderWindow& window)
{
	for (size_t i = 0; i < 5; i++)
	{
		window.draw(shape[i]);
	}
	//window.draw(score);
}