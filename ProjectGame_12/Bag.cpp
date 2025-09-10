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
    items_.emplace(EItemType::HealAmount, std::make_shared<PotionHealAmount>());
    items_.emplace(EItemType::HealRatio, std::make_shared<PotionHealRatio>());
    items_.emplace(EItemType::EWeapon, std::make_shared<Weapon>());
    items_.emplace(EItemType::EArmor, std::make_shared<Armor>());
}

Bag::~Bag()
{
}

void Bag::addItem(EItemType ItemType, int count)
{
    items_[ItemType].lock()->addCount(count);
};

void Bag::printInfo() const {
    for (auto& witem : items_)
    {
        if (auto item = witem.second.lock())
        {
            std::cout << "[" << item->getName() << "] ����:" << item->getPrice()
                << " ����:" << item->getinfo() << "\n";
        }
    }
}

bool Bag::useItem(EItemType ItemType) {
    if(Owner == nullptr)
        return false;

    if (items_[ItemType].lock() == nullptr)
        return false;

    if (items_[ItemType].lock()->getCount() < 1)
        return false;

    items_[ItemType].lock()->use(Owner);

    return true;
}
Item* Bag::Dropitem()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int>distribute(1, 100);
	int randomNumber = distribute(gen);
	if (randomNumber <= 95)
	{
		cout << "[ž �������� ��]�� ȹ���Ͽ����ϴ�\n";
		return new Weapon("ž �������� ��", 80, "damage 20% up",0.2f, 1);
	}
	else if (randomNumber <= 90)
	{
		cout << "[ž �������� ����]�� ȹ���Ͽ����ϴ�\n";
		return new Armor("ž �������� ����", 80, "max hp up",0.3f , 1);
	}
	else if (randomNumber <= 82)
	{
		cout << "[elixirr] �� ȹ���Ͽ����ϴ�\n";
		return new PotionHealRatio("[elixirr]", 20, "50% MaxHP heal",0.5f, 1);
	}
	else if (randomNumber <= 70)
	{
		cout << "[Potion] �� ȹ���Ͽ����ϴ�\n";
		return new PotionHealAmount("[Potion]", 10, "100 HP heal",100, 1);
	}
	else
	{
		cout << "�ƹ��͵� ���� ���߽��ϴ� �Ф�\n";
		return nullptr;
	}
}