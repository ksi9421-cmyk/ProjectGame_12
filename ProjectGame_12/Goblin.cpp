#include "Goblin.h"
#include <random>

Goblin::Goblin(int level)
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> dist(level * 40, level * 60);
	health = dist(gen);


	uniform_int_distribution<int> dist(level * 10, level * 20);
	attack = dist(gen);

	name = "Goblin";
}

string Goblin::getName()
{
	return name;
}

int Goblin::getHealth()
{
	return health;
}

int Goblin::getAttack()
{
	return attack;
}

void Goblin::takeDamage(/*Player* p*/)
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