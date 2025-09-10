#include "Bag.h"
#include "Player.h"
#include "Item.h"
#include <iostream>
#include <vector>
#include <random>

Bag::Bag(Player* owner)
{
	Owner = owner;

	//quickSlots_.resize(QUICKSLOT_NUM);
	items_.emplace(EItemType::HealAmount, std::make_shared<PotionHealAmount>("potion", 10, "100 HP heal", 100, 0));
	items_.emplace(EItemType::HealRatio, std::make_shared<PotionHealRatio>("elixirr", 20, "50% MaxHP heal", 0.5f, 0));
	items_.emplace(EItemType::EWeapon, std::make_shared<Weapon>("���ݷ� ���� ����", 80, "damage 20% up", 0.2f, 0));
	items_.emplace(EItemType::EArmor, std::make_shared<Armor>("�ִ�ü�� ���� ����", 80, "max hp up", 0.3f, 0));
}

Bag::~Bag()
{
}

void Bag::addItem(EItemType ItemType, int count)
{
	items_[ItemType]->addCount(count);
};

void Bag::printInfo() const {
	for (auto& witem : items_)
	{
		if (auto item = witem.second)
		{
			std::cout << "[" << item->getName() << "]" << item->getCount() << "��"
				<< " ����:" << item->getinfo() << "\n";
		}
	}
}

bool Bag::useItem(EItemType ItemType) {
	if (Owner == nullptr)
		return false;

	if (items_[ItemType] == nullptr)
		return false;

	if (items_[ItemType]->getCount() < 1)
		return false;

	items_[ItemType]->use(Owner);

	return true;
}


void Bag::TakeRandomItem()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int>distribute(1, 100);
	int randomNumber = distribute(gen);
	if (randomNumber >= 95)
	{
		addItem(EItemType::EWeapon, 1);    
		cout << "5%Ȯ���� [���ݷ� ���� ����]�� ȹ���Ͽ����ϴ�\n";
	}
	else if (randomNumber >= 90)
	{
		addItem(EItemType::EArmor, 1);     
		cout << "5%Ȯ���� [�ִ�ü�� ���� ����]�� ȹ���Ͽ����ϴ�\n";
	}
	else if (randomNumber >= 82)
	{
		addItem(EItemType::HealRatio, 1);
		cout << "8%Ȯ���� [HP 50% ���� ����] �� ȹ���Ͽ����ϴ�\n";
	}
	else if (randomNumber >= 70)
	{
		addItem(EItemType::HealAmount, 1);  
		cout << "12%Ȯ����[HP 50 ���� ���� ] �� ȹ���Ͽ����ϴ�\n";
	}

	else cout << "�ƹ��͵� ���� ���߽��ϴ� �Ф�\n";
}
