#include "Lizardman.h"
#include <random>

Lizardman::Lizardman()
{
	int level = GameManager::getinstance().getRound();
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> distHealth(level * 40, level * 60);
	health = distHealth(gen);


	uniform_int_distribution<int> distAttack(level * 10, level * 20);
	attack = distAttack(gen);

	name = "Lizardman";
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

void Lizardman::roar()
{
	cout << "Lizardman appeared!" << endl;
}


void Lizardman::takeDamage(int damage)
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
