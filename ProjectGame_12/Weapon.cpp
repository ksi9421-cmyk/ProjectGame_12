#include "Item.h"
#include "player.h"
#include "Bag.h"
#include <iostream>
#include <string>
#include <utility>
#include <vector>

Weapon::Weapon(std::string name, int price, std::string info, float damage, int count)
	:Item(name, price, info, count), damage(damage) {
}

Weapon::~Weapon()
{

}

void Weapon::use(Player* target) {
	int bonus = static_cast<int>(target->getAttack() * damage);
	target->powerUp(bonus);

	std::cout << getName() << " damage 20% up.(+" << bonus << ")\n";
}