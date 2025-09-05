#include "Item.h"
#include "Player.h"
#include <string>
#include <utility>
#include <vector>
#include <iostream>

Armor::Armor(std::string name, int price, std::string info, int HPBoostRatio)
	: Item(std::move(name), price, std::move(info)), HPBoost(0), HPBoostRatio(HPBoostRatio) {
}
Armor::~Armor() = default;

void Armor::use(Player& target) {
	HPBoost = static_cast<int>(target.getMaxHP() * (HPBoostRatio / 30.f));
	target.increaseMaxHP(HPBoost);
	std::cout << "[����]" << getName() << "�� �����Ͽ� �ִ� HP�� " << HPBoost << "��ŭ �����߽��ϴ�.\n";
}