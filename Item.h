#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Item
{
public:
	Item();
	~Item();

	void Spawn();
	void Update(FloatRect Collision);
	void Draw(RenderWindow& window);

private:

};

