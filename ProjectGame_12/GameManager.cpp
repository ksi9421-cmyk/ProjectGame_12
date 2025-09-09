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
	cout << "캐릭터 이름 : \n";
	
	string nickname;
	cin >> nickname;

	player.lock()->setName(nickname);

	cout << player.lock()->getName() << "으로 설정되었습니다!\n";
	cout << "HP / MaxHP : " << player.lock()->getHealth() << " / " << player.lock()->getmaxHP() << "공격력 : " << player.lock()->getAttack() << endl;
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
		cout << "======" << Round << "층 Monster!!======\n";
		cout << "*****Monster 등장!!*****\n";
		monster->roar();
		cout << "Monster HP : " << monster->getHealth() << "Monster Attack : " << monster->getAttack() << endl;

		while (1)
		{
			if (monster->getHealth() > 0)
			{
				cout << "======My Turn======\n";
				cout << "선택해주세요 : \n";
				cout << "1. 공격하기\n";
				cout << "2. 인벤토리 열기\n";
				cin >> TrunChoice;

				switch (TrunChoice)
				{

				case 1:
					cout << player.lock()->getName() << "이(가)" << monster->getName() << "을(를) 공격했다!!\n";
					//monster->getHealth() -= Player::getinstance().getAttack();
					cout << player.lock()->getAttack() << "만큼 데미지를 입혔다!!\n";
					break;

				case 2:
					//cout << " " << 인벤토리 << endl;
					cout << "어떤 아이템을 사용하시겠습니까? : \n";
					cout << "1. Hp물약\n";
					cout << "2. Attack물약\n";
					cout << "3. 돌아가기\n";
					cout << "HP : " << player.lock()->getHealth() << "Attack : " << player.lock()->getAttack() << endl;
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

					case 3:
						cout << "돌아갑니다";
						break;
					}
					break;
				}
				cout << monster->getName() << "이(가)" << player.lock()->getName() << "을(를) 공격했다!!\n";
				//Player::getinstance().getHealth() -= monster->getAttack();
				cout << monster->getAttack() << "만큼 데미지를 입혔다!!\n";
			}
			else if (monster->getHealth() <= 0)
			{
				int NextChoice = 0;
				cout << monster->getName() << "을(를) 처치했다!!\n";
				cout << "다음 층으로 넘어가시겠습니까? : \n";
				cout << "1. 다음 층\n";
				cout << "2. 상점\n";
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
				cout << monster->getName() << "에게 당했다...\n";
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
		cout << "======" << Round << "층 Monster!!======\n";
		cout << "*****B.O.S.S!!!*****\n";
		Boss_RedDragon Boss;
		Boss.roar();
		cout << "Boss HP : " << Boss.getHealth() << "Boss Attack : " << Boss.getAttack() << endl;

		while (1)
		{
			if (Boss.getHealth() > 0)
			{
				cout << "======My Turn======\n";
				cout << "선택해주세요 : \n";
				cout << "1. 공격하기\n";
				cout << "2. 인벤토리 열기\n";
				cin >> TrunChoice;

				switch (TrunChoice)
				{
				case 1:
					cout << player.lock()->getName() << "이(가)" << Boss.getName() << "을(를) 공격했다!!\n";
					//monster->getHealth() -= Player::getinstance().getAttack();
					cout << player.lock()->getAttack() << "만큼 데미지를 입혔다!!\n";
					break;

				case 2:
					//cout << " " << 인벤토리 << endl;
					cout << "어떤 아이템을 사용하시겠습니까? : \n";
					cout << "1. Hp물약\n";
					cout << "2. Attack물약\n";
					cout << "3. 돌아가기\n";
					cout << "HP : " << player.lock()->getHealth() << "Attack : " << player.lock()->getAttack() << endl;
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

					case 3:
						cout << "돌아갑니다";
						break;
					}
					break;
				}
				cout << Boss.getName() << "이(가)" << player.lock()->getName() << "을(를) 공격했다!!\n";
				//Boss.takeDamage(Player * p);
				cout << Boss.getAttack() << "만큼 데미지를 입혔다!!\n";
			}
			else if (Boss.getHealth() <= 0)
			{
				cout << Boss.getName() << "을(를) 처치했다!!\n";
				GameOver();
			}
			else if (player.lock()->getHealth() <= 0)
			{
				cout << Boss.getName() << "에게 당했다...\n";
				GameOver();
			}
		}
	}
}


int GameManager::GameOver()
{
	cout << "게임에서 패배하였습니다\n";
	exit(0);
}



