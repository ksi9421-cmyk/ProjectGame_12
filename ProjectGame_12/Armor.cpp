#include "Item.h"
#include "Player.h"
#include "Bag.h"
#include <string>
#include <utility>
#include <vector>
#include <iostream>

Armor::Armor(std::string name, int price, std::string info, float HPBoostRatio, int count)
	: Item(name, price, info, count), HPBoost(0), HPBoostRatio(HPBoostRatio)
{
}
Armor::~Armor() = default;

void Armor::use(Player* target)
{
	HPBoost = static_cast<int>(target->getmaxHP() * (HPBoostRatio));
	target->addmaxHP(HPBoost);
	std::cout << "Å¾ °ü¸®ÀÚÀÇ °©¿Ê" << getName() << "at used max hp up" << HPBoost << "% up.\n";
}
