#include "Game.h"

Game::Game() :
	player(Vector2u(3, 3), 100.f, 200.f),
	enemy(Vector2u(3, 2), 1.f)
{
	font.loadFromFile("Fonts/editundo.ttf");
	point = 0;
	hp = 10;
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
	shieldTime = shieldClock.getElapsedTime().asSeconds();
	healTime = healClock.getElapsedTime().asSeconds();
	bonusTime = bonusClock.getElapsedTime().asSeconds();

	if (shieldTime > 30)
	{
		item.shieldState = true;
	}
	if (healTime > 60)
	{
		item.healState = true;
	}
	if (bonusTime > 45)
	{
		item.bonusState = true;
	}

	//shield //every 30 sec
	if (player.body.getGlobalBounds().intersects(item.shield.getGlobalBounds()) 
		&& Keyboard::isKeyPressed(Keyboard::Space)
		&& item.shieldState)
	{
		item.shieldState = false;
		item.bubbleState = true;
		shieldClock.restart();
	}
	item.bubble.setPosition(player.body.getPosition().x, player.body.getPosition().y);

	//heal //every 1 min
	if (player.body.getGlobalBounds().intersects(item.heal.getGlobalBounds()) 
		&& Keyboard::isKeyPressed(Keyboard::Space)
		&& item.healState)
	{
		item.healState = false;
		hp += 2;
		healClock.restart();
	}

	//bonus //every 45 sec
	if (player.body.getGlobalBounds().intersects(item.bonus.getGlobalBounds()) 
		&& Keyboard::isKeyPressed(Keyboard::Space)
		&& item.bonusState)
	{
		item.bonusState = false;
		point *= 2;
		bonusClock.restart();
	}
}

void Game::SharkCollision()
{
	if (item.bubbleState && player.body.getGlobalBounds().intersects(enemy.shark.getGlobalBounds()))
	{
		item.bubbleState = false;
		enemy.row = 0;
	}
	if (!item.bubbleState && player.body.getGlobalBounds().intersects(enemy.shark.getGlobalBounds()))
	{
		hp--;
		enemy.row = 0;
		if (enemy.shark.getPosition().x + 140.f > player.body.getPosition().x + 110.f)
		{
			player.body.setPosition(player.body.getPosition().x - 150.f, player.body.getPosition().y + 150.f);
		}
		if (enemy.shark.getPosition().x + 175.f < player.body.getPosition().x)
		{
			player.body.setPosition(player.body.getPosition().x + 150.f, player.body.getPosition().y + 150.f);
		}
	}
	enemy.row = 1;

}

void Game::ScoreUpdate()
{
	score.setFont(font);
	score.setFillColor(Color::Black);
	score.setCharacterSize(36);
	stringstream ss;
	ss << "Score : " << point;
	score.setString(ss.str());
	score.setPosition(Vector2f(35, 75));
}

void Game::HpUpdate()
{
	if (hp <= 10 && hp >= 0)
	{
		hpBar.setSize(Vector2f((float)hp * 30.f, 30.f));
	}
	else if (hp > 10)
	{
		hpBar.setSize(Vector2f(300.f, 30.f));
	}
	
	hpBar.setFillColor(Color::Cyan);
	hpBar.setPosition(Vector2f(35.f, 35.f));

	hpBarBase.setSize(Vector2f(300.f, 30.f));
	hpBarBase.setFillColor(Color(25, 25, 25, 200));
	hpBarBase.setPosition(Vector2f(35.f, 35.f));
}

void Game::SpeedUpdate()
{
	if (point > 100) { enemy.speed = 0.4f; }
	if (point > 200) { enemy.speed = 0.5f; }
	if (point > 300) { enemy.speed = 0.4f; }
	if (point > 200) { enemy.speed = 0.5f; }
}

void Game::DrawGameOver()
{
	overTexture.loadFromFile("Textures/gameover.png");
	overbox.setSize(Vector2f(810.f, 420.f));
	overbox.setOrigin(overbox.getGlobalBounds().width / 2, overbox.getGlobalBounds().height / 2);
	overbox.setPosition(540.f, 360.f);
	overbox.setTexture(&overTexture);

	gameOver.setFont(font);
	gameOver.setFillColor(Color::Black);
	gameOver.setCharacterSize(70);
	gameOver.setString("Game Over");
	gameOver.setOrigin(gameOver.getGlobalBounds().width / 2, gameOver.getGlobalBounds().height / 2);
	gameOver.setPosition(540.f, 250.f);
	
	yourScore.setFont(font);
	yourScore.setFillColor(Color::Black);
	yourScore.setCharacterSize(50);
	stringstream ss;
	ss << "Score " << point;
	yourScore.setString(ss.str());
	yourScore.setOrigin(yourScore.getGlobalBounds().width / 2, yourScore.getGlobalBounds().height / 2);
	yourScore.setPosition(540.f, 350.f);

	press.setFont(font);
	press.setFillColor(Color::Black);
	press.setCharacterSize(36);
	press.setString("Press right to go back to menu");
	press.setOrigin(press.getGlobalBounds().width / 2, press.getGlobalBounds().height / 2);
	press.setPosition(540.f, 450.f);
}

bool Game::GameOver()
{
	if (hp <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::Reset()
{
	hp = 10;
	point = 0;
}

void Game::Draw(RenderWindow& window)
{
	if (hp > 0)
	{
		background.Draw(window);
		ScoreUpdate();
		CoinCollision();
		coin.Draw(window);
		window.draw(score);
		ItemCollision();
		HpUpdate();
		window.draw(hpBarBase);
		window.draw(hpBar);
		item.Draw(window);
		babyshark.Draw(window);
		SharkCollision();
		enemy.Update();
		enemy.Draw(window);
		player.Update();
		player.Draw(window);
		SpeedUpdate();
	}
	else
	{
		background.Draw(window);
		window.draw(overbox);
		window.draw(gameOver);
		window.draw(yourScore);
		window.draw(press);
		DrawGameOver();
	}
}
