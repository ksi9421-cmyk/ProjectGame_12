#include "GameManager.h"
#include<iostream>

using namespace std;

void GameManager::GameStart()
{
	cout << "======TOP Monster======\n";
	cout << "ĳ���� �̸� : \n";
	//cin >> PlayerName;
	//cout << PlayerName << "���� �����Ǿ����ϴ�!\n";
	//cout << "HP : " << player.gethp() << "���ݷ� : " << player.getattack() << endl;
}

void GameManager::NewRound()
{
	Round++;
	cout << "======" << Round << "�� Monster!!======\n";

	if (Round == 10)
	{
		cout << "*****B.O.S.S!!!*****\n";
		//����()
		// cout << "Boss HP : " << ����HP << "Boss Attack : " << ����Attack <<endl;
	}
	else
	{
		cout << "*****Monster ����!!*****\n";
		//���()
		// cout << "Monster HP : " << ����HP << "Monster Attack : " << ����Attack << endl;
	}
}

void GameManager::PlayerTrun()
{
	int TrunChoice = 0;
	int InvenChoice = 0;

	while (1)
	{
		cout << "======My Turn======\n";
		cout << "�������ּ��� : \n";
		cout << "1. �����ϱ�\n";
		cout << "2. �κ��丮 ����\n";
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
			//cout << " " << �κ��丮 << endl;
			cout << "� �������� ����Ͻðڽ��ϱ�? : \n";
			cout << "1. Hp����\n";
			cout << "2. Attack����\n";
			cout << "3. ���ư���\n";
			//cout << "HP : " << PlayerHp << "Attack : " << PlayerAttack << endl;
			cin >> InvenChoice;

			switch (InvenChoice)
			{
			case 1:
				//if (inventory.hppotion > 0)
				//{
				//	PlayerHp += HPpotion;
				//	cout << "HP�� �����Ǿ����ϴ�!\n";
				//	cout << "HP : " << PlayerHp << "Attack : " << PlayerAttack << endl;
				//}
				//else
				//{
				//	cout << "HP ������ �����մϴ�.\n"
				//}
				break;
			}

			switch (InvenChoice)
			{
			case 2:
				//if (inventory.Attackpotion > 0)
				//{
					//PlayerAttack += Attackpotion;
					//cout << "Attack�� �����Ǿ����ϴ�!\n";
					//cout << "HP : " << PlayerHp << "Attack : " << PlayerAttack << endl;
				//}
				//else
				//{
				//	cout << "Attack ������ �����մϴ�.";
				//}
				break;
			}

			switch (InvenChoice)
			{
			case 3:
				cout << "���ư��ϴ�";
				break;
			}
		}
	}
}

void GameManager::PlayerAttack()
{
	//cout << PlayerName << "��(��)" << monster.name << "��(��) �����ߴ�!!\n";
	//Monster.hp -= playerAttack;
	//cout << playerAttack << "��ŭ �������� ������!!\n";

	//if (Monster.hp <= 0)
	//{
	// cout << Monster.name << "��(��) óġ�ߴ�!!\n";
	//	NewRound();
	//}
	//else
	//{
	//	PlayerTrun();
	//}
}

void GameManager::MonsterAttack()
{
	//cout << monster.name << "��(��)" << Playername << "��(��) �����ߴ�!!\n";
	//Player.HP -= Monster.Attack;
	//cout << Monster.Attack << "��ŭ �������� ������!!\n";
	
	//if (Player.hp <= 0)
	//{
	// cout << Monster.name << "���� ���ߴ�...\n";
	//	���ӿ���();
	//}
}

void GameManager::BossAttack()
{
	//cout << monster.name << "��(��)" << Playername << "��(��) �����ߴ�!!\n";
	//Player.HP -= Monster.Attack;
	//cout << Monster.Attack << "��ŭ �������� ������!!\n";

	//if (Player.hp <= 0)
	//{
	// cout << Monster.name << "���� ���ߴ�...\n";
	//	���ӿ���();
	//}
}

void GameManager::OpenShop()
{
	int ShopChoice;

	cout << "=====����=====";
	//cout << "���� Gold : " << player.gold << endl;
	cout << "1. Hp 100 ȸ������ (10Gold)\n";
	cout << "2. Hp 50% ȸ������ (20Gold)\n";
	cout << "3. 30% �ִ� ü�� ��(80Gold)\n";
	cout << "4. 20% ���ݷ� ����(20Gold)\n";
	cout << "5. ���� ������\n";
	cin >> ShopChoice;

	switch (ShopChoice)
	{
	case 1:
		//if(player.gold >= 10)
		//{
			//inventory.HPpotion += Hp100potion;
			//cout << "Hp 100 ȸ�������� �����Ͽ����ϴ�.\n";
			//cout << "���� �κ��丮 : " << inventory.HPpotion << endl;
		//}
		//else
		//{
		//	cout << "��尡 �����մϴ�.\n";
		//}
		break;

	case 2:
		//if(player.gold >= 20)
		//{
			//inventory.HPpercentpotion += Hp50percentpotion;
			//cout << "Hp 50% ȸ�������� �����Ͽ����ϴ�.\n";
			//cout << "���� �κ��丮 : " << inventory.HPpercentpotion << endl;
		//}
		//else
		//{
		//	cout << "��尡 �����մϴ�.\n";
		//}

	case 3:
		//if(player.gold >= 80)
		//{
			//inventory.HPArmor += HPArmor
			//cout << "���� �����Ͽ����ϴ�.\n";
			//cout << "���� �κ��丮 : " << inventory.HPArmor << endl;
		//}
		//else
		//{
		//	cout << "��尡 �����մϴ�.\n";
		//}

	case 4:
		//if(player.gold >= 80)
		//{
			//inventory.Sword += Sword
			//cout << "���⸦ �����Ͽ����ϴ�.\n";
			//cout << "���� �κ��丮 : " << inventory.Sword << endl;
		//}
		//else
		//{
		//	cout << "��尡 �����մϴ�.\n";
		//}
	case 5:
		cout << "������ �����ϴ�.\n";
		break;
	}
}