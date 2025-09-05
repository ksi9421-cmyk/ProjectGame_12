#pragma once
#include <string>
using namespace std;


class Monster          
{
	
public:
	virtual string getName() = 0;
	virtual int getHealth() = 0;
	virtual int getAttack() = 0;
	virtual void takeDamage(int dagamge) = 0; 

	virtual ~Monster() {}
};

