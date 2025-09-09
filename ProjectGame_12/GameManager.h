#pragma once

#include <iostream>
#include <string>
using namespace std;

class GameManager
{
private:
	static int Round;

	std::weak_ptr<Player> player;

	GameManager();

public : 
	void GameStart();
	void NewRound();
	void MonsterBattle();
	void BossBttle();
	int GameOver();
	static int getRound() { return Round; }
};