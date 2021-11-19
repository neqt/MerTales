#include "Game.h"

int random(int start, int stop) {
	int n = (rand() % (stop - start + 1)) + start;
	return int(n);
}

Game::Game() :
	player(Vector2u(3, 3), 100.f, 200.f),
	enemy(Vector2u(3, 2), 0.5f),
	babyshark(Vector2u(3, 2), 1.f),
	specialshark(Vector2u(3, 2), 0.75f),
	lastshark(Vector2u(3, 2), 0.9f)
{
	font.loadFromFile("Fonts/editundo.ttf");
	
	quitTexture.loadFromFile("Textures/gamequit.png");
	quit.setTexture(&quitTexture);
	quit.setSize(Vector2f(100.f, 100.f));
	quit.setPosition(945.f, 35.f);

	point = 0;
	hp = 10;
	coinMax = 1;

}

Game::~Game()
{
}

void Game::CoinCollision()
{
	for (size_t i = 0; i < coinMax; i++)
	{
		if (coin[i].shape.getGlobalBounds().intersects(player.body.getGlobalBounds()))
		{
			song.Coin();
			point += 10;
			coin[i].shape.setPosition(float(rand() % (1030 - 50 + 1) + 50), float(rand() % (600 - 300 + 1) + 300));
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
		item.shield.setPosition(random(100, 940), random(200, 575));
	}
	if (healTime > 60)
	{
		item.healState = true;
		item.heal.setPosition(random(100, 940), random(200, 575));
	}
	if (bonusTime > 45)
	{
		item.bonusState = true;
		item.bonus.setPosition(random(100, 940), random(200, 575));
	}
	
	//shield //every 30 sec
	if (player.body.getGlobalBounds().intersects(item.shield.getGlobalBounds()) 
		&& Keyboard::isKeyPressed(Keyboard::Space)
		&& item.shieldState)
	{
		song.Shield();
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
		song.Heal();
		item.healState = false;
		hp += 2;
		healClock.restart();
	}

	//bonus //every 45 sec
	if (player.body.getGlobalBounds().intersects(item.bonus.getGlobalBounds()) 
		&& Keyboard::isKeyPressed(Keyboard::Space)
		&& item.bonusState)
	{
		song.Bonus();
		item.bonusState = false;
		point += 200;
		bonusClock.restart();
	}
}

void Game::SharkCollision()
{
	if (item.bubbleState == true && player.body.getGlobalBounds().intersects(enemy.shark.getGlobalBounds()) && sharkTime[0] > 1000)
	{
		song.Bubble();
		item.bubbleState = false;
		sharkClock[0].restart();
		enemy.row = 0;
		if (enemy.shark.getPosition().x + 140.f > player.body.getPosition().x + 110.f && enemy.shark.getPosition().y + 70.f > player.body.getPosition().y + 50.f)
		{
			enemy.bounce = false;
			player.body.setPosition(player.body.getPosition().x - 150.f, player.body.getPosition().y - 150.f);
		}
		if (enemy.shark.getPosition().x + 175.f < player.body.getPosition().x && enemy.shark.getPosition().y + 70.f > player.body.getPosition().y + 50.f)
		{
			enemy.bounce = true;
			player.body.setPosition(player.body.getPosition().x + 150.f, player.body.getPosition().y - 150.f);
		}
		if (enemy.shark.getPosition().x + 140.f > player.body.getPosition().x + 110.f && enemy.shark.getPosition().y + 70.f < player.body.getPosition().y + 50.f)
		{
			enemy.bounce = false;
			player.body.setPosition(player.body.getPosition().x - 150.f, player.body.getPosition().y + 150.f);
		}
		if (enemy.shark.getPosition().x + 175.f < player.body.getPosition().x && enemy.shark.getPosition().y + 70.f < player.body.getPosition().y + 50.f)
		{
			enemy.bounce = true;
			player.body.setPosition(player.body.getPosition().x + 150.f, player.body.getPosition().y + 150.f);
		}
	}
	else
	{
		enemy.row = 1;
	}
	if (item.bubbleState == false && player.body.getGlobalBounds().intersects(enemy.shark.getGlobalBounds()) && sharkTime[0] > 500)
	{
		song.Bounce();
		hp--;
		sharkClock[0].restart();
		enemy.row = 0;
		if (enemy.shark.getPosition().x + 140.f > player.body.getPosition().x + 110.f && enemy.shark.getPosition().y + 70.f > player.body.getPosition().y + 50.f)
		{
			enemy.bounce = false;
			player.body.setPosition(player.body.getPosition().x - 150.f, player.body.getPosition().y - 150.f);
		}
		if (enemy.shark.getPosition().x + 175.f < player.body.getPosition().x && enemy.shark.getPosition().y + 70.f > player.body.getPosition().y + 50.f)
		{
			enemy.bounce = true;
			player.body.setPosition(player.body.getPosition().x + 150.f, player.body.getPosition().y - 150.f);
		}
		if (enemy.shark.getPosition().x + 140.f > player.body.getPosition().x + 110.f && enemy.shark.getPosition().y + 70.f < player.body.getPosition().y + 50.f)
		{
			enemy.bounce = false;
			player.body.setPosition(player.body.getPosition().x - 150.f, player.body.getPosition().y + 150.f);
		}
		if (enemy.shark.getPosition().x + 175.f < player.body.getPosition().x && enemy.shark.getPosition().y + 70.f < player.body.getPosition().y + 50.f)
		{
			enemy.bounce = true;
			player.body.setPosition(player.body.getPosition().x + 150.f, player.body.getPosition().y + 150.f);
		}
		
	}
	else
	{
		enemy.row = 1;
	}

	if (player.body.getPosition().x < 0)
	{
		player.body.setPosition(0, player.body.getPosition().y);
	}
	if (player.body.getPosition().x > 950)
	{
		player.body.setPosition(950, player.body.getPosition().y);
	}
	if (player.body.getPosition().y < 200)
	{
		player.body.setPosition(player.body.getPosition().x, 200);
	}
	if (player.body.getPosition().y > 600)
	{
		player.body.setPosition(player.body.getPosition().x, 600);
	}
}

void Game::BabyCollision()
{
	if (item.bubbleState == true && player.body.getGlobalBounds().intersects(babyshark.baby.getGlobalBounds()) && sharkTime[1] > 1000)
	{
		song.Bubble();
		item.bubbleState = false;
		sharkClock[1].restart();
		if (babyshark.baby.getPosition().x + 45.f > player.body.getPosition().x + 110.f && babyshark.baby.getPosition().y + 50.f > player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x - 100.f, player.body.getPosition().y - 100.f);
		}
		if (babyshark.baby.getPosition().x + 75.f < player.body.getPosition().x && babyshark.baby.getPosition().y + 50.f > player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x + 100.f, player.body.getPosition().y - 100.f);
		}
		if (babyshark.baby.getPosition().x + 45.f > player.body.getPosition().x + 110.f && babyshark.baby.getPosition().y + 50.f < player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x - 100.f, player.body.getPosition().y + 100.f);
		}
		if (babyshark.baby.getPosition().x + 75.f < player.body.getPosition().x && babyshark.baby.getPosition().y + 50.f < player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x + 100.f, player.body.getPosition().y + 100.f);
		}
	}
	else
	{
		enemy.row = 1;
	}
	if (item.bubbleState == false && player.body.getGlobalBounds().intersects(babyshark.baby.getGlobalBounds()) && sharkTime[1] > 500)
	{
		song.Bounce();
		hp--;
		sharkClock[1].restart();
		if (babyshark.baby.getPosition().x + 75.f > player.body.getPosition().x + 110.f && babyshark.baby.getPosition().y + 35.f > player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x - 100.f, player.body.getPosition().y - 100.f);
		}
		if (babyshark.baby.getPosition().x + 75.f < player.body.getPosition().x && babyshark.baby.getPosition().y + 35.f > player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x + 100.f, player.body.getPosition().y - 100.f);
		}
		if (babyshark.baby.getPosition().x + 75.f > player.body.getPosition().x + 110.f && babyshark.baby.getPosition().y + 35.f < player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x - 100.f, player.body.getPosition().y + 100.f);
		}
		if (babyshark.baby.getPosition().x + 75.f < player.body.getPosition().x && babyshark.baby.getPosition().y + 35.f < player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x + 100.f, player.body.getPosition().y + 100.f);
		}
	}
	else
	{
		enemy.row = 1;
	}

	if (player.body.getPosition().x < 0)
	{
		player.body.setPosition(0, player.body.getPosition().y);
	}
	if (player.body.getPosition().x > 950)
	{
		player.body.setPosition(950, player.body.getPosition().y);
	}
	if (player.body.getPosition().y < 200)
	{
		player.body.setPosition(player.body.getPosition().x, 200);
	}
	if (player.body.getPosition().y > 600)
	{
		player.body.setPosition(player.body.getPosition().x, 600);
	}
}

