#include "GameManager.h"
#include "Monster.h"
#include "MonsterFactory.h"
#include "Boss_RedDragon.h"
#include "Player.h"
#include "Shop.h"
#include "Gold.h"

using namespace std;

GameManager::GameManager() : player(make_shared<Player>())
{
}

void GameManager::GameStart()
{
	cout << "======TOP Monster======\n";
	cout << "ĳ���� �̸� : \n";
	
	string nickname;
	cin >> nickname;

	player.lock()->setName(nickname);

	cout << player.lock()->getName() << "���� �����Ǿ����ϴ�!\n";
	cout << "HP / MaxHP : " << player.lock()->getHealth() << " / " << player.lock()->getmaxHP() << "���ݷ� : " << player.lock()->getAttack() << endl;
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
			if (monster->getHealth() > 0)
			{
				cout << "======My Turn======\n";
				cout << "�������ּ��� : \n";
				cout << "1. �����ϱ�\n";
				cout << "2. �κ��丮 ����\n";
				cin >> TrunChoice;

				switch (TrunChoice)
				{

				case 1:
					cout << player.lock()->getName() << "��(��)" << monster->getName() << "��(��) �����ߴ�!!\n";
					//monster->getHealth() -= Player::getinstance().getAttack();
					cout << player.lock()->getAttack() << "��ŭ �������� ������!!\n";
					break;

				case 2:
					//cout << " " << �κ��丮 << endl;
					cout << "� �������� ����Ͻðڽ��ϱ�? : \n";
					cout << "1. Hp����\n";
					cout << "2. Attack����\n";
					cout << "3. ���ư���\n";
					cout << "HP : " << player.lock()->getHealth() << "Attack : " << player.lock()->getAttack() << endl;
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

					case 3:
						cout << "���ư��ϴ�";
						break;
					}
					break;
				}
				cout << monster->getName() << "��(��)" << player.lock()->getName() << "��(��) �����ߴ�!!\n";
				//Player::getinstance().getHealth() -= monster->getAttack();
				cout << monster->getAttack() << "��ŭ �������� ������!!\n";
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
					break;

				case 2:
					Shop shop;
					//shop.buyItem(playerGold);
					break;
				}
				break;
			}
			else if (player.lock()->getHealth() <= 0)
			{
				cout << monster->getName() << "���� ���ߴ�...\n";
				GameOver();
			}
		}
		Round++;
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
			if (Boss.getHealth() > 0)
			{
				cout << "======My Turn======\n";
				cout << "�������ּ��� : \n";
				cout << "1. �����ϱ�\n";
				cout << "2. �κ��丮 ����\n";
				cin >> TrunChoice;

				switch (TrunChoice)
				{
				case 1:
					cout << player.lock()->getName() << "��(��)" << Boss.getName() << "��(��) �����ߴ�!!\n";
					//monster->getHealth() -= Player::getinstance().getAttack();
					cout << player.lock()->getAttack() << "��ŭ �������� ������!!\n";
					break;

				case 2:
					//cout << " " << �κ��丮 << endl;
					cout << "� �������� ����Ͻðڽ��ϱ�? : \n";
					cout << "1. Hp����\n";
					cout << "2. Attack����\n";
					cout << "3. ���ư���\n";
					cout << "HP : " << player.lock()->getHealth() << "Attack : " << player.lock()->getAttack() << endl;
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

					case 3:
						cout << "���ư��ϴ�";
						break;
					}
					break;
				}
				cout << Boss.getName() << "��(��)" << player.lock()->getName() << "��(��) �����ߴ�!!\n";
				//Boss.takeDamage(Player * p);
				cout << Boss.getAttack() << "��ŭ �������� ������!!\n";
			}
			else if (Boss.getHealth() <= 0)
			{
				cout << Boss.getName() << "��(��) óġ�ߴ�!!\n";
				GameOver();
			}
			else if (player.lock()->getHealth() <= 0)
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



