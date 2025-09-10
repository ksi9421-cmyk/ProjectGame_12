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
	cout << "======TOP Monster======\n\n";
	cout << "ĳ���� �̸� : ";
	
	string nickname;
	cin >> nickname;

	player->setName(nickname);

	cout << player->getName() << "���� �����Ǿ����ϴ�!\n\n";
	cout << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
	cout << "���ݷ� : " << player->getAttack() << endl;
}



void GameManager::MonsterRound()
{
	GameManager::getRound();
	auto monster = MonsterFactory::CreateRandomMonster();

	int TrunChoice = 0;
	int InvenChoice = 0;

		cout << "======" << Round << "�� Monster!!======\n\n";
		cout << "*****Monster ����!!*****\n\n";
		monster->roar();
		cout << "Monster HP : " << monster->getHealth() << " / Monster Attack : " << monster->getAttack() << endl;

		while (player->getHealth() >0 && monster->getHealth() >0)
		{
			if (monster->getHealth() > 0)
			{
				MAKE_CHOICE1:
				cout << "======My Turn======\n\n";
				cout << "1. �����ϱ�\n";
				cout << "2. �κ��丮 ����\n";
				cout << "�������ּ��� : ";
				cin >> TrunChoice;

				switch (TrunChoice)
				{
				case 1:
					cout << "======My Attack======\n\n";
					cout << player->getName() << "��(��)" << monster->getName() << "��(��) �����߽��ϴ�!!\n\n";
					cout << player->getAttack() << "��ŭ ���� �߽��ϴ�!!\n\n";
					monster->takeDamage(player->getAttack());
					cout << "========================\n\n";
					cout << "Monster HP : " << monster->getHealth() << " / Monster Attack : " << monster->getAttack() << endl;
					break;

				case 2:
				MAKE_CHOICE2:

					player->openInventory();
					cout << "======Use Item======\n\n";
					cout << " " << player->getName() << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
					cout << "���ݷ� : " << player->getAttack() << endl;
					cout << "========================\n\n";
					cout << "1. Hp����\n\n";
					cout << "2. 50%����\n\n";
					cout << "3. ���ư���\n\n";
					cout << "� �������� ����Ͻðڽ��ϱ�? : ";
					cin >> InvenChoice;

					switch (InvenChoice)
					{
					case 1:
						if (player->useItem(EItemType::HealAmount))
						{
							cout << "======Hp 100 Potion Use======\n\n";
							cout << "HP�� �����Ǿ����ϴ�!\n\n";
							cout << " " << player->getName() << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
							cout << "���ݷ� : " << player->getAttack() << endl;
						}
						else
						{
							cout << "========================\n\n";
							cout << "HP ������ �����մϴ�.\n\n";
							goto MAKE_CHOICE2;
						}
						break;
						

					case 2:
						if (player->useItem(EItemType::HealRatio))
					    {
							cout << "======Hp 50% Potion Use======\n\n";
							cout << "Hp�� 50% �����Ǿ����ϴ�!\n\n";
							cout << " " << player->getName() << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
							cout << "���ݷ� : " << player->getAttack() << endl;
						}
						else
						{
							cout << "========================\n\n";
					    	cout << "Hp�� 50% ������ �����մϴ�.\n\n";
							goto MAKE_CHOICE2;
						}
						break;
						
					case 3:
						cout << "========================\n\n";
						cout << "���ư��ϴ�\n\n";
						goto MAKE_CHOICE1;
					}
					break;
				}
				if (monster->getHealth() > 0)
				{
					cout << "======Monster Trun======\n\n";
					cout << monster->getName() << "��(��)" << player->getName() << "��(��) �����߽��ϴ�!!\n\n";
					cout << monster->getAttack() << "��ŭ ���� ���߽��ϴ�!!\n\n";
					player->takeDamage(monster->getAttack());
					cout << "========================\n\n";
					cout << " " << player->getName() << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
					cout << "���ݷ� : " << player->getAttack() << endl;
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
			//���� item, �÷��̾� exp
		}
		else if (player->getHealth() <= 0)
		{
			cout << monster->getName() << "���� ���߽��ϴ�...\n\n";
			GameOver();
		}
		Round++;
}

void GameManager::VisitShop()
{
	int NextChoice = 0;
	cout << "======Next Floor or VisitShop======\n\n";
	cout << "1. ���� ��\n\n";
	cout << "2. ����\n\n";
	cout << "���� ������ �Ѿ�ðڽ��ϱ�? : ";
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
		cout << "======" << Round << "�� Monster!!======\n\n";
		cout << "*****B.O.S.S!!!*****\n\n";
		Boss_RedDragon Boss;
		Boss.roar();
		cout << "Boss HP : " << Boss.getHealth() << " / Boss Attack : " << Boss.getAttack() << endl;

		while (1)
		{
			if (Boss.getHealth() > 0)
			{
			MAKE_CHOICE1:
				cout << "======My Turn======\n\n";
				cout << "1. �����ϱ�\n\n";
				cout << "2. �κ��丮 ����\n\n";
				cout << "�������ּ��� : ";
				cin >> TrunChoice;

				switch (TrunChoice)
				{
				case 1:
					cout << "======My Attack======\n\n";
					cout << player->getName() << "��(��)" << Boss.getName() << "��(��) �����߽��ϴ�!!\n\n";
					cout << player->getAttack() << "��ŭ ���� �߽��ϴ�!!\n\n";
					Boss.takeDamage(player->getAttack());
					cout << "========================\n\n";
					cout << "Boss HP : " << Boss.getHealth() << " / Boss Attack : " << Boss.getAttack() << endl;
					break;

				case 2:
				MAKE_CHOICE2:
					cout << "======Use Item======\n\n";
					player->openInventory();
					cout << " " << player->getName() << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
					cout << "���ݷ� : " << player->getAttack() << endl;
					cout << "========================\n\n";
					cout << "1. Hp����\n\n";
					cout << "2. Attack����\n\n";
					cout << "3. ���ư���\n\n";
					cout << "� �������� ����Ͻðڽ��ϱ�? : ";
					cin >> InvenChoice;

					switch (InvenChoice)
					{
					case 1:
						if (player->useItem(EItemType::HealAmount))
						{
							cout << "======Hp 100 Potion Use======\n\n";
							cout << "HP�� �����Ǿ����ϴ�!\n\n";
							cout << " " << player->getName() << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
							cout << "���ݷ� : " << player->getAttack() << endl;
						}
						else
						{
							cout << "HP ������ �����մϴ�.\n\n";
							goto MAKE_CHOICE2;
						}
						break;

					case 2:
						if (player->useItem(EItemType::HealRatio))
						{
							cout << "======Hp 50%Potion Use======\n\n";
							cout << "Hp�� 50% �����Ǿ����ϴ�!\n\n";
							cout << " " << player->getName() << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
							cout << "���ݷ� : " << player->getAttack() << endl;
						}
						else
						{
							cout << "Hp�� 50% ������ �����մϴ�.";
							goto MAKE_CHOICE2;
						}
						break;

					case 3:
						cout << "���ư��ϴ�";
						goto MAKE_CHOICE1;
					}
					break;
				}
				cout << "======Boss Trun======\n\n";
				cout << Boss.getName() << "��(��)" << player->getName() << "��(��) �����߽��ϴ�!!\n\n";
				cout << Boss.getAttack() << "��ŭ ���� ���߽��ϴ�!!\n\n";
				player->takeDamage(Boss.getAttack());
				cout << "========================\n\n";
				cout << " " << player->getName() << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
				cout << "���ݷ� : " << player->getAttack() << endl;
			}
			else if (Boss.getHealth() <= 0)
			{
				cout << Boss.getName() << "��(��) óġ�߽��ϴ�!!\n\n";
				GameWin();
			}
			else if (player->getHealth() <= 0)
			{
				cout << Boss.getName() << "���� ���߽��ϴ�...\n\n";
				GameOver();
			}
		}
	}
}


void GameManager::GameOver()
{
	cout << "���ӿ��� �й��Ͽ����ϴ�\n\n";
	return exit(0);
}

void GameManager::GameWin()
{
	cout << "������ �¸��ϼ̽��ϴ�\n\n";
	return exit(0);
}