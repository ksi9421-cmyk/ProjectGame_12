#include "GameManager.h"
#include "Monster.h"
#include "MonsterFactory.h"
#include "Boss_RedDragon.h"
#include "Player.h"
#include "Shop.h"
#include "Gold.h"
#include <cstdlib>

using namespace std;



GameManager& GameManager::getinstance()
{
	static GameManager instance;
	return instance;
}

GameManager::GameManager() : player(make_shared<Player>()) , Round(1)
{
}

void GameManager::GameStart()
{
	cout << "======TOP Monster======\n";
	cout << "ĳ���� �̸� : ";
	
	string nickname;
	cin >> nickname;

	player->setName(nickname);

	cout << player->getName() << "���� �����Ǿ����ϴ�!\n";
	cout << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << "���ݷ� : " << player->getAttack() << endl;
}



void GameManager::MonsterRound()
{
	GameManager::getRound();
	auto monster = MonsterFactory::CreateRandomMonster();

	int TrunChoice = 0;
	int InvenChoice = 0;

		cout << "======" << Round << "�� Monster!!======\n";
		cout << "*****Monster ����!!*****\n";
		monster->roar();
		cout << "Monster HP : " << monster->getHealth() << "Monster Attack : " << monster->getAttack() << endl;

		while (player->getHealth() >0 && monster->getHealth() >0)
		{
			if (monster->getHealth() > 0)
			{
				MAKE_CHOICE1:
				cout << "======My Turn======\n";
				cout << "�������ּ��� : \n";
				cout << "1. �����ϱ�\n";
				cout << "2. �κ��丮 ����\n";
				cin >> TrunChoice;

				switch (TrunChoice)
				{
				case 1:
					cout << player->getName() << "��(��)" << monster->getName() << "��(��) �����߽��ϴ�!!\n";
					 monster->takeDamage(player->getAttack());
					cout << player->getAttack() << "��ŭ �������� �������ϴ�!!\n";
					break;

				case 2:
				MAKE_CHOICE2:

					player->openInventory();
					cout << "� �������� ����Ͻðڽ��ϱ�? : \n";
					cout << "1. Hp����\n";
					cout << "2. 50%����\n";
					cout << "3. ���ư���\n";
					cout << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << "���ݷ� : " << player->getAttack() << endl;
					cin >> InvenChoice;

					switch (InvenChoice)
					{
					case 1:
						if (player->useItem(EItemType::HealAmount))
						{
							cout << "HP�� �����Ǿ����ϴ�!\n";
							cout << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << "���ݷ� : " << player->getAttack() << endl;
						}
						else
						{
							cout << "HP ������ �����մϴ�.\n";
						}
						goto MAKE_CHOICE2;
						break;

					case 2:
						if (player->useItem(EItemType::HealRatio))
					    {
							cout << "Hp�� 50% �����Ǿ����ϴ�!\n";
							cout << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << "���ݷ� : " << player->getAttack() << endl;
						}
						else
						{
					    	cout << "Hp�� 50% ������ �����մϴ�.";
						}
						goto MAKE_CHOICE2;
						break;

					case 3:
						cout << "���ư��ϴ�";
						goto MAKE_CHOICE1;
						break;
					}
					break;
				}
				if (monster->getHealth() > 0)
				{
					cout << monster->getName() << "��(��)" << player->getName() << "��(��) �����߽��ϴ�!!\n";
					player->takeDamage(monster->getAttack());
					cout << monster->getAttack() << "��ŭ �������� �������ϴ�!!\n";
				}
				else
				{
					break;
				}
			}		
		}
		if (monster->getHealth() <= 0)
		{
			player->levelUp();
		}
		else if (player->getHealth() <= 0)
		{
			cout << monster->getName() << "���� ���߽��ϴ�...\n";
			GameOver();
		}
		Round++;
}

void GameManager::VisitShop()
{
	int NextChoice = 0;
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
		shop.buyItem();
		break;
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
					cout << player->getName() << "��(��)" << Boss.getName() << "��(��) �����߽��ϴ�!!\n";
					Boss.takeDamage(player->getAttack());
					cout << player->getAttack() << "��ŭ �������� �������ϴ�!!\n";
					break;

				case 2:
					player->openInventory();
					cout << "� �������� ����Ͻðڽ��ϱ�? : \n";
					cout << "1. Hp����\n";
					cout << "2. Attack����\n";
					cout << "3. ���ư���\n";
					cout << "HP : " << player->getHealth() << "Attack : " << player->getAttack() << endl;
					cin >> InvenChoice;

					switch (InvenChoice)
					{
					case 1:
						if (player->useItem(EItemType::HealAmount))
						{
							cout << "HP�� �����Ǿ����ϴ�!\n";
							cout << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << "���ݷ� : " << player->getAttack() << endl;
						}
						else
						{
							cout << "HP ������ �����մϴ�.\n";
						}
						break;

					case 2:
						if (player->useItem(EItemType::HealRatio))
						{
							cout << "Hp�� 50% �����Ǿ����ϴ�!\n";
							cout << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << "���ݷ� : " << player->getAttack() << endl;
						}
						else
						{
							cout << "Hp�� 50% ������ �����մϴ�.";
						}
						break;

					case 3:
						cout << "���ư��ϴ�";
						break;
					}
					break;
				}
				cout << Boss.getName() << "��(��)" << player->getName() << "��(��) �����߽��ϴ�!!\n";
				player->takeDamage(Boss.getAttack());
				cout << Boss.getAttack() << "��ŭ �������� �������ϴ�!!\n";
			}
			else if (Boss.getHealth() <= 0)
			{
				cout << Boss.getName() << "��(��) óġ�߽��ϴ�!!\n";
				GameOver();
			}
			else if (player->getHealth() <= 0)
			{
				cout << Boss.getName() << "���� ���߽��ϴ�...\n";
				GameOver();
			}
		}
	}
}


void GameManager::GameOver()
{
	cout << "���ӿ��� �й��Ͽ����ϴ�\n";
	return exit(0);
}
