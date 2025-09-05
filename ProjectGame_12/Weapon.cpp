#include "Item.h"
#include "player.h"
#include <iostream>
#include <string>
#include <utility>
#include <vector>

Weapon::Weapon(std::string name, int price, std::string info, int damage)
	:Item(std::move(name), price, std::move(info)), damage(damage) {
}
Weapon::~Weapon() = default;

void Weapon::use(Player& target) {
	int bonus = static_cast<int>(target.getAttack() * 0.2);
	target.addAttack(bonus);

	std::cout << "���� ����ǰ��� �����߽��ϴ�." << getName() << " ���ݷ��� 20%�����߽��ϴ�.(+" << bonus << ")\n";
}