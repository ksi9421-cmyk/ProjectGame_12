#pragma once
#include "Monster.h"

class Slime :public Monster
{
private:
	string name;
	int health;
	int attack;

public:
	Slime(int level);
	string getName();
	int getHealth();
	int getAttack();
	void takeDamage(int damage);
};

