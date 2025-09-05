#pragma once
#include "Monster.h"

class Boss_RedDragon : public Monster
{
private:
	string name;
	int health;
	int attack;

public:
	Boss_RedDragon(int level);
	string getName();
	int getHealth();
	int getAttack();
	void takeDamage(/*Player* p*/);
};

