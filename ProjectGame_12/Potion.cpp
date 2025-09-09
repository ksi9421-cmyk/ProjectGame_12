#include "Item.h"
#include "Player.h"
#include "Bag.h"
#include <string>
#include <utility>
#include <vector>
#include <iostream>

Potion::Potion(std::string name, int price, std::string info, int healAmount)
	: Item(std::move(name), price, std::move(info)), healAmount(healAmount) ,healRatio(0.0f), isPercent(false){}


Potion::Potion(std::string name, int price, std::string info, float healRatio)
	: Item(std::move(name), price, std::move(info)), healAmount(0), healRatio(healRatio), isPercent(true) {
}

Potion::~Potion() = default;

void Potion::use(Player* target) {
	if (isPercent) {
		int healValue = static_cast<int>(target->getHealth() * healRatio);
		target->heal(healValue);
		std::cout << "[elixirr]" << getName() << "at used max hp " << (healRatio * 50) << "% heal.(+" << healValue << ")\n";
	}
	else {
		target->heal(healAmount);
		std::cout << " [Potion]" << getName() << "at used " << healAmount << "heal.\n";
	}
}