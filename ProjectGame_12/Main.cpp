#include "GameManager.h"


int main()
{

	GameManager::getinstance().GameStart();


	for (int i = 1; i <= 9; i++)
	{
		GameManager::getinstance().MonsterRound();
		GameManager::getinstance().VisitShop();
	}

	GameManager::getinstance().BossRound();

}