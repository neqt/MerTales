#include "Game.h"

Game::Game() :
	player(Vector2u(3, 3), 100.f, 200.f), 
	enemy(Vector2u(3, 2), 0.1f, 1.f)
{
	deltaTime = clock.restart().asSeconds();

	fontScore.loadFromFile("Fonts/editundo.ttf");
	point = 0;
}

Game::~Game()
{
}

void Game::ScoreUpdate()
{
	score.setFont(fontScore);
	score.setFillColor(Color::Black);
	score.setCharacterSize(36);
	stringstream ss;
	ss << "Score : " << point;
	score.setString(ss.str());
	score.setPosition(Vector2f(35, 75));
}

void Game::CoinCollision()
{
	for (size_t i = 0; i < 5; i++)
	{
		if (coin.shape[i].getGlobalBounds().intersects(player.body.getGlobalBounds()))
		{
			point += 10;
			std::cout << " " << point;

			coin.shape[i].setPosition(float(rand() % (1030 - 50 + 1) + 50), float(rand() % (600 - 300 + 1) + 300));
		}
	}
}

void Game::SharkCollision()
{
	/*
	for (size_t i = 0; i < 5; i++)
	{
		eraseHeart = false;
		if (player.body.getGlobalBounds().intersects(enemy.shark.getGlobalBounds()))
		{
			if (shark.position.x + 140.f > body.getPosition().x + 110.f)
			{
				body.setPosition(body.getPosition().x - 150.f, body.getPosition().y);
				eraseHeart = true;
			}
			if (position.x + 175.f < body.getPosition().x)
			{
				body.setPosition(body.getPosition().x + 150.f, body.getPosition().y);
				eraseHeart = true;
			}
		}
		//return eraseHeart;
	}
	return eraseHeart;
	*/
}

void Game::Update()
{
}

void Game::GameOver()
{
}

void Game::Draw(RenderWindow& window)
{
	background.Draw(window);
	
	//coin.Update(player.GetBounds());
	coin.Draw(window);
	window.draw(score);
	ScoreUpdate();
	CoinCollision();

	enemy.Update(deltaTime);
	enemy.Draw(window);
	player.Update(deltaTime, enemy.GetBounds(), enemy.GetPosition());
	player.Collision(enemy.GetBounds(), enemy.GetPosition());
	player.Draw(window);
}
