#include "GameManager.h"
#include "Monster.h"
#include "MonsterFactory.h"
#include "Boss_RedDragon.h"
#include "Player.h"
#include "Shop.h"
#include "Gold.h"

using namespace std;

void GameManager::GameStart()
{
	cout << "======TOP Monster======\n";
	cout << "ĳ���� �̸� : \n";
	
	string nickname;
	cin >> nickname;

	Player::getinstance().setName(nickname);

	cout << Player::getinstance().getName() << "���� �����Ǿ����ϴ�!\n";
	cout << "HP : " << Player::getinstance().getHealth() << "���ݷ� : " << Player::getinstance().getAttack() << endl;
}

int GameManager::Round = 1;

void GameManager::MonsterRound()
{
	GameManager::getRound();
	auto monster = MonsterFactory::CreateRandomMonster();

	int TrunChoice = 0;
	int InvenChoice = 0;

	if (Round <= 9)
	{
		cout << "======" << Round << "�� Monster!!======\n";
		cout << "*****Monster ����!!*****\n";
		monster->roar();
		cout << "Monster HP : " << monster->getHealth() << "Monster Attack : " << monster->getAttack() << endl;

		while (1)
		{
			if (monster->getHealth() >= 0)
			{
				cout << "======My Turn======\n";
				cout << "�������ּ��� : \n";
				cout << "1. �����ϱ�\n";
				cout << "2. �κ��丮 ����\n";
				cin >> TrunChoice;

				switch (TrunChoice)
				{
				case 1:
					cout << Player::getinstance().getName() << "��(��)" << monster->getName() << "��(��) �����ߴ�!!\n";
					//monster->getHealth() -= Player::getinstance().getAttack();
					cout << Player::getinstance().getAttack() << "��ŭ �������� ������!!\n";
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
					cout << "HP : " << Player::getinstance().getHealth() << "Attack : " << Player::getinstance().getAttack() << endl;
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
			else if (monster->getHealth() <= 0)
			{
				int NextChoice = 0;
				cout << monster->getName() << "��(��) óġ�ߴ�!!\n";
				cout << "���� ������ �Ѿ�ðڽ��ϱ�? : \n";
				cout << "1. ���� ��\n";
				cout << "2. ����\n";
				cin >> NextChoice;

				switch (NextChoice)
				{
				case 1:
					MonsterRound();
					break;

				case 2:
					Shop shop;
					//shop.buyItem(playerGold);
					break;
				}
			}
			cout << monster->getName() << "��(��)" << Player::getinstance().getName() << "��(��) �����ߴ�!!\n";
			//Player::getinstance().getHealth() -= monster->getAttack();
			cout << monster->getAttack() << "��ŭ �������� ������!!\n";
		}
		Round++;
	}

	if (Player::getinstance().getHealth() <= 0)
	{
		cout << monster->getName() << "���� ���ߴ�...\n";
		GameOver();
	}
}

void GameManager::BossRound()
{
	Boss_RedDragon Boss;
	int TrunChoice = 0;
	int InvenChoice = 0;

	if (Round == 10)
	{
		cout << "======" << Round << "�� Monster!!======\n";
		cout << "*****B.O.S.S!!!*****\n";
		Boss_RedDragon Boss;
		Boss.roar();
		cout << "Boss HP : " << Boss.getHealth() << "Boss Attack : " << Boss.getAttack() << endl;

		while (1)
		{
			if (Boss.getHealth() >= 0)
			{
				cout << "======My Turn======\n";
				cout << "�������ּ��� : \n";
				cout << "1. �����ϱ�\n";
				cout << "2. �κ��丮 ����\n";
				cin >> TrunChoice;

				switch (TrunChoice)
				{
				case 1:
					cout << Player::getinstance().getName() << "��(��)" << Boss.getName() << "��(��) �����ߴ�!!\n";
					//monster->getHealth() -= Player::getinstance().getAttack();
					cout << Player::getinstance().getAttack() << "��ŭ �������� ������!!\n";
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
					cout << "HP : " << Player::getinstance().getHealth() << "Attack : " << Player::getinstance().getAttack() << endl;
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
				cout << Boss.getName() << "��(��)" << Player::getinstance().getName() << "��(��) �����ߴ�!!\n";
				//Boss.takeDamage(Player * p);
				cout << Boss.getAttack() << "��ŭ �������� ������!!\n";
			}
			else if (Boss.getHealth() <= 0)
			{
				cout << Boss.getName() << "��(��) óġ�ߴ�!!\n";
				GameOver();
			}
			else if (Player::getinstance().getHealth() <= 0)
			{
				cout << Boss.getName() << "���� ���ߴ�...\n";
				GameOver();
			}
		}
	}
}



int GameManager::GameOver()
{
	cout << "���ӿ��� �й��Ͽ����ϴ�\n";
	exit(0);
}