void Game::BossCollision()
{
	if (item.bubbleState == true && player.body.getGlobalBounds().intersects(specialshark.boss.getGlobalBounds()) && sharkTime[2] > 1000)
	{
		song.Bubble();
		item.bubbleState = false;
		enemy.row = 0;
		sharkClock[2].restart();
		if (specialshark.boss.getPosition().x + 60.f > player.body.getPosition().x + 110.f && specialshark.boss.getPosition().y + 60.f > player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x - 125.f, player.body.getPosition().y - 125.f);
		}
		if (specialshark.boss.getPosition().x + 90.f < player.body.getPosition().x && specialshark.boss.getPosition().y + 60.f > player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x + 125.f, player.body.getPosition().y - 125.f);
		}
		if (specialshark.boss.getPosition().x + 60.f > player.body.getPosition().x + 110.f && specialshark.boss.getPosition().y + 60.f < player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x - 125.f, player.body.getPosition().y + 125.f);
		}
		if (specialshark.boss.getPosition().x + 90.f < player.body.getPosition().x && specialshark.boss.getPosition().y + 60.f < player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x + 125.f, player.body.getPosition().y + 125.f);
		}
	}
	else
	{
		enemy.row = 1;
	}
	if (item.bubbleState == false && player.body.getGlobalBounds().intersects(specialshark.boss.getGlobalBounds()) && sharkTime[2] > 500)
	{
		song.Bounce();
		hp--;
		enemy.row = 0;
		sharkClock[2].restart();
		if (specialshark.boss.getPosition().x + 60.f > player.body.getPosition().x + 110.f && specialshark.boss.getPosition().y + 60.f > player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x - 125.f, player.body.getPosition().y - 125.f);
		}
		if (specialshark.boss.getPosition().x + 90.f < player.body.getPosition().x && specialshark.boss.getPosition().y + 60.f > player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x + 125.f, player.body.getPosition().y - 125.f);
		}
		if (specialshark.boss.getPosition().x + 60.f > player.body.getPosition().x + 110.f && specialshark.boss.getPosition().y + 60.f < player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x - 125.f, player.body.getPosition().y + 125.f);
		}
		if (specialshark.boss.getPosition().x + 90.f < player.body.getPosition().x && specialshark.boss.getPosition().y + 60.f < player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x + 125.f, player.body.getPosition().y + 125.f);
		}
	}
	else
	{
		enemy.row = 1;
	}

	if (player.body.getPosition().x < 0)
	{
		player.body.setPosition(0, player.body.getPosition().y);
	}
	if (player.body.getPosition().x > 950)
	{
		player.body.setPosition(950, player.body.getPosition().y);
	}
	if (player.body.getPosition().y < 200)
	{
		player.body.setPosition(player.body.getPosition().x, 200);
	}
	if (player.body.getPosition().y > 600)
	{
		player.body.setPosition(player.body.getPosition().x, 600);
	}
}

