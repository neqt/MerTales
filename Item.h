#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Item
{
public:
	Item();
	~Item();

	void Spawn();
	void Update();
	void Draw(RenderWindow& window);

	RectangleShape shield;
	RectangleShape bubble;
	RectangleShape heal;
	bool shieldState;
	bool bubbleState;
	bool healState;

private:
	Clock clock;
	float time;

	Texture shieldTexture;
	Texture bubbleTexture;
	Texture healTexture;
};

