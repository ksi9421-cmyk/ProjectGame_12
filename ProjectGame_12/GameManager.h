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
	shared_ptr<Bag> bag;

	GameManager();

public:
	void GameStart();
	void MonsterRound();
	void VisitShop();
	void BossRound();
	void GameOver();
	void GameWin();
	int getRound() { return Round; }

	static GameManager& getinstance();
};