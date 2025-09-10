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
	cout << "HP / �ִ�HP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
	cout << "���ݷ� : " << player->getAttack() << endl;
}



void GameManager::MonsterRound()
{
	GameManager::getRound();
	auto monster = MonsterFactory::CreateRandomMonster();

	int TrunChoice = 0;
	int InvenChoice = 0;

	cout << "======" << Round << "�� ����!!======\n\n";
	cout << "*****���� ����!!*****\n\n";
	monster->roar();
	cout << "���� HP : " << monster->getHealth() << " / ���� ���ݷ� : " << monster->getAttack() << endl;
	while (player->getHealth() > 0 && monster->getHealth() > 0)
	{
		if (monster->getHealth() > 0)
		{
		MAKE_CHOICE1:
			cout << "======���� ��======\n\n";
			cout << "1. �����ϱ�\n";
			cout << "2. �κ��丮 ����\n";
			cout << "�������ּ��� : ";
			cin >> TrunChoice;

			switch (TrunChoice)
			{
			case 1:
				cout << "======���� ����======\n\n";
				cout << player->getName() << "��(��)" << monster->getName() << "��(��)" << player->getAttack() << "��ŭ ���� �߽��ϴ�!!\n";
				monster->takeDamage(player->getAttack());
				cout << "*���� HP : " << monster->getHealth() << "*\n\n";

				break;
			case 2:
			MAKE_CHOICE2:

				player->openInventory();
				cout << "======������ ���======\n\n";
				cout << " " << player->getName() << "HP / �ִ�HP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
				cout << "���ݷ� : " << player->getAttack() << endl;
				cout << "========================\n\n";
				cout << "1. Hp ȸ�� ����\n\n";
				cout << "2. Hp 50% ȸ�� ����\n\n";
				cout << "3. ���ݷ� ���� ����\n\n";
				cout << "4. �ִ� HP ���� ����\n\n";
				cout << "5. ���ư���\n\n";
				cout << "� �������� ����Ͻðڽ��ϱ�? : ";
				cin >> InvenChoice;

				switch (InvenChoice)
				{
				case 1:
					if (player->useItem(EItemType::HealAmount))
					{
						cout << "======HP ȸ�� ���� ���======\n\n";
						cout << "HP�� �����Ǿ����ϴ�!\n\n";
						cout << " " << player->getName() << "HP / �ִ�HP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
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
						cout << "======Hp 50% ȸ�� ����======\n\n";
						cout << "Hp�� 50% �����Ǿ����ϴ�!\n\n";
						cout << " " << player->getName() << "HP / �ִ�HP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
					}
					else
					{
						cout << "========================\n\n";
						cout << "Hp�� 50% ������ �����մϴ�.\n\n";
						goto MAKE_CHOICE2;
					}
					break;

				case 3:
					if (player->useItem(EItemType::EWeapon))
					{
						cout << "======���ݷ� ���� ���� ���======\n\n";
						cout << "���ݷ��� 20% �����Ǿ����ϴ�!\n\n";
						cout << " " << player->getName() << "���ݷ� : " << player->getAttack() << endl;
					}
					else
					{
						cout << "========================\n\n";
						cout << "���ݷ� ���� ������ �����մϴ�.\n\n";
						goto MAKE_CHOICE2;
					}
					break;

				case 4:
					if (player->useItem(EItemType::EArmor))
					{
						cout << "======�ִ�HP ���� ���� ���======\n\n";
						cout << "�ִ�HP�� 30% �����Ǿ����ϴ�!\n\n";
						cout << " " << player->getName() << "�ִ� HP : " << player->getmaxHP() << endl;
					}
					else
					{
						cout << "========================\n\n";
						cout << "�ִ� HP ���� ������ �����մϴ�.\n\n";
						goto MAKE_CHOICE2;
					}
					break;

				case 5:
					cout << "========================\n\n";
					cout << "���ư��ϴ�\n\n";
					goto MAKE_CHOICE1;

				default:
					cout << "�ٽ� �������ּ��� \n\n";
					goto MAKE_CHOICE2;
				}
			default:
				cout << "�ٽ� �������ּ��� \n\n";
				goto MAKE_CHOICE1;
			}
			if (monster->getHealth() > 0)
			{
				cout << "======���� ����======\n\n";
				cout << monster->getName() << "��(��)" << player->getName() << "��(��) " << monster->getAttack() << "��ŭ ���� ���߽��ϴ�!!\n";
				player->takeDamage(monster->getAttack());
				cout << "* " << player->getName() << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << "*\n\n";

			}
			else
			{
				break;
			}
		}
	}
	if (monster->getHealth() <= 0)
	{
		cout << "Level�� 1 �ö����ϴ�!!";
		player->setExp();
		player->levelUp();
		Gold::getinstance().add();
		Bag* myBag = player->getBag();
		if (myBag)
		{
			myBag->TakeRandomItem();
		}
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
	Shop shop;
	while (1)
	{
	MAKE_CHOICE:
		int NextChoice = 0;
		cout << "======����======\n\n";
		cout << "1. ���� ��\n\n";
		cout << "2. ����\n\n";
		cout << "���� ������ �Ѿ�ðڽ��ϱ�? : ";
		cin >> NextChoice;

		switch (NextChoice)
		{
		case 1:
			break;

		case 2:
			
			shop.buyItem(player.get()); 
			break;

		default:
			cout << "�ٽ� �������ּ��� \n\n";
			goto MAKE_CHOICE;
		}
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
		cout << "======" << Round << "�� ����!!======\n\n";
		cout << "*****B.O.S.S!!!*****\n\n";
		Boss_RedDragon Boss;
		Boss.roar();
		cout << "���� HP : " << Boss.getHealth() << " / ���� ���ݷ� : " << Boss.getAttack() << endl;

		while (1)
		{
			if (player->getHealth() > 0 && Boss.getHealth() > 0)
			{
			MAKE_CHOICE1:
				cout << "======���� ��======\n\n";
				cout << "1. �����ϱ�\n\n";
				cout << "2. �κ��丮 ����\n\n";
				cout << "�������ּ��� : ";
				cin >> TrunChoice;

				switch (TrunChoice)
				{
				case 1:
					cout << "======���� ����======\n\n";
					cout << player->getName() << "��(��)" << Boss.getName() << "��(��)" << player->getAttack() << "��ŭ ���� �߽��ϴ�!!\n";
					Boss.takeDamage(player->getAttack());
					cout << "*���� HP : " << Boss.getHealth() << "*\n\n";

					break;

				case 2:
				MAKE_CHOICE2:

					player->openInventory();
					cout << "======������ ���======\n\n";
					cout << " " << player->getName() << "HP / �ִ�HP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
					cout << "���ݷ� : " << player->getAttack() << endl;
					cout << "========================\n\n";
					cout << "1. Hp ȸ�� ����\n\n";
					cout << "2. Hp 50% ȸ�� ����\n\n";
					cout << "3. ���ݷ� ���� ����\n\n";
					cout << "4. �ִ� HP ���� ����\n\n";
					cout << "5. ���ư���\n\n";
					cout << "� �������� ����Ͻðڽ��ϱ�? : ";
					cin >> InvenChoice;

					switch (InvenChoice)
					{
					case 1:
						if (player->useItem(EItemType::HealAmount))
						{
							cout << "======HP ȸ�� ���� ���======\n\n";
							cout << "HP�� �����Ǿ����ϴ�!\n\n";
							cout << " " << player->getName() << "HP / �ִ�HP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
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
							cout << "======Hp 50% ȸ�� ����======\n\n";
							cout << "Hp�� 50% �����Ǿ����ϴ�!\n\n";
							cout << " " << player->getName() << "HP / �ִ�HP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
						}
						else
						{
							cout << "========================\n\n";
							cout << "Hp�� 50% ������ �����մϴ�.\n\n";
							goto MAKE_CHOICE2;
						}
						break;

					case 3:
						if (player->useItem(EItemType::EWeapon))
						{
							cout << "======���ݷ� ���� ���� ���======\n\n";
							cout << "���ݷ��� 20% �����Ǿ����ϴ�!\n\n";
							cout << " " << player->getName() << "���ݷ� : " << player->getAttack() << endl;
						}
						else
						{
							cout << "========================\n\n";
							cout << "���ݷ� ���� ������ �����մϴ�.\n\n";
							goto MAKE_CHOICE2;
						}
						break;

					case 4:
						if (player->useItem(EItemType::EArmor))
						{
							cout << "======�ִ�HP ���� ���� ���======\n\n";
							cout << "�ִ�HP�� 30% �����Ǿ����ϴ�!\n\n";
							cout << " " << player->getName() << "�ִ� HP : " << player->getmaxHP() << endl;
						}
						else
						{
							cout << "========================\n\n";
							cout << "�ִ� HP ���� ������ �����մϴ�.\n\n";
							goto MAKE_CHOICE2;
						}
						break;

					case 5:
						cout << "========================\n\n";
						cout << "���ư��ϴ�\n\n";
						goto MAKE_CHOICE1;

					default:
						cout << "�ٽ� �������ּ��� \n\n";
						goto MAKE_CHOICE2;
					}
				default:
					cout << "�ٽ� �������ּ��� \n\n";
					goto MAKE_CHOICE1;
				}

				cout << "======���� ����======\n\n";
				cout << Boss.getName() << "��(��)" << player->getName() << "��(��) " << Boss.getAttack() << "��ŭ ���� ���߽��ϴ�!!\n";
				player->takeDamage(Boss.getAttack());
				cout << "* " << player->getName() << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << "*\n\n";
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