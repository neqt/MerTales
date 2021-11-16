#include "Menu.h"

Menu::Menu(float width, float height)
{
	bgTexture.loadFromFile("Textures/island.jpg");
	bg.setSize(Vector2f(1080.f, 720.f));
	bg.setPosition(0.0f, 0.0f);
	bg.setTexture(&bgTexture);

	fontMain.loadFromFile("Fonts/RopaBilly.ttf"); //พู่กัน
	//fontMertales.loadFromFile("Fonts/light_pixel-7.ttf"); //ปากกา
	//fontMain.loadFromFile("Fonts/Fipps-Regular.otf");
	main.setFont(fontMain);
	main.setFillColor(Color::Black);
	main.setCharacterSize(185);
	main.setString("MerTales");
	main.setOrigin(main.getLocalBounds().width / 4, main.getLocalBounds().height / 8);
	main.setPosition(Vector2f(width / 4, 60));

	fontMenu.loadFromFile("Fonts/hachicro.ttf"); //พิกเซลกลมดอกไม้
	menu[0].setFont(fontMenu);
	menu[0].setFillColor(Color::Black);
	menu[0].setCharacterSize(48);
	menu[0].setString("Play");
	menu[0].setOrigin(menu[0].getLocalBounds().width / 1.75, menu[0].getLocalBounds().height / 2);
	menu[0].setPosition(Vector2f(width / 1.25, height / (maxItem + 1) * 1));

	menu[1].setFont(fontMenu);
	menu[1].setFillColor(Color::White);
	menu[1].setCharacterSize(28);
	menu[1].setString("Score");
	menu[1].setOrigin(menu[1].getLocalBounds().width / 1.75, menu[1].getLocalBounds().height / 2);
	menu[1].setPosition(Vector2f(width / 1.25, height / (maxItem + 1) * 2));

	menu[2].setFont(fontMenu);
	menu[2].setFillColor(Color::White);
	menu[2].setCharacterSize(28);
	menu[2].setString("About");
	menu[2].setOrigin(menu[2].getLocalBounds().width / 1.75, menu[2].getLocalBounds().height / 2);
	menu[2].setPosition(Vector2f(width / 1.25, height / (maxItem + 1) * 3));

	menu[3].setFont(fontMenu);
	menu[3].setFillColor(Color::White);
	menu[3].setCharacterSize(28);
	menu[3].setString("Exit");
	menu[3].setOrigin(menu[3].getLocalBounds().width / 1.75, menu[3].getLocalBounds().height / 2);
	menu[3].setPosition(Vector2f(width / 1.25, height / (maxItem + 1) * 4));

	font.loadFromFile("Fonts/editundo.ttf");
	dev.setFont(font);
	dev.setFillColor(Color::Black);
	dev.setCharacterSize(32);
	dev.setString("64011308 Supitcha  Pulsiri");
	dev.setOrigin(dev.getLocalBounds().width / 4, dev.getLocalBounds().height / 1.25);
	dev.setPosition(Vector2f(width / 4, height / 1.25));

	menuTexture.loadFromFile("Textures/mainmenu.png");
	menubox.setSize(Vector2f(350.f, 650.f));
	menubox.setOrigin(menubox.getLocalBounds().width / 1.75, menubox.getLocalBounds().height / 2);
	menubox.setPosition(Vector2f(width / 1.25, height / 2));
	menubox.setTexture(&menuTexture);

	menuState = true;
	userState = false;
	gameState = false;
	scoreState = false;
	aboutState = false;
}

Menu::~Menu()
{
}

void Menu::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		menu[selectedItem].setFillColor(Color::White);
		selectedItem--;
		menu[selectedItem].setFillColor(Color::Black);
	}
}

void Menu::MoveDown()
{
	if (selectedItem + 1 < maxItem)
	{
		menu[selectedItem].setFillColor(Color::White);
		selectedItem++;
		menu[selectedItem].setFillColor(Color::Black);
	}
}

void Menu::GetName(string name)
{
	score.playerName = name;
}

void Menu::Draw(RenderWindow& window)
{
	window.draw(bg);
	//window.draw(menubox);

	for (size_t i = 0; i < maxItem; i++)
	{
		window.draw(menu[i]);
	}

	if (menu[0].getFillColor() == Color::Black && Keyboard::isKeyPressed(Keyboard::Enter)) 
	{
		game.Reset();
		userState = true;
		menuState = false;/*
		if (username.name.size() != 0 && Keyboard::isKeyPressed(Keyboard::Right))
		{
			gameState = true;
			userState = false;
		}*/
	}
	if (menu[1].getFillColor() == Color::Black && Keyboard::isKeyPressed(Keyboard::Enter))
	{
		scoreState = true;
		menuState = false;
	}
	if (menu[2].getFillColor() == Color::Black && Keyboard::isKeyPressed(Keyboard::Enter))
	{
		aboutState = true;
		menuState = false;
	}
	if (menu[3].getFillColor() == Color::Black && Keyboard::isKeyPressed(Keyboard::Enter))
	{
		window.close();
	}

	window.draw(main);
	window.draw(dev);
}