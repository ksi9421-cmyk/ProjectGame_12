#include "Item.h"
#include "Player.h"
#include "Bag.h"
#include <string>
#include <utility>
#include <vector>
#include <iostream>

Armor::Armor(std::string name, int price, std::string info, float HPBoostRatio)
	: Item(std::move(name), price, std::move(info)), HPBoost(0), HPBoostRatio(HPBoostRatio) {
}
Armor::~Armor() = default;

void Armor::use(Player* target)
{
	HPBoost = static_cast<int>(target->getmaxHP() * (HPBoostRatio / 30.f));
	target->addmaxHP(HPBoost);
	std::cout << "[cloak]" << getName() << "at used max hp" << HPBoost << "% up.\n";
}
