#pragma once
#include "Monster.h"
#include "Player.h"

class Lizardman : public Monster
{
private:
	string name;
	int health;
	int attack;

public:
	Lizardman();
	string getName();
	int getHealth();
	int getAttack() ;
	void roar();
	void takeDamage(int damage) override;
};

