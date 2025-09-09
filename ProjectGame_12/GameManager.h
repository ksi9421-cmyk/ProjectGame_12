#pragma once

#include <iostream>
#include <string>
using namespace std;

class GameManager
{
private:
	static int Round;

	std::unique_ptr<Player> player;

	GameManager();

public : 
	void GameStart();
	void MonsterRound();
	void BossRound();
	int GameOver();
	static int getRound() { return Round; }
};