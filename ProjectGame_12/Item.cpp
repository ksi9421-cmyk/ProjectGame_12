#include "Item.h"
#include "Player.h"
#include "Bag.h"
#include <iostream>
#include <string>
#include <utility>
#include <vector>


using namespace std;

Item::Item(std::string name, int price, std::string info, int inCount) : name(name), price(price), info(info), count(inCount)
{
}

std::string Item::getName() const
{
	return name;
}

int Item::getPrice() const
{
	return price;
}

const std::string& Item::getinfo() const
{
	return info;
}