void Game::LastCollision()
{
	if (item.bubbleState == true && player.body.getGlobalBounds().intersects(lastshark.last.getGlobalBounds()) && sharkTime[3] > 1000)
	{
		song.Bubble();
		item.bubbleState = false;
		enemy.row = 0;
		sharkClock[3].restart();
		if (lastshark.last.getPosition().x + 50.f > player.body.getPosition().x + 110.f && lastshark.last.getPosition().y + 55.f > player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x - 110.f, player.body.getPosition().y - 110.f);
		}
		if (lastshark.last.getPosition().x + 80.f < player.body.getPosition().x && lastshark.last.getPosition().y + 55.f > player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x + 110.f, player.body.getPosition().y - 110.f);
		}
		if (lastshark.last.getPosition().x + 50.f > player.body.getPosition().x + 110.f && lastshark.last.getPosition().y + 55.f < player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x - 110.f, player.body.getPosition().y + 110.f);
		}
		if (lastshark.last.getPosition().x + 80.f < player.body.getPosition().x && lastshark.last.getPosition().y + 55.f < player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x + 110.f, player.body.getPosition().y + 110.f);
		}
	}
	else
	{
		enemy.row = 1;
	}
	if (item.bubbleState == false && player.body.getGlobalBounds().intersects(lastshark.last.getGlobalBounds()) && sharkTime[1] > 500)
	{
		song.Bounce();
		hp--;
		enemy.row = 0;
		sharkClock[3].restart();
		if (lastshark.last.getPosition().x + 50.f > player.body.getPosition().x + 110.f && lastshark.last.getPosition().y + 55.f > player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x - 110.f, player.body.getPosition().y - 110.f);
		}
		if (lastshark.last.getPosition().x + 80.f < player.body.getPosition().x && lastshark.last.getPosition().y + 55.f > player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x + 110.f, player.body.getPosition().y - 110.f);
		}
		if (lastshark.last.getPosition().x + 50.f > player.body.getPosition().x + 110.f && lastshark.last.getPosition().y + 55.f < player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x - 110.f, player.body.getPosition().y + 110.f);
		}
		if (lastshark.last.getPosition().x + 80.f < player.body.getPosition().x && lastshark.last.getPosition().y + 55.f < player.body.getPosition().y + 50.f)
		{
			player.body.setPosition(player.body.getPosition().x + 110.f, player.body.getPosition().y + 110.f);
		}
	}
	else
	{
		enemy.row = 1;
	}

	if (player.body.getPosition().x < 0)
	{
		player.body.setPosition(0, player.body.getPosition().y);
	}
	if (player.body.getPosition().x > 950)
	{
		player.body.setPosition(950, player.body.getPosition().y);
	}
	if (player.body.getPosition().y < 200)
	{
		player.body.setPosition(player.body.getPosition().x, 200);
	}
	if (player.body.getPosition().y > 600)
	{
		player.body.setPosition(player.body.getPosition().x, 600);
	}
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

