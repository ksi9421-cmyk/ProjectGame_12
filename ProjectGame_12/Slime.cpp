#include "Slime.h"
#include <random>

Slime::Slime(int level)
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> dist(level * 40, level * 60);
	health = dist(gen);


	uniform_int_distribution<int> dist(level * 10, level * 20);
	attack = dist(gen);

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

void Slime::takeDamage(/*Player* p*/)
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