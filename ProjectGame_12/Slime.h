#pragma once
#include "Monster.h"
#include "Player.h"

class Slime :public Monster
{
private:
	string name;
	int health;
	int attack;

public:
	Slime();
	string getName();
	int getHealth();
	int getAttack();
	void roar();
	void takeDamage(int damage);
};

