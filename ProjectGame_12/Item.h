#pragma once
#include <string>
#include <vector>
#include <iostream>

class Player;


class Item
{
private:
	std::string name;
	int price;
	std::string info;

public:
	Item(std::string name, int price, std::string info);
	virtual ~Item();

	virtual void use(Player& target) = 0;

	const std::string  getName() const;
	int getPrice() const;
	const std::string&getinfo() const;
};
class Weapon : public Item
{
public:
	int damage;
	Weapon();
	~Weapon();
	Weapon(std::string name, int price, std::string info, int damage);
	void use(Player& target) override;
};
class Armor : public Item
{
public:
	int defense;
	Armor();
	~Armor();
	Armor(std::string name, int price, std::string info, int defense);
		void use(Player& target) override;
};
class Potion : public Item {
public:
	int healAmount;
	Potion();
	~Potion();
	Potion(std::string name, int price, std::string info, int healAmount);
	void use(Player& target) override;
};