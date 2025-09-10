#include "Goblin.h"
#include <random>

Goblin::Goblin()
{
	int level = GameManager::getRound();
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> distHealth(level * 40, level * 60);
	health = distHealth(gen);


	uniform_int_distribution<int> distAttack(level * 10, level * 20);
	attack = distAttack(gen);

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

void Goblin::roar()
{
	cout << "Goblin appeared!" << endl;
}

void Goblin::takeDamage(int damage)
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