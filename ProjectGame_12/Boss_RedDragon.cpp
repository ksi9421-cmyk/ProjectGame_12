#include "Boss_RedDragon.h"
#include <random>

Boss_RedDragon::Boss_RedDragon(int level)
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> dist(level * 60, level * 90);
	health = dist(gen);


	uniform_int_distribution<int> dist(level * 15, level * 30);
	attack = dist(gen);

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

void Boss_RedDragon::takeDamage(/*Player* p*/)
{
	/*if (health > p.getattack)
	{
		health -= p.getattack;
	}
	else
	{
		health = 0;
		cout << name << "을(를) 처치했습니다!" << endl;
	}*/
}