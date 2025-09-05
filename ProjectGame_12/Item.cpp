#include "Item.h"
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

Item::Item(std::string name, int price, std::string info) : name(std::move(name)), price(price), info(std::move(info)) {}
Item::~Item() = default;
const std::string Item::getName() const { return name; }
int Item::getPrice() const { return price; }
const std::string& Item::getinfo() const { return info; }
