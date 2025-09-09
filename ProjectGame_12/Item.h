#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <random>


class Player;
class Item
{
private:
	std::string name;
	int price;
	std::string info;

public:
	Item()
	{
		price = 0;
	}
	Item(std::string name, int price, std::string info);
	virtual ~Item();
	
	virtual void use(Player* target) = 0;

	const std::string  getName() const;
	int getPrice() const;
	const std::string&getinfo() const;
	virtual void printInfo() const {
				std::cout << "[" << getName() << "] 가격:" << getPrice()
					<< " 설명:" << getinfo() << "\n";
	}

};
class Weapon : public Item
{
public:
	int damage;
	Weapon() 
	{
		damage = 1;
	}
	~Weapon();
	Weapon(std::string name, int price, std::string info, int damage);;
	void use(Player* target);
};
class Armor : public Item
{
public:
	int HPBoost;
	float HPBoostRatio;
	Armor() 
	{
		HPBoost = 0;
		HPBoostRatio = 1;
	}
	Armor(std::string name, int price, std::string info, float HPBoostRatio);
	~Armor() override;
	void use(Player* target);
};
class Potion : public Item {
public:
	int healAmount;
	float healRatio;
	bool isPercent;
	Potion()
	{
		isPercent = 0;
		healAmount = 100;
		healRatio = 1;
	}
	Potion(std::string name, int price, std::string info, int healAmount);
	Potion(std::string name, int price, std::string info, float healRatio);

	~Potion() override;

	void use(Player* target);

};

