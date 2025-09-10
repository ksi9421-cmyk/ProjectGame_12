#pragma once
#include <iostream>
#include <string>
#include <random>
#include "Player.h"
#include "GameManager.h"
using namespace std;


class Monster          
{
	
public:

	Monster() {}
	virtual string getName() = 0;
	virtual int getHealth() = 0;
	virtual int getAttack() = 0;
	virtual void roar() = 0;
	virtual void takeDamage(int damage) = 0; 

	virtual ~Monster() {}
};


