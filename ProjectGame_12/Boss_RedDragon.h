#pragma once
#include "Monster.h"

class Boss_Dragon : public Monster
{
private:
	string name;
	int health;
	int attack;

public:
	Boss_Dragon(int level);
	string getName();
	int getHealth();
	int getAttack();
	void takeDamage(int damage);
};

