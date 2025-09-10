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
	cout << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
	cout << "공격력 : " << player->getAttack() << endl;
}



void GameManager::MonsterRound()
{
	GameManager::getRound();
	auto monster = MonsterFactory::CreateRandomMonster();

	int TrunChoice = 0;
	int InvenChoice = 0;

		cout << "======" << Round << "층 Monster!!======\n\n";
		cout << "*****Monster 등장!!*****\n\n";
		monster->roar();
		cout << "Monster HP : " << monster->getHealth() << " / Monster Attack : " << monster->getAttack() << endl;

		while (player->getHealth() >0 && monster->getHealth() >0)
		{
			if (monster->getHealth() > 0)
			{
				MAKE_CHOICE1:
				cout << "======My Turn======\n\n";
				cout << "1. 공격하기\n";
				cout << "2. 인벤토리 열기\n";
				cout << "선택해주세요 : ";
				cin >> TrunChoice;

				switch (TrunChoice)
				{
				case 1:
					cout << "======My Attack======\n\n";
					cout << player->getName() << "이(가)" << monster->getName() << "을(를)" << player->getAttack() << "만큼 공격 했습니다!!\n";
					monster->takeDamage(player->getAttack());
					cout << "*Monster HP : " << monster->getHealth() << "*\n\n";
					
					break;

				case 2:
				MAKE_CHOICE2:

					player->openInventory();
					cout << "======Use Item======\n\n";
					cout << " " << player->getName() << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
					cout << "공격력 : " << player->getAttack() << endl;
					cout << "========================\n\n";
					cout << "1. Hp물약\n\n";
					cout << "2. 50%물약\n\n";
					cout << "3. 돌아가기\n\n";
					cout << "어떤 아이템을 사용하시겠습니까? : ";
					cin >> InvenChoice;

					switch (InvenChoice)
					{
					case 1:
						if (player->useItem(EItemType::HealAmount))
						{
							cout << "======Hp 100 Potion Use======\n\n";
							cout << "HP가 증가되었습니다!\n\n";
							cout << " " << player->getName() << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
							cout << "공격력 : " << player->getAttack() << endl;
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
							cout << "======Hp 50% Potion Use======\n\n";
							cout << "Hp가 50% 증가되었습니다!\n\n";
							cout << " " << player->getName() << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
							cout << "공격력 : " << player->getAttack() << endl;
						}
						else
						{
							cout << "========================\n\n";
					    	cout << "Hp가 50% 물약이 부족합니다.\n\n";
							goto MAKE_CHOICE2;
						}
						break;
						
					case 3:
						cout << "========================\n\n";
						cout << "돌아갑니다\n\n";
						goto MAKE_CHOICE1;
					}
					break;
				}
				if (monster->getHealth() > 0)
				{
					cout << "======Monster Trun======\n\n";
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
			
		     //아이템 count 연동 , 전리품 기능함수 추가
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
	int NextChoice = 0;
	cout << "======Next Floor or VisitShop======\n\n";
	cout << "1. 다음 층\n\n";
	cout << "2. 상점\n\n";
	cout << "다음 층으로 넘어가시겠습니까? : ";
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
		cout << "======" << Round << "층 Monster!!======\n\n";
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
				cout << "1. 공격하기\n\n";
				cout << "2. 인벤토리 열기\n\n";
				cout << "선택해주세요 : ";
				cin >> TrunChoice;

				switch (TrunChoice)
				{
				case 1:
					cout << "======My Attack======\n\n";
					cout << player->getName() << "이(가)" << Boss.getName() << "을(를)" << player->getAttack() << "만큼 공격 했습니다!!\n";
					Boss.takeDamage(player->getAttack());
					cout << "*Monster HP : " << Boss.getHealth() << "*\n\n";
					break;

				case 2:
				MAKE_CHOICE2:
					cout << "======Use Item======\n\n";
					player->openInventory();
					cout << " " << player->getName() << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
					cout << "공격력 : " << player->getAttack() << endl;
					cout << "========================\n\n";
					cout << "1. Hp물약\n\n";
					cout << "2. Attack물약\n\n";
					cout << "3. 돌아가기\n\n";
					cout << "어떤 아이템을 사용하시겠습니까? : ";
					cin >> InvenChoice;

					switch (InvenChoice)
					{
					case 1:
						if (player->useItem(EItemType::HealAmount))
						{
							cout << "======Hp 100 Potion Use======\n\n";
							cout << "HP가 증가되었습니다!\n\n";
							cout << " " << player->getName() << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
							cout << "공격력 : " << player->getAttack() << endl;
						}
						else
						{
							cout << "HP 물약이 부족합니다.\n\n";
							goto MAKE_CHOICE2;
						}
						break;

					case 2:
						if (player->useItem(EItemType::HealRatio))
						{
							cout << "======Hp 50%Potion Use======\n\n";
							cout << "Hp가 50% 증가되었습니다!\n\n";
							cout << " " << player->getName() << "HP / MaxHP : " << player->getHealth() << " / " << player->getmaxHP() << endl;
							cout << "공격력 : " << player->getAttack() << endl;
						}
						else
						{
							cout << "Hp가 50% 물약이 부족합니다.";
							goto MAKE_CHOICE2;
						}
						break;

					case 3:
						cout << "돌아갑니다";
						goto MAKE_CHOICE1;
					}
					break;
				}
				cout << "======Boss Trun======\n\n";
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