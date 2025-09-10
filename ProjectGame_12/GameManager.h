#pragma once

#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

class GameManager
{
private:
	int Round;

	shared_ptr<Player> player;

	GameManager();

public:
	void GameStart();
	void MonsterRound();
	void VisitShop();
	void BossRound();
	int GameOver();
	int getRound() { return Round; }

	static GameManager& getinstance();
};