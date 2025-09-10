#include "Player.h"
#include "Bag.h"

using namespace std;

Player::Player() :
	Name("Player"), Level(1), Health(200), Attack(30), Exp(0), maxHP(200), bag(std::make_unique<Bag>(this))
{
}

void Player::levelUp()
{
	if (Exp >= 100)
	{
		Level++;
		Health += 50;
		maxHP += 50;
		Attack += 10;
		Exp = 0;

		cout << "Level: " << Level << endl;
		cout << "Attack Up: " << Attack << ", HP Up: " << Health << endl << endl;
	}
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
	bag->PrintAllItems();
	bag->printInfo();
}

bool Player::useItem(EItemType ItemType)
{
	return bag->useItem(ItemType);
}

void Player::heal(int amount)
{
	Health += amount;
}

void Player::powerUp(int amount)
{
	Attack += amount;
}

void Player::addmaxHP(int amount)
{
	maxHP += amount;
}

int Player::getmaxHP()
{
	return maxHP;
}


int Player::getHealth()
{
	return Health;
}

int Player::getAttack()
{
	return Attack;
}

string Player::getName()
{
	return Name;
}

void Player::setName(const string& nickname)
{
	Name = nickname;
}
