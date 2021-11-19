#include "About.h"

About::About()
{
	bgTexture.loadFromFile("Textures/island2.jpg");
	bg.setTexture(&bgTexture);
	bg.setSize(Vector2f(1080, 720));
	bg.setPosition(0, 0);

	boxTexture.loadFromFile("Textures/airy.png");
	box.setTexture(&boxTexture);
	box.setSize(Vector2f(810, 470));
	box.setOrigin(Vector2f(box.getGlobalBounds().width / 2, box.getGlobalBounds().height / 2));
	box.setPosition(540, 390);

	fontMain.loadFromFile("Fonts/hachicro.ttf");
	main.setFont(fontMain);
	main.setFillColor(Color::Black);
	main.setCharacterSize(60);
	main.setString("How to Play");
	main.setOrigin(Vector2f(main.getGlobalBounds().width / 2, 0));
	main.setPosition(540, 45);

	font.loadFromFile("Fonts/editundo.ttf");
	back.setFont(font);
	back.setFillColor(Color::Black);
	back.setCharacterSize(36);
	back.setString("Press left to go back to menu");
	back.setPosition(490, 650);
	
	wasdTexture.loadFromFile("Textures/wasd.png");
	wasd.setTexture(&wasdTexture);
	wasd.setSize(Vector2f(180, 110));
	wasd.setPosition(280, 200);

	wasdText.setFont(font);
	wasdText.setFillColor(Color::Black);
	wasdText.setCharacterSize(40);
	wasdText.setString("Player Movement");
	wasdText.setPosition(220, 310);

	spaceTexture.loadFromFile("Textures/space.png");
	space.setTexture(&spaceTexture);
	space.setSize(Vector2f(180, 90));
	space.setPosition(635, 180);

	spaceText.setFont(font);
	spaceText.setFillColor(Color::Black);
	spaceText.setCharacterSize(40);
	spaceText.setString("Collect Item");
	spaceText.setPosition(610, 260);

	sharkTexture.loadFromFile("Textures/shark.png");
	shark.setTexture(&sharkTexture);
	shark.setTextureRect(IntRect((sharkTexture.getSize().x / 3) * 1, 0, sharkTexture.getSize().x / 3, sharkTexture.getSize().y / 2));
	shark.setSize(Vector2f(150, 90));
	shark.setPosition(200, 390);

	sharkText.setFont(font);
	sharkText.setFillColor(Color::Black);
	sharkText.setCharacterSize(40);
	sharkText.setString("hp -1");
	sharkText.setPosition(370, 410);

	coinTexture.loadFromFile("Textures/coins.png");
	coin.setTexture(&coinTexture);
	coin.setTextureRect(IntRect((coinTexture.getSize().x / 8) * 0, 0, coinTexture.getSize().x / 8, coinTexture.getSize().y));
	coin.setSize(Vector2f(70, 70));
	coin.setPosition(240, 520);

	coinText.setFont(font);
	coinText.setFillColor(Color::Black);
	coinText.setCharacterSize(40);
	coinText.setString("Score +10");
	coinText.setPosition(370, 525);

	shieldTexture.loadFromFile("Textures/shield.png");
	shield.setTexture(&shieldTexture);
	shield.setSize(Vector2f(60, 70));
	shield.setPosition(630, 350);

	shieldText.setFont(font);
	shieldText.setFillColor(Color::Black);
	shieldText.setCharacterSize(40);
	shieldText.setString("shield");
	shieldText.setPosition(720, 360);

	healTexture.loadFromFile("Textures/heal.png");
	heal.setTexture(&healTexture);
	heal.setSize(Vector2f(60, 70));
	heal.setPosition(630, 435);

	healText.setFont(font);
	healText.setFillColor(Color::Black);
	healText.setCharacterSize(40);
	healText.setString("hp +3");
	healText.setPosition(720, 445);

	bonusTexture.loadFromFile("Textures/bonus.png");
	bonus.setTexture(&bonusTexture);
	bonus.setSize(Vector2f(60, 70));
	bonus.setPosition(630, 520);

	bonusText.setFont(font);
	bonusText.setFillColor(Color::Black);
	bonusText.setCharacterSize(40);
	bonusText.setString("score +200");
	bonusText.setPosition(720, 525);
}

About::~About()
{
}

bool About::Back()
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void About::Draw(RenderWindow& window)
{
	window.draw(bg);
	window.draw(box);
	window.draw(main);
	window.draw(back);
	window.draw(wasd);
	window.draw(wasdText);
	window.draw(space);
	window.draw(spaceText);
	window.draw(shark);
	window.draw(sharkText);
	window.draw(coin);
	window.draw(coinText);
	window.draw(shield);
	window.draw(shieldText);
	window.draw(heal);
	window.draw(healText); 
	window.draw(bonus);
	window.draw(bonusText);
}
