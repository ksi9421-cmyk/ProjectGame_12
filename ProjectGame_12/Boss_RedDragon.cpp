#include "Boss_RedDragon.h"
#include <random>

Boss_RedDragon::Boss_RedDragon()
{
	int level = 10;
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> distHealth(level * 60, level * 90);
	health = distHealth(gen);


	uniform_int_distribution<int> distAttack(level * 15, level * 20);
	attack = distAttack(gen);

	name = "Red Dragon";
}

string Boss_RedDragon::getName()
{
	return name;
}

int Boss_RedDragon::getHealth()
{
	return health;
}

int Boss_RedDragon::getAttack()
{
	return attack;
}

void Boss_RedDragon::roar()
{
	cout << "Red Dragon appeared!" << endl;
}

void Boss_RedDragon::takeDamage(int damage)
{
	if (health > damage)
	{
		health -= damage;
	}
	else
	{
		health = 0;
		cout << name << "을(를) 처치했습니다!" << endl;
	}
}