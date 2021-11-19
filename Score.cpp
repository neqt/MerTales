#define _CRT_SECURE_NO_WARNINGS
#include "Score.h"

Score::Score()
{
	bgTexture.loadFromFile("Textures/island2.jpg");
	bg.setSize(Vector2f(1080.f, 720.f));
	bg.setPosition(0.0f, 0.0f);
	bg.setTexture(&bgTexture);
	
	boxTexture.loadFromFile("Textures/airy.png");
	box.setTexture(&boxTexture);
	box.setSize(Vector2f(810, 470));
	box.setOrigin(Vector2f(box.getGlobalBounds().width / 2, box.getGlobalBounds().height / 2));
	box.setPosition(540, 390);

	fontMain.loadFromFile("Fonts/hachicro.ttf");
	main.setFont(fontMain);
	main.setFillColor(Color::Black);
	main.setCharacterSize(60);
	main.setString("Leaderboard");
	main.setOrigin(Vector2f(main.getGlobalBounds().width / 2, 0));
	main.setPosition(540, 45);
	
	font.loadFromFile("Fonts/editundo.ttf");
	back.setFont(font);
	back.setFillColor(Color::Black);
	back.setCharacterSize(36);
	back.setString("Press left to go back to menu");
	back.setPosition(490, 650);
	
	for (int i = 0; i < 5; i++)
	{
		scores[i].setCharacterSize(40);
		scores[i].setFillColor(sf::Color::Black);
		scores[i].setPosition(540, 210 + (i * 80));
		scores[i].setFont(font);
	}
	
}

Score::~Score()
{
}

void Score::ReadFile()
{
	fp = fopen("./score.txt", "r");
	for (int i = 0; i < 5; i++)
	{
		fscanf(fp, "%s", &temp);
		name[i] = temp;
		fscanf(fp, "%d", &score[i]);
		this->userScore.push_back(make_pair(score[i], name[i]));
	}
}

void Score::WriteFile()
{
	ReadFile();
	this->name[5] = playerName;
	this->score[5] = playerScore;
	this->userScore.push_back(make_pair(this->score[5], this->name[5]));
	sort(userScore.begin(), userScore.end());
	fp = fopen("./score.txt", "w");
	for (int i = 5; i > 0; i--)
	{

		strcpy(temp, userScore[i].second.c_str());
		fprintf(fp, "%s %d\n", temp, userScore[i].first);
	}

	for (int i = 0; i < 6; i++)
	{
		userScore.pop_back();
	}
	fclose(this->fp);
}

bool Score::Back()
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

void Score::Draw(RenderWindow& window)
{
	window.draw(bg);
	window.draw(box);
	stringstream ss[5];
	ReadFile();
	fclose(this->fp);
	for (int i = 0; i < 5; i++) 
	{
		ss[i] << userScore[i].second << "       " << userScore[i].first;
		scores[i].setString(ss[i].str());
		scores[i].setOrigin(sf::Vector2f(scores[i].getGlobalBounds().width / 2, 0));
		window.draw(scores[i]);
	}
	while (!userScore.empty())
	{
		userScore.pop_back();
	}

	window.draw(main);
	window.draw(back);
}
