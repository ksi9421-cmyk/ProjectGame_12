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
	cout << "캐릭터 이름 : ";
	
	string nickname;
	cin >> nickname;

	player->setName(nickname);

	cout << player->getName() << "으로 설정되었습니다!\n\n";
	cout << "HP / 최대HP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
	cout << "공격력 : " << player->getAttack() << endl;
}



void GameManager::MonsterRound()
{
	GameManager::getRound();
	auto monster = MonsterFactory::CreateRandomMonster();

	int TrunChoice = 0;
	int InvenChoice = 0;

	cout << "======" << Round << "층 몬스터!!======\n\n";
	cout << "*****몬스터 등장!!*****\n\n";
	monster->roar();
	cout << "몬스터 HP : " << monster->getHealth() << " / 몬스터 공격력 : " << monster->getAttack() << endl;
	while (player->getHealth() > 0 && monster->getHealth() > 0)
	{
		if (monster->getHealth() > 0)
		{
		MAKE_CHOICE1:
			cout << "======유저 턴======\n\n";
			cout << "1. 공격하기\n";
			cout << "2. 인벤토리 열기\n";
			cout << "선택해주세요 : ";
			cin >> TrunChoice;

			switch (TrunChoice)
			{
			case 1:
				cout << "======유저 공격======\n\n";
				cout << player->getName() << "이(가)" << monster->getName() << "을(를)" << player->getAttack() << "만큼 공격 했습니다!!\n";
				monster->takeDamage(player->getAttack());
				cout << "*몬스터 HP : " << monster->getHealth() << "*\n\n";

				break;
			case 2:
			MAKE_CHOICE2:

				player->openInventory();
				cout << "======아이템 사용======\n\n";
				cout << " " << player->getName() << "HP / 최대HP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
				cout << "공격력 : " << player->getAttack() << endl;
				cout << "========================\n\n";
				cout << "1. Hp 회복 물약\n\n";
				cout << "2. Hp 50% 회복 물약\n\n";
				cout << "3. 공격력 증가 물약\n\n";
				cout << "4. 최대 HP 증가 물약\n\n";
				cout << "5. 돌아가기\n\n";
				cout << "어떤 아이템을 사용하시겠습니까? : ";
				cin >> InvenChoice;

				switch (InvenChoice)
				{
				case 1:
					if (player->useItem(EItemType::HealAmount))
					{
						cout << "======HP 회복 물약 사용======\n\n";
						cout << "HP가 증가되었습니다!\n\n";
						cout << " " << player->getName() << "HP / 최대HP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
					}
					else
					{
						cout << "========================\n\n";
						cout << "HP 물약이 부족합니다.\n\n";
						goto MAKE_CHOICE2;
					}
					break;

				case 2:
					if (player->useItem(EItemType::HealRatio))
					{
						cout << "======Hp 50% 회복 물약======\n\n";
						cout << "Hp가 50% 증가되었습니다!\n\n";
						cout << " " << player->getName() << "HP / 최대HP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
					}
					else
					{
						cout << "========================\n\n";
						cout << "Hp가 50% 물약이 부족합니다.\n\n";
						goto MAKE_CHOICE2;
					}
					break;

				case 3:
					if (player->useItem(EItemType::EWeapon))
					{
						cout << "======공격력 증가 물약 사용======\n\n";
						cout << "공격력이 20% 증가되었습니다!\n\n";
						cout << " " << player->getName() << "공격력 : " << player->getAttack() << endl;
					}
					else
					{
						cout << "========================\n\n";
						cout << "공격력 증가 물약이 부족합니다.\n\n";
						goto MAKE_CHOICE2;
					}
					break;

				case 4:
					if (player->useItem(EItemType::EArmor))
					{
						cout << "======최대HP 증가 물약 사용======\n\n";
						cout << "최대HP이 30% 증가되었습니다!\n\n";
						cout << " " << player->getName() << "최대 HP : " << player->getmaxHP() << endl;
					}
					else
					{
						cout << "========================\n\n";
						cout << "최대 HP 증가 물약이 부족합니다.\n\n";
						goto MAKE_CHOICE2;
					}
					break;

				case 5:
					cout << "========================\n\n";
					cout << "돌아갑니다\n\n";
					goto MAKE_CHOICE1;

				default:
					cout << "다시 선택해주세요 \n\n";
					goto MAKE_CHOICE2;
				}
			default:
				cout << "다시 선택해주세요 \n\n";
				goto MAKE_CHOICE1;
			}
			if (monster->getHealth() > 0)
			{
				cout << "======몬스터 공격======\n\n";
				cout << monster->getName() << "이(가)" << player->getName() << "을(를) " << monster->getAttack() << "만큼 공격 당했습니다!!\n";
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
		cout << "Level이 1 올랐습니다!!";
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
		cout << monster->getName() << "에게 당했습니다...\n\n";
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
		cout << "======상점======\n\n";
		cout << "1. 다음 층\n\n";
		cout << "2. 상점\n\n";
		cout << "다음 층으로 넘어가시겠습니까? : ";
		cin >> NextChoice;

		switch (NextChoice)
		{
		case 1:
			break;

		case 2:
			
			shop.buyItem(player.get()); 
			break;

		default:
			cout << "다시 선택해주세요 \n\n";
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
		cout << "======" << Round << "층 보스!!======\n\n";
		cout << "*****B.O.S.S!!!*****\n\n";
		Boss_RedDragon Boss;
		Boss.roar();
		cout << "보스 HP : " << Boss.getHealth() << " / 보스 공격력 : " << Boss.getAttack() << endl;

		while (1)
		{
			if (player->getHealth() > 0 && Boss.getHealth() > 0)
			{
			MAKE_CHOICE1:
				cout << "======유저 턴======\n\n";
				cout << "1. 공격하기\n\n";
				cout << "2. 인벤토리 열기\n\n";
				cout << "선택해주세요 : ";
				cin >> TrunChoice;

				switch (TrunChoice)
				{
				case 1:
					cout << "======유저 공격======\n\n";
					cout << player->getName() << "이(가)" << Boss.getName() << "을(를)" << player->getAttack() << "만큼 공격 했습니다!!\n";
					Boss.takeDamage(player->getAttack());
					cout << "*보스 HP : " << Boss.getHealth() << "*\n\n";

					break;

				case 2:
				MAKE_CHOICE2:

					player->openInventory();
					cout << "======아이템 사용======\n\n";
					cout << " " << player->getName() << "HP / 최대HP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
					cout << "공격력 : " << player->getAttack() << endl;
					cout << "========================\n\n";
					cout << "1. Hp 회복 물약\n\n";
					cout << "2. Hp 50% 회복 물약\n\n";
					cout << "3. 공격력 증가 물약\n\n";
					cout << "4. 최대 HP 증가 물약\n\n";
					cout << "5. 돌아가기\n\n";
					cout << "어떤 아이템을 사용하시겠습니까? : ";
					cin >> InvenChoice;

					switch (InvenChoice)
					{
					case 1:
						if (player->useItem(EItemType::HealAmount))
						{
							cout << "======HP 회복 물약 사용======\n\n";
							cout << "HP가 증가되었습니다!\n\n";
							cout << " " << player->getName() << "HP / 최대HP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
						}
						else
						{
							cout << "========================\n\n";
							cout << "HP 물약이 부족합니다.\n\n";
							goto MAKE_CHOICE2;
						}
						break;

					case 2:
						if (player->useItem(EItemType::HealRatio))
						{
							cout << "======Hp 50% 회복 물약======\n\n";
							cout << "Hp가 50% 증가되었습니다!\n\n";
							cout << " " << player->getName() << "HP / 최대HP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
						}
						else
						{
							cout << "========================\n\n";
							cout << "Hp가 50% 물약이 부족합니다.\n\n";
							goto MAKE_CHOICE2;
						}
						break;

					case 3:
						if (player->useItem(EItemType::EWeapon))
						{
							cout << "======공격력 증가 물약 사용======\n\n";
							cout << "공격력이 20% 증가되었습니다!\n\n";
							cout << " " << player->getName() << "공격력 : " << player->getAttack() << endl;
						}
						else
						{
							cout << "========================\n\n";
							cout << "공격력 증가 물약이 부족합니다.\n\n";
							goto MAKE_CHOICE2;
						}
						break;

					case 4:
						if (player->useItem(EItemType::EArmor))
						{
							cout << "======최대HP 증가 물약 사용======\n\n";
							cout << "최대HP이 30% 증가되었습니다!\n\n";
							cout << " " << player->getName() << "최대 HP : " << player->getmaxHP() << endl;
						}
						else
						{
							cout << "========================\n\n";
							cout << "최대 HP 증가 물약이 부족합니다.\n\n";
							goto MAKE_CHOICE2;
						}
						break;

					case 5:
						cout << "========================\n\n";
						cout << "돌아갑니다\n\n";
						goto MAKE_CHOICE1;

					default:
						cout << "다시 선택해주세요 \n\n";
						goto MAKE_CHOICE2;
					}
				default:
					cout << "다시 선택해주세요 \n\n";
					goto MAKE_CHOICE1;
				}

				cout << "======보스 공격======\n\n";
				cout << Boss.getName() << "이(가)" << player->getName() << "을(를) " << Boss.getAttack() << "만큼 공격 당했습니다!!\n";
				player->takeDamage(Boss.getAttack());
				cout << "* " << player->getName() << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << "*\n\n";
			}
			else if (Boss.getHealth() <= 0)
			{
				cout << Boss.getName() << "을(를) 처치했습니다!!\n\n";
				GameWin();
			}
			else if (player->getHealth() <= 0)
			{
				cout << Boss.getName() << "에게 당했습니다...\n\n";
				GameOver();
			}
		}
	}
}


void GameManager::GameOver()
{
	cout << "게임에서 패배하였습니다\n\n";
	return exit(0);
}

void GameManager::GameWin()
{
	cout << "게임을 승리하셨습니다\n\n";
	return exit(0);
}