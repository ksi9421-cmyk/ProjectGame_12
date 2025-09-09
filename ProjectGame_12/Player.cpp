#include "Player.h"

using namespace std;

Player::Player(string nickname, int level, int health, int attack, int gold, int exp) :
	Name(nickname), Level(1), Health(200), Attack(30), Gold(0), Exp(0) {}

void Player::levelUp()
{
	if (Exp >= 100)
	{
		Level++;
		Health += 50;
		Attack += 10;
		Exp = 0;

		cout << "Level: " << Level << endl;
		cout << "Attack: " << Attack << ", HP: " << Health << endl << endl;
	}
}

void Player::printPlayerStatus() const {
	cout << "----- Player stat -----" << endl;
	cout << "       Attack: " << Attack << endl;
	cout << "           HP: " << Health << endl;
	cout << "          Lv.: " << Level << endl;
	cout << "         Gold: " << Gold << endl;
	cout << "=========================" << endl;
}

void Player::takeDamage(int Damage)
{
	Health -= Damage;

	if (Health < 0)
		Health = 0;

	cout << "-" << Damage << endl;
}

void Player::openInventory() 
{

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
