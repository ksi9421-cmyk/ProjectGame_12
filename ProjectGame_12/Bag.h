#pragma once
#include <vector>
#include "Item.h"
#include <string>
#include <iostream>


class Player;

class Bag
{
private:
    Player* Owner;
    std::vector<std::weak_ptr<Item>> items_;
public:
    Bag(Player* owner);
    ~Bag()
    {
    }
public:
    virtual void printInfo() const;

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
            
        }
    }
    void useAt(int index);
};
