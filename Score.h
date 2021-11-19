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
	bool Back();
	void Draw(RenderWindow& window);

	string playerName;
	int playerScore;
	Text back;

private:
	Font fontMain;
	Font font;
	Text main, names[5], scores[5];
	FILE* fp;
	char temp[255];
	int i;
	string name[6];
	size_t score[6];

	vector<pair<int, string>> userScore;
	string getName;
	size_t getScore;

	RectangleShape box;
	Texture boxTexture;
	RectangleShape bg;
	Texture bgTexture;
};