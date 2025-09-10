#pragma once
#include "Monster.h"
#include "Player.h"


class Goblin : public Monster
{
private:
	string name;
	int health;
	int attack;

public:
	Goblin();
	string getName();
	int getHealth();
	int getAttack();
	void roar();
	void takeDamage(int damage) override;
};