void Game::HarderUpdate()
{
	if (point >= 4600)
	{
		coinMax = 10;
		enemy.speed = 0.4f;
		babyshark.speed = 0.4f;
		specialshark.speed = 0.4f;
		lastshark.speed = 0.4f;
	}
	else if (point >= 3700)
	{
		coinMax = 10;
		enemy.speed = 0.4f;
		babyshark.speed = 0.4f;
		specialshark.speed = 0.4f;
		lastshark.speed = 0.3f;
	}
	else if (point >= 2900)
	{
		coinMax = 9;
		enemy.speed = 0.4f;
		babyshark.speed = 0.4f;
		specialshark.speed = 0.3f;
		lastshark.speed = 0.3f;
	}
	else if (point >= 2200)
	{
		coinMax = 8;
		enemy.speed = 0.3f;
		babyshark.speed = 0.4f;
		specialshark.speed = 0.3f;
		lastshark.speed = 0.3f;
	}
	else if (point >= 1600)
	{
		coinMax = 7;
		enemy.speed = 0.3f;
		babyshark.speed = 0.4f;
		specialshark.speed = 0.3f;
		lastshark.speed = 0.2f;
	}
	else if (point >= 1100)
	{
		coinMax = 6;
		enemy.speed = 0.3f;
		babyshark.speed = 0.4f;
		specialshark.speed = 0.3f;
		lastshark.speed = 0.2f;
	}
	else if (point >= 700)
	{
		coinMax = 5;
		enemy.speed = 0.3f;
		babyshark.speed = 0.3f;
		specialshark.speed = 0.3f;
		lastshark.speed = 0.2f;
	}
	else if (point >= 400)
	{
		coinMax = 4;
		enemy.speed = 0.3f;
		babyshark.speed = 0.3f;
		specialshark.speed = 0.2f;
		lastshark.speed = 0.2f;
	}
	else if (point >= 200)
	{
		coinMax = 3;
		enemy.speed = 0.3f;
		babyshark.speed = 0.3f;
		specialshark.speed = 0.2f;
		lastshark.speed = 0.2f;
	}
	else if (point >= 100)
	{
		coinMax = 2;
		enemy.speed = 0.2f;
		babyshark.speed = 0.3f;
		specialshark.speed = 0.2f;
		lastshark.speed = 0.2f;
	}
	else if (point >= 50)
	{
		coinMax = 1;
		enemy.speed = 0.2f;
		babyshark.speed = 0.2f;
		specialshark.speed = 0.2f;
		lastshark.speed = 0.2f;
	}
	else if (point >= 0)
	{
		coinMax = 1;
		enemy.speed = 0.2f;
		babyshark.speed = 0.2f;
		specialshark.speed = 0.2f;
		lastshark.speed = 0.2f;
	}
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
	player.body.setPosition(450.f, 300.f);
	enemy.shark.setPosition(-250, float(rand() % (460 - 260 + 1) + 260));
	babyshark.baby.setPosition(1100, 400);
	specialshark.boss.setPosition(-50, 600);
	lastshark.last.setPosition(1200, 500);
	enemy.speed = 0.2;
	babyshark.speed = 0.2;
	specialshark.speed = 0.2;
	lastshark.speed = 0.2;
	shieldClock.restart();
	healClock.restart();
	bonusClock.restart();
}

