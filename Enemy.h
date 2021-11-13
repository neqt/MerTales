#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Animation.h"
using namespace sf;

class Enemy
{
public:
	Enemy(Vector2u imageCount, float switchTime, float speed);
	~Enemy();

	void Spawn();
	void Update();
	void Draw(RenderWindow& window);

	IntRect uvRect;
	Vector2f GetPosition() { return shark.getPosition(); }
	FloatRect GetBounds() { return shark.getGlobalBounds(); }
	
	RectangleShape shark;

private:
	Animation animation;
	Texture sharkTexture;
	Clock clock;
	float time;
	unsigned int row;
	float speed;
	bool faceRight = true;
	bool moveRight;
	
	float spawnTimerMax;
	float spawnTimer;
	int maxEnemies;
	int viewX;
	int viewY;
};
