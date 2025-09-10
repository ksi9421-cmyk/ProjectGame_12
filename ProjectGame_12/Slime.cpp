#include "Slime.h"
#include <random>

Slime::Slime()
{
	int level = GameManager::getinstance().getRound();
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> distHealth(level * 40, level * 60);
	health = distHealth(gen);


	uniform_int_distribution<int> distAttack(level * 10, level * 20);
	attack = distAttack(gen);

	name = "Slime";
}

string Slime::getName()
{
	return name;
}

int Slime::getHealth()
{
	return health;
}

int Slime::getAttack()
{
	return attack;
}

void Slime::roar()
{
	cout << "Slime appeared!" << endl;
}

void Slime::takeDamage(int damage)
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