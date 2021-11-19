#include "Song.h"

Song::Song()
{
	menuBuffer.loadFromFile("Audio/menusong.wav");
	menuSound.setBuffer(menuBuffer);
	menuSound.setVolume(30);

	chooseBuffer.loadFromFile("Audio/choose.wav");
	chooseSound.setBuffer(chooseBuffer);
	chooseSound.setVolume(15);

	clickBuffer.loadFromFile("Audio/click.wav");
	clickSound.setBuffer(clickBuffer);
	clickSound.setVolume(20);

	gamestartBuffer.loadFromFile("Audio/gamestart.wav");
	gamestartSound.setBuffer(gamestartBuffer);
	gamestartSound.setVolume(30);

	gameBuffer.loadFromFile("Audio/gamesong.wav");
	gameSound.setBuffer(gameBuffer);
	gameSound.setVolume(30);

	bounceBuffer.loadFromFile("Audio/bounce.wav");
	bounceSound.setBuffer(bounceBuffer);
	bounceSound.setVolume(5);

	coinBuffer.loadFromFile("Audio/coin.wav");
	coinSound.setBuffer(coinBuffer);
	coinSound.setVolume(20);

	shieldBuffer.loadFromFile("Audio/shield.wav");
	shieldSound.setBuffer(shieldBuffer);
	shieldSound.setVolume(30);

	bubbleBuffer.loadFromFile("Audio/bubble.wav");
	bubbleSound.setBuffer(bubbleBuffer);
	bubbleSound.setVolume(30);

	bonusBuffer.loadFromFile("Audio/bonus.wav");
	bonusSound.setBuffer(bonusBuffer);
	bonusSound.setVolume(30);

	healBuffer.loadFromFile("Audio/heal.wav");
	healSound.setBuffer(healBuffer);
	healSound.setVolume(30);

	gameoverBuffer.loadFromFile("Audio/gameover.wav");
	gameoverSound.setBuffer(gameoverBuffer);
	gameoverSound.setVolume(60);

	menuSong = false;
	gameSong = false;
}

Song::~Song()
{
}

void Song::Menu()
{
	if (menuSound.getStatus() != Music::Status::Playing) 
	{
		menuSound.play();
	}
}

void Song::Choose()
{
	chooseSound.play();
}

void Song::Click()
{
	clickSound.play();
}

void Song::Gamestart()
{
	gamestartSound.play();
}

void Song::Game()
{
	if (gameSong == true && gameSound.getStatus() != Music::Status::Playing)
	{
		gameSound.play();
	}
	if (gameSong == false)
	{
		gameSound.stop();
	}
}

void Song::Bounce()
{
	bounceSound.play();
}

void Song::Coin()
{
	coinSound.play();
}

void Song::Shield()
{
	shieldSound.play();
}

void Song::Bubble()
{
	bubbleSound.play();
}

void Song::Bonus()
{
	bonusSound.play();
}

void Song::Heal()
{
	healSound.play();
}

void Song::Gameover()
{
	gameoverSound.play();
}
