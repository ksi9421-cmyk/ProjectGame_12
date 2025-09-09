#include "Player.h"

using namespace std;

Player::Player(string nickname, int level, int health, int attack, int gold, int exp)
	:Name(nickname), Level(level), Health(health), Attack(attack), Gold(gold), Exp(exp) {}

void Player::levelUp()
{
	if (Exp >= 100)
	{
		Level++;
		Health += 50;
		Attack += 10;
		Exp = 0;

		cout << "레벨 업! 현재 레벨: " << Level << endl;
		cout << "공격력: " << Attack << ", 체력: " << Health << endl << endl;
	}
}

void Player::printPlayerStatus() const {
	cout << "----- 플레이어 상태 -----" << endl;
	cout << "       공격력: " << Attack << endl;
	cout << "           HP: " << Health << endl;
	cout << "          Lv.: " << Level << endl;
	cout << "       소지금: " << Gold << endl;
	cout << "=========================" << endl;
}

void Player::takeDamage(int Damage)
{
	Health -= Damage;

	if (Health < 0)
		Health = 0;

	cout << "-" << Damage << endl;
}

void Player::openInventory() {
	
}

void Player::useItem()
{
}


int Player::getHealth()
{
	return Health;
}

int Player::getAttack()
{
	return Attack;
}

int Player::getGold()
{
	return Gold;
}