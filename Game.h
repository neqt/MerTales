#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Background.h"
#include "Coin.h"
#include "Enemy.h"
#include "Animation.h"
#include "Item.h"
using namespace sf;
using namespace std;

class Game
{
public:
	Game();
	~Game();
	
	void CoinCollision();
	void ItemCollision();
	void SharkCollision();
	void ScoreUpdate();
	void HpUpdate();
	void DrawGameOver();
	bool GameOver();
	void Reset();
	void Draw(RenderWindow& window);

private:
	Event event;
	Font font;

	Player player;
	RectangleShape hpBar;
	RectangleShape hpBarBase;
	int hp;

	Coin coin;
	Text score;
	size_t point;

	Enemy enemy;
	
	Item item;

	Background background;

	RectangleShape bg;
	Texture bgTexture;

	Text gameOver;
	Texture overTexture;
	RectangleShape overbox;

	Texture userTexture;
	RectangleShape userbox;
	string userName;
	vector<char> name;
	Text user;

	float deltaTime = 0.0f;
	Clock clock;

};

