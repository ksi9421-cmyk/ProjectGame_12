#pragma once
#include "Monster.h"

class Goblin : public Monster
{
private:
	string name;
	int health;
	int attack;

public:
	Goblin(int level);
	string getName();
	int getHealth();
	int getAttack();
	void takeDamage(/*Player* p*/);
};

