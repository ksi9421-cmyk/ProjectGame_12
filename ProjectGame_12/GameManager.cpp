#include "GameManager.h"
#include<iostream>

using namespace std;

void GameManager::GameStart()
{
	cout << "======TOP Monster======\n";
	cout << "캐릭터 이름 : \n";
	//cin >> PlayerName;
	//cout << PlayerName << "으로 설정되었습니다!\n";
	//cout << "HP : " << player.gethp() << "공격력 : " << player.getattack() << endl;
}

void GameManager::NewRound()
{
	Round++;
	cout << "======" << Round << "층 Monster!!======\n";

	if (Round == 10)
	{
		cout << "*****B.O.S.S!!!*****\n";
		//보스()
		// cout << "Boss HP : " << 보스HP << "Boss Attack : " << 보스Attack <<endl;
	}
	else
	{
		cout << "*****Monster 등장!!*****\n";
		//잡몹()
		// cout << "Monster HP : " << 몬스터HP << "Monster Attack : " << 몬스터Attack << endl;
	}
}

void GameManager::PlayerTrun()
{
	int TrunChoice = 0;
	int InvenChoice = 0;

	while (1)
	{
		cout << "======My Turn======\n";
		cout << "선택해주세요 : \n";
		cout << "1. 공격하기\n";
		cout << "2. 인벤토리 열기\n";
		cin >> TrunChoice;

		switch (TrunChoice)
		{
		case 1:
			// //playerattack()
			break;
		}
		switch (TrunChoice)
		{
		case 2:
			//cout << " " << 인벤토리 << endl;
			cout << "어떤 아이템을 사용하시겠습니까? : \n";
			cout << "1. Hp물약\n";
			cout << "2. Attack물약\n";
			cout << "3. 돌아가기\n";
			//cout << "HP : " << PlayerHp << "Attack : " << PlayerAttack << endl;
			cin >> InvenChoice;

			switch (InvenChoice)
			{
			case 1:
				//if (inventory.hppotion > 0)
				//{
				//	PlayerHp += HPpotion;
				//	cout << "HP가 증가되었습니다!\n";
				//	cout << "HP : " << PlayerHp << "Attack : " << PlayerAttack << endl;
				//}
				//else
				//{
				//	cout << "HP 물약이 부족합니다.\n"
				//}
				break;
			}

			switch (InvenChoice)
			{
			case 2:
				//if (inventory.Attackpotion > 0)
				//{
					//PlayerAttack += Attackpotion;
					//cout << "Attack이 증가되었습니다!\n";
					//cout << "HP : " << PlayerHp << "Attack : " << PlayerAttack << endl;
				//}
				//else
				//{
				//	cout << "Attack 물약이 부족합니다.";
				//}
				break;
			}

			switch (InvenChoice)
			{
			case 3:
				cout << "돌아갑니다";
				break;
			}
		}
	}
}

void GameManager::PlayerAttack()
{
	//cout << PlayerName << "이(가)" << monster.name << "을(를) 공격했다!!\n";
	//Monster.hp -= playerAttack;
	//cout << playerAttack << "만큼 데미지를 입혔다!!\n";

	//if (Monster.hp <= 0)
	//{
	// cout << Monster.name << "을(를) 처치했다!!\n";
	//	NewRound();
	//}
	//else
	//{
	//	PlayerTrun();
	//}
}

void GameManager::MonsterAttack()
{
	//cout << monster.name << "이(가)" << Playername << "을(를) 공격했다!!\n";
	//Player.HP -= Monster.Attack;
	//cout << Monster.Attack << "만큼 데미지를 입혔다!!\n";
	
	//if (Player.hp <= 0)
	//{
	// cout << Monster.name << "에게 당했다...\n";
	//	게임오버();
	//}
}

void GameManager::BossAttack()
{
	//cout << monster.name << "이(가)" << Playername << "을(를) 공격했다!!\n";
	//Player.HP -= Monster.Attack;
	//cout << Monster.Attack << "만큼 데미지를 입혔다!!\n";

	//if (Player.hp <= 0)
	//{
	// cout << Monster.name << "에게 당했다...\n";
	//	게임오버();
	//}
}

void GameManager::OpenShop()
{
	int ShopChoice;

	cout << "=====상점=====";
	//cout << "현재 Gold : " << player.gold << endl;
	cout << "1. Hp 100 회복물약 (10Gold)\n";
	cout << "2. Hp 50% 회복물약 (20Gold)\n";
	cout << "3. 30% 최대 체력 방어구(80Gold)\n";
	cout << "4. 20% 공격력 무기(20Gold)\n";
	cout << "5. 상점 나가기\n";
	cin >> ShopChoice;

	switch (ShopChoice)
	{
	case 1:
		//if(player.gold >= 10)
		//{
			//inventory.HPpotion += Hp100potion;
			//cout << "Hp 100 회복물약을 구매하였습니다.\n";
			//cout << "현재 인벤토리 : " << inventory.HPpotion << endl;
		//}
		//else
		//{
		//	cout << "골드가 부족합니다.\n";
		//}
		break;

	case 2:
		//if(player.gold >= 20)
		//{
			//inventory.HPpercentpotion += Hp50percentpotion;
			//cout << "Hp 50% 회복물약을 구매하였습니다.\n";
			//cout << "현재 인벤토리 : " << inventory.HPpercentpotion << endl;
		//}
		//else
		//{
		//	cout << "골드가 부족합니다.\n";
		//}

	case 3:
		//if(player.gold >= 80)
		//{
			//inventory.HPArmor += HPArmor
			//cout << "방어구를 구매하였습니다.\n";
			//cout << "현재 인벤토리 : " << inventory.HPArmor << endl;
		//}
		//else
		//{
		//	cout << "골드가 부족합니다.\n";
		//}

	case 4:
		//if(player.gold >= 80)
		//{
			//inventory.Sword += Sword
			//cout << "무기를 구매하였습니다.\n";
			//cout << "현재 인벤토리 : " << inventory.Sword << endl;
		//}
		//else
		//{
		//	cout << "골드가 부족합니다.\n";
		//}
	case 5:
		cout << "상점을 나갑니다.\n";
		break;
	}
}