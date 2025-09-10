#pragma once
#include <vector>
#include "Item.h"
#include <string>
#include <iostream>
#include <unordered_map>

class Player;

class Bag
{
public:

private:
    Player* Owner;
    std::unordered_map<EItemType, std::weak_ptr<Item>> items_;

public:

    Bag(Player* owner);
    ~Bag();
public:
    void printInfo() const;

public:
    void addItem(EItemType ItemType, int count);
    int GetSize() const
    {
        return (int)items_.size();
    }
    void PrintAllItems() const
    {
        if (GetSize() == 0)
        {
            std::cout << "가방이 비어있습니다." << std::endl;
            
        }
    }
    bool useItem(EItemType ItemType);
};
