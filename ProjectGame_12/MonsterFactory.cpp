#include "MonsterFactory.h"
#include "Lizardman.h"
#include "Slime.h"
#include "Goblin.h"




unique_ptr<Monster> MonsterFactory::CreateRandomMonster()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(0, 2);

	switch (dist(gen))
	{
	case 0: return make_unique<Lizardman>();
	case 1: return make_unique<Goblin>();
	case 2: return make_unique<Slime>();
	}
	return nullptr;
}

