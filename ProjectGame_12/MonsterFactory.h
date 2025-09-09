#pragma once
#include "Monster.h"
class MonsterFactory
{
public:
	static unique_ptr<Monster> CreateRandomMonster();
};


