#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace sf;
using namespace std;

class Score
{
public:
	Score();
	~Score();

	void ReadFile();
	void WriteFile();
	bool Back(RenderWindow& window);
	void Draw(RenderWindow& window);

	string playerName;
	int playerScore;
	Text back;

private:
	Font fontMain;
	Font fontMenu;
	Font fontBack;
	Text main, scores[5], top[5];
	FILE* fp;
	char temp[255];
	int i;
	string name[6];
	size_t score[6];

	vector<pair<int, string>> userScore;
	string getName;
	size_t getScore;

	RectangleShape bg;
	Texture bgTexture;
};