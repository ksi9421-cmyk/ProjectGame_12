#include "Bag.h"
#include "Player.h"
#include "Item.h"
#include <iostream>
#include <vector>


Bag::Bag(Player* owner)
{
    Owner = owner;
}

Bag::~Bag()
{
}

void Bag::printInfo() const {
    for (auto witem : items_)
    {
        if (auto item = witem.lock())
        {
            std::cout << "[" << item->getName() << "] ����:" << item->getPrice()
                << " ����:" << item->getinfo() << "\n";
        }
    }
}

void Bag::useAt(int index) {
    if(Owner == nullptr)
        return;
    if (index >= items_.size())
    {
        std::cout << "�߸��� �ε��� �Դϴ�.\n";
        return;
    }

    if (items_[index].lock() != nullptr)
    {
        items_[index].lock()->use(Owner);
    }

}