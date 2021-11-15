#include "Player.h"

Player::Player(Vector2u imageCount, float switchTime, float speed)
{
	this->speed = speed;
	row = 0;

	playerTexture.loadFromFile("Textures/merman.png");
	body.setTexture(&playerTexture);
	body.setSize(Vector2f(120.f, 100.f));
	//body.setSize(Vector2f(90.f, 100.f));
	body.setPosition(450.f, 300.f);
	uvRect.width = playerTexture.getSize().x / 3;
	uvRect.height = playerTexture.getSize().y / 4;
	body.setTextureRect(sf::IntRect(0, 0, uvRect.width, uvRect.height));

	animationFrame = 0;

	playerHeart.loadFromFile("Textures/heart.png");
	heart[0].setTexture(&playerHeart);
	heart[0].setSize(Vector2f(40.f, 40.f));
	heart[0].setPosition(30.f, 30.f);

	heart[1].setTexture(&playerHeart);
	heart[1].setSize(Vector2f(40.f, 40.f));
	heart[1].setPosition(80.f, 30.f);

	heart[2].setTexture(&playerHeart);
	heart[2].setSize(Vector2f(40.f, 40.f));
	heart[2].setPosition(130.f, 30.f);

	heart[3].setTexture(&playerHeart);
	heart[3].setSize(Vector2f(40.f, 40.f));
	heart[3].setPosition(180.f, 30.f);

	heart[4].setTexture(&playerHeart);
	heart[4].setSize(Vector2f(40.f, 40.f));
	heart[4].setPosition(230.f, 30.f);
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	time = clock.getElapsedTime().asMilliseconds();
	Vector2f movement(0.0f, 0.0f);

	if (Keyboard::isKeyPressed(Keyboard::A) && body.getPosition().x > 0)
	{
		body.move(-0.3f, 0.f);
		//movement.x -= speed * deltaTime;
		body.setTextureRect(IntRect(uvRect.width * animationFrame, uvRect.height * 1, uvRect.width, uvRect.height));
	}
	if (Keyboard::isKeyPressed(Keyboard::D) && body.getPosition().x < 950)
	{
		body.move(0.3f, 0.f);
		//movement.x += speed * deltaTime;
		body.setTextureRect(IntRect(uvRect.width * animationFrame, uvRect.height * 2, uvRect.width, uvRect.height));
	}
	if (sf::Keyboard::isKeyPressed(Keyboard::W) && body.getPosition().y > 200)
	{
		body.move(0.f, -0.3f);
		//movement.y -= speed * deltaTime;
		body.setTextureRect(IntRect(uvRect.width * animationFrame, uvRect.height * 3, uvRect.width, uvRect.height));
	}
	if (sf::Keyboard::isKeyPressed(Keyboard::S) && body.getPosition().y < 600)
	{
		//movement.y += speed * deltaTime;
		body.move(0.f, 0.3f);
		body.setTextureRect(IntRect(uvRect.width * animationFrame, uvRect.height * 0, uvRect.width, uvRect.height));
	}
	if (time > 100)
	{
		animationFrame++;
		clock.restart();
	}

	if (animationFrame >= 3)
	{
		animationFrame = 0;
	}

	body.move(movement);
	
}

void Player::Draw(RenderWindow& window)
{
	window.draw(body);
	for (size_t i = 0; i < 5; i++)
	{
		if (!eraseHeart)
		{
			window.draw(heart[i]);
		}
		else
		{
			//undraw heart
		}
	}
}
