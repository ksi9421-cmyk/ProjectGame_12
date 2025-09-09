#pragma once
#include <vector>
#include "Player.h"
#include "Item.h"
#include <string>
#include <iostream>



class Bag
{
private:
    std::vector<std::weak_ptr<Item>> items_;
public:
    Bag()
    {
    }
    ~Bag()
    {
    }
public:
    virtual void printInfo() const {
        for(auto witem:items_)
        {
            if (auto item = witem.lock())
            {
                std::cout << "[" << item->getName() << "] 가격:" << item->getPrice()
                    << " 설명:" << item->getinfo() << "\n";
            }
        }
    }
public:
    void addItem(const std::shared_ptr<Item>& item)
    {
        items_.push_back(item);
    }
    void RemoveLastItem()
    {
        items_.pop_back();
    }
    int GetSize() const
    {
        return items_.size();
    }
    void PrintAllItems() const
    {
        if (GetSize() == 0)
        {
            std::cout << "가방이 비어있습니다." << std::endl;
            return;
        }
    }
    void useAt(int index, Player& target) {
        if (index < 0 || index >= GetSize()) {
            std::cout << "잘못된 인덱스 입니다.\n";
            return;
        }
    }
};
