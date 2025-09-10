#include "Bag.h"
#include "Player.h"
#include "Item.h"
#include <iostream>
#include <vector>
#include <random>

Bag::Bag(Player* owner) : Owner(owner)
{
	

	//quickSlots_.resize(QUICKSLOT_NUM);
	items_.emplace(EItemType::HealAmount, std::make_shared<PotionHealAmount>("potion", 10, "100 HP heal", 100, 0));
	items_.emplace(EItemType::HealRatio, std::make_shared<PotionHealRatio>("elixirr", 20, "50% MaxHP heal", 0.5f, 0));
	items_.emplace(EItemType::EWeapon, std::make_shared<Weapon>("���ݷ� ���� ����", 40, "damage 20% up", 0.2f, 0));
	items_.emplace(EItemType::EArmor, std::make_shared<Armor>("�ִ�ü�� ���� ����", 40, "max hp up", 0.3f, 0));
}

Bag::~Bag()
{
}

Item* Bag::getItem(EItemType type)
{
	auto it = items_.find(type);
	if (it != items_.end())
	{
		return it->second.get();
	}
	return nullptr;
}

void Bag::addItem(EItemType ItemType, int count)
{
	if (items_[ItemType])
	{
		items_[ItemType]->addCount(count);
	}
	else
	{
		switch (ItemType)
		{
		case EItemType::EWeapon:
			items_[ItemType] = std::make_shared<Weapon>("���ݷ� ���� ����", 40, "damage 20% up", 0.2f, count);
			break;

		case EItemType::EArmor:
			items_[ItemType] = std::make_shared<Armor>("�ִ�ü�� ���� ����", 40, "max hp up", 0.3f, count);
			break;

		case EItemType::HealAmount:
			items_[ItemType] = std::make_shared<PotionHealAmount>("potion", 10, "100 HP heal", 100, count);
			break;

		case EItemType::HealRatio:
			items_[ItemType] = std::make_shared<PotionHealRatio>("elixirr", 20, "50% MaxHP heal", 0.5f, count);
			break;
		}
	}
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
	if (randomNumber >= 93)
	{
		addItem(EItemType::EWeapon, 1);    
		cout << "8%Ȯ���� [���ݷ� ���� ����]�� ȹ���Ͽ����ϴ�\n";
	}
	else if (randomNumber >= 85)
	{
		addItem(EItemType::EArmor, 1);     
		cout << "8%Ȯ���� [�ִ�ü�� ���� ����]�� ȹ���Ͽ����ϴ�\n";
	}
	else if (randomNumber >= 74)
	{
		addItem(EItemType::HealRatio, 1);
		cout << "11%Ȯ���� [HP 50% ȸ�� ����] �� ȹ���Ͽ����ϴ�\n";
	}
	else if (randomNumber >= 60)
	{
		addItem(EItemType::HealAmount, 1);  
		cout << "14%Ȯ����[HP 100 ȸ�� ���� ] �� ȹ���Ͽ����ϴ�\n";
	}

	else cout << "�ƹ��͵� ���� ���߽��ϴ� �Ф�\n";
}
