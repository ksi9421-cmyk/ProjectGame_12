#include "Item.h"
#include "Player.h"
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

void Potion::use(Player& target) {
	if (isPercent) {
		int healValue = static_cast<int>(target.getMaxHP() * healRatio);
		target.heal(healValue);
		std::cout << "[엘릭서]" << getName() << "을 사용하여 최대 HP의 " << (healRatio * 100) << "%만큼 회복했습니다.(+" << healValue << ")\n";
	}
	else {
		target.heal(healAmount);
		std::cout << " [포션]" << getName() << "을 사용하여 " << healAmount << "만큼 회복했습니다.\n";
	}
}