void Game::Draw(RenderWindow& window)
{
	if (hp > 0)
	{
		sharkTime[0] = sharkClock[0].getElapsedTime().asMilliseconds();
		sharkTime[1] = sharkClock[1].getElapsedTime().asMilliseconds();
		sharkTime[2] = sharkClock[2].getElapsedTime().asMilliseconds();
		sharkTime[3] = sharkClock[3].getElapsedTime().asMilliseconds();

		background.Draw(window);
		window.draw(quit);
		ScoreUpdate();
		CoinCollision();
		HarderUpdate();
		for (size_t i = 0; i < coinMax; i++)
		{
			coin[i].Update();
			coin[i].Draw(window);
		}
		window.draw(score);
		ItemCollision();
		HpUpdate();
		window.draw(hpBarBase);
		window.draw(hpBar);
		item.Draw(window);
		if (point >= 1600)
		{
			lastshark.Draw(window);
			lastshark.Update();
			LastCollision();
		}
		if (point >= 400)
		{
			specialshark.Draw(window);
			specialshark.Update();
			BossCollision();
		}
		if (point >= 50)
		{
			babyshark.Draw(window);
			babyshark.Update();
			BabyCollision();
		}
		enemy.Update();
		enemy.Draw(window);
		SharkCollision();
		player.Update();
		player.Draw(window);
		
		if (Keyboard::isKeyPressed(Keyboard::Q))
		{
			song.Gameover();
			hp = 0;
		}
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
