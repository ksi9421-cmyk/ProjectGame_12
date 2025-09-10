#pragma once
#include "Monster.h"
#include "Player.h"

class Boss_RedDragon : public Monster
{
private:
	string name;
	int health;
	int attack;

public:
	Boss_RedDragon();
	string getName();
	int getHealth();
	int getAttack();
	void roar();
	void takeDamage(int damage);
};

