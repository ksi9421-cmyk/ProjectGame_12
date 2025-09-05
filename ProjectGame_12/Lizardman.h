#pragma once
#include "Monster.h"

class Lizardman : public Monster
{
private:
	string name;
	int health;
	int attack;

public:
	Lizardman(int level);
	string getName();
	int getHealth();
	int getAttack();
	void takeDamage(/*Player* p*/);
};

