#include "Lizardman.h"
#include <random>

Lizardman::Lizardman(int level)
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> dist(level * 40, level * 60);
	health = dist(gen);


	uniform_int_distribution<int> dist(level * 10, level * 20);
	attack = dist(gen);
}

string Lizardman::getName()
{
	return name;
}

int Lizardman::getHealth()
{
	return health;
}

int Lizardman::getAttack()
{
	return attack;
}

void Lizardman::takeDamage(int damage)
{

}
