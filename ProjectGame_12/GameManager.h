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
	void PlayerMonsterAttack();
	void PlayerBossAttack();
	void MonsterAttack();
	void BossAttack();
	int GameOver();
	int getRound();
};