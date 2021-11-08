#define _CRT_SECURE_NO_WARNINGS
#include "Score.h"

Score::Score()
{
	font.loadFromFile("Fonts/editundo.ttf");
	Text ttext("Leaderboard", font, 80);
	main = ttext;
	main.setFillColor(Color::White);
	main.setOrigin(Vector2f(main.getGlobalBounds().width / 2, 0));
	main.setPosition(Vector2f(540, 50));
	for (int i = 0; i < 5; i++)
	{
		scores[i].setCharacterSize(40);
		scores[i].setFillColor(sf::Color::White);
		scores[i].setPosition(540, 200 + (i * 80));
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

void Score::Draw(RenderWindow& window)
{
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
}
