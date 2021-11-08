#include "Menu.h"

Menu::Menu(float width, float height)
{
	bgTexture.loadFromFile("Texture/island.jpg");

	bg.setSize(Vector2f(1080.f, 720.f));
	bg.setPosition(0.0f, 0.0f);
	bg.setTexture(&bgTexture);

	//fontMertales.loadFromFile("Fonts/OliviaBloom.ttf"); //ปากกา
	fontMertales.loadFromFile("Fonts/RopaBilly.ttf"); //พู่กัน
	//fontMertales.loadFromFile("Fonts/light_pixel-7.ttf"); //ปากกา
	//fontMertales.loadFromFile("Fonts/Fipps-Regular.otf");

	mertales.setFont(fontMertales);
	mertales.setFillColor(Color::Black);
	//mertales.setCharacterSize(60);
	mertales.setCharacterSize(150);
	mertales.setString("MerTales");
	mertales.setOrigin(mertales.getLocalBounds().width / 4, mertales.getLocalBounds().height / 8);
	mertales.setPosition(Vector2f(width / 4, height / 8));

	fontDev.loadFromFile("Fonts/editundo.ttf");
	dev.setFont(fontDev);
	dev.setFillColor(Color::Black);
	dev.setCharacterSize(36);
	dev.setString("64011308 Supitcha  Pulsiri");
	dev.setOrigin(dev.getLocalBounds().width / 4, dev.getLocalBounds().height / 1.25);
	dev.setPosition(Vector2f(width / 4, height / 1.25));
	//font.loadFromFile("Fonts/light_pixel-7.ttf"); //พิกเซลกลม
	//font.loadFromFile("Font/Something Fishy.ttf"); //ปลา
	//font.loadFromFile("Font/ulove.ttf"); //คลื่นน้ำ
	//font.loadFromFile("Font/AMERIKA_.ttf"); //หอก
	//font.loadFromFile("Font/editundo.ttf"); //พิกเซล
	//font.loadFromFile("Fonts/Billo.ttf"); //ฟองน้ำ
	//font.loadFromFile("Fonts/Fipps-Regular.otf"); //ขอบพิกเซลเงา
	//font.loadFromFile("Fonts/CrunchyBeefOutli.ttf"); //ขอบพิกเซล
	//font.loadFromFile("Fonts/Edit Undo Line BRK.ttf"); //ขีดพิกเซล
	//font.loadFromFile("Fonts/Sabo-Regular.otf"); //พิกเซลขีด
	//font.loadFromFile("Fonts/outline_pixel-7.ttf"); //พิกเซลบาง
	font.loadFromFile("Fonts/hachicro.ttf"); //พิกเซลกลมดอกไม้

	menu[0].setFont(font);
	menu[0].setFillColor(Color::Black);
	menu[0].setCharacterSize(48);
	menu[0].setString("Play");
	menu[0].setOrigin(menu[0].getLocalBounds().width / 1.25, menu[0].getLocalBounds().height / 2);
	menu[0].setPosition(Vector2f(width / 1.25, height / (maxItem + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setCharacterSize(28);
	menu[1].setString("Score");
	menu[1].setOrigin(menu[1].getLocalBounds().width / 1.25, menu[1].getLocalBounds().height / 2);
	menu[1].setPosition(Vector2f(width / 1.25, height / (maxItem + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(Color::White);
	menu[2].setCharacterSize(28);
	menu[2].setString("About");
	menu[2].setOrigin(menu[2].getLocalBounds().width / 1.25, menu[2].getLocalBounds().height / 2);
	menu[2].setPosition(Vector2f(width / 1.25, height / (maxItem + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(Color::White);
	menu[3].setCharacterSize(28);
	menu[3].setString("Exit");
	menu[3].setOrigin(menu[3].getLocalBounds().width / 1.25, menu[3].getLocalBounds().height / 2);
	menu[3].setPosition(Vector2f(width / 1.25, height / (maxItem + 1) * 4));
}

Menu::~Menu()
{
}

void Menu::Draw(RenderWindow& window)
{
	window.draw(bg);
	for (size_t i = 0; i < maxItem; i++)
	{
		window.draw(menu[i]);
	}

	if (menu[0].getFillColor() == Color::Black && Keyboard::isKeyPressed(Keyboard::Enter)) 
	{
		gameState = true;
	}
	if (menu[1].getFillColor() == Color::Black && Keyboard::isKeyPressed(Keyboard::Enter))
	{
		scoreState = true;
	}
	if (menu[2].getFillColor() == Color::Black && Keyboard::isKeyPressed(Keyboard::Enter))
	{
		aboutState = true;
	}
	if (menu[3].getFillColor() == Color::Black && Keyboard::isKeyPressed(Keyboard::Enter))
	{
		window.close();
	}
	window.draw(mertales);
	window.draw(dev);
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
