#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Background.h"
#include "Coin.h"
#include "Enemy.h"
#include "Animation.h"
using namespace sf;
using namespace std;

class Game
{
public:
	Game();
	~Game();
	void ScoreUpdate();
	void CoinCollision();
	void SharkCollision();
	void Update();
	void GameOver();
	void Draw(RenderWindow& window);

private:
	Player player;
	
	Font fontScore;
	Text score;
	size_t point;
	
	Coin coin;

	Enemy enemy;
	
	Background background;

	float deltaTime = 0.0f;
	Clock clock;

};

