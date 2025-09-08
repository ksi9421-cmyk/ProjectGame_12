#pragma once

#include <iostream>
#include <string>
using namespace std;

class GameManager
{
private:
	static int Round;
	

public : 
	void GameStart();
	void NewRound();
	void PlayerTrun();
	void PlayerAttack();
	void MonsterAttack();
	void BossAttack();
	int GameOver();
	int getRound();
};