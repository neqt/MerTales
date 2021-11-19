#pragma once
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;

class Song
{
public:
	Song();
	~Song();

	void Menu();
	void Choose();
	void Click();

	void Bounce();
	void Coin();
	void Shield();
	void Bubble();
	void Bonus();
	void Heal();
	void Gameover();

	bool menuSong;
	bool gameSong;

private:
	SoundBuffer menuBuffer;
	Sound menuSound;
	SoundBuffer chooseBuffer;
	Sound chooseSound;
	SoundBuffer clickBuffer;
	Sound clickSound;

	SoundBuffer bounceBuffer;
	Sound bounceSound;
	SoundBuffer coinBuffer;
	Sound coinSound;
	SoundBuffer shieldBuffer;
	Sound shieldSound;
	SoundBuffer bubbleBuffer;
	Sound bubbleSound;
	SoundBuffer bonusBuffer;
	Sound bonusSound;
	SoundBuffer healBuffer;
	Sound healSound;
	SoundBuffer gameoverBuffer;
	Sound gameoverSound;
};
