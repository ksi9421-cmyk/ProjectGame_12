#include "Bag.h"
#include "Player.h"
#include "Item.h"
#include <iostream>
#include <vector>


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
            std::cout << "[" << item->getName() << "] 가격:" << item->getPrice()
                << " 설명:" << item->getinfo() << "\n";
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
