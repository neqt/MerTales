#include "Game.h"

Game::Game() :
	player(Vector2u(3, 3), 100.f, 200.f), 
	enemy(Vector2u(3, 2), 1.f, 3.f)
{
	fontScore.loadFromFile("Fonts/editundo.ttf");
	point = 0;

	hpBar.setSize(Vector2f(300.f, 30.f));
	hpBar.setFillColor(Color::Cyan);
	hpBar.setPosition(Vector2f(35.f, 35.f));

	hpBarBack = hpBar;
	hpBarBack.setFillColor(Color(25, 25, 25, 200));
}

Game::~Game()
{
}

void Game::CoinCollision()
{
	for (size_t i = 0; i < 5; i++)
	{
		if (coin.shape[i].getGlobalBounds().intersects(player.body.getGlobalBounds()))
		{
			point += 10;
			coin.shape[i].setPosition(float(rand() % (1030 - 50 + 1) + 50), float(rand() % (600 - 300 + 1) + 300));
		}
	}
}

void Game::ItemCollision()
{
	//shield

	if (player.body.getGlobalBounds().intersects(item.shield.getGlobalBounds()))
	{
		item.shieldState = false;
		item.bubbleState = true;
		item.bubble.setPosition(player.body.getPosition().x / 2, player.body.getPosition().y / 2);
	}

	//heal
	if (player.body.getGlobalBounds().intersects(item.heal.getGlobalBounds()))
	{
		item.healState = false;
		player.hp += 10;
	}
}

void Game::SharkCollision()
{
	for (size_t i = 0; i < 2; i++)
	{
		if (player.body.getGlobalBounds().intersects(enemy.shark.getGlobalBounds()))
		{
			player.hp -= 10;
			if (enemy.shark.getPosition().x + 140.f > player.body.getPosition().x + 110.f)
			{
				player.body.setPosition(player.body.getPosition().x - 150.f, player.body.getPosition().y);
			}
			if (enemy.shark.getPosition().x + 175.f < player.body.getPosition().x)
			{
				player.body.setPosition(player.body.getPosition().x + 150.f, player.body.getPosition().y);
			}
		}
	}
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

void Game::HpUpdate()
{
	float hpPercent = static_cast<float>(player.hp / player.hpMax * 100);
	hpBar.setSize(Vector2f(300.f * hpPercent, hpBar.getSize().y));
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
	ScoreUpdate();
	CoinCollision();
	coin.Draw(window);
	window.draw(score);
	ItemCollision();
	HpUpdate();
	window.draw(hpBarBack);
	window.draw(hpBar);
	item.Draw(window);
	SharkCollision();
	enemy.Update();
	enemy.Draw(window);
	player.Update(deltaTime, enemy.GetBounds(), enemy.GetPosition());
	player.Draw(window);
}
