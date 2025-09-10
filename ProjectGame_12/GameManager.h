#pragma once

#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

class GameManager
{
private:
	static int Round;

	weak_ptr<Player> player;

	GameManager();

public:
	void GameStart();
	void MonsterRound();
	void VisitShop();
	void BossRound();
	int GameOver();
	static int getRound() { return Round; }
};