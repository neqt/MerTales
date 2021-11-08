#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Background
{
public:
	Background();
	~Background();
	void Draw(RenderWindow& window);

private:
	RectangleShape bg;
	Texture bgTexture;
	Vector2f position;
	Vector2f size;
};
