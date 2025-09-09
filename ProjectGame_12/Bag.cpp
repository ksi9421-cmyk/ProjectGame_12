#include "Bag.h"
#include "Player.h"
#include "Item.h"
#include <iostream>
#include <vector>

/*
std::vector<std::weak_ptr<Item>> items_;
int Bag_size = 10;
int CurrentBag_size = 0;

if(Bag_size > CurrentBag_size)
{
	
}
*/

Bag::Bag(Player* owner)
{
    Owner = owner;
}

void Bag::printInfo() const {
    for (auto witem : items_)
    {
        if (auto item = witem.lock())
        {
            std::cout << "[" << item->getName() << "] 가격:" << item->getPrice()
                << " 설명:" << item->getinfo() << "\n";
        }
    }
}

void Bag::useAt(int index) {
    if(Owner == nullptr)
    if (index >= items_.size())
    {
        std::cout << "잘못된 인덱스 입니다.\n";
        return;
    }

    if (items_[index].lock() != nullptr)
    {
        items_[index].lock()->use(Owner);
    }

}