#pragma once

#include <iostream>
#include <string>
using namespace std;

class GameManager
{
private:
	int Round = 0;
	

public : 
	
	void GameStart();
	void NewRound();
	void PlayerTrun();
	void PlayerAttack();
	void MonsterAttack();
	void BossAttack();
	void OpenShop();
};