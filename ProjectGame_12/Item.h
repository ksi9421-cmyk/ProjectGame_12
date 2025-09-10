#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <random>

enum EItemType
{
	HealAmount = 1,
	HealRatio,
	EWeapon,
	EArmor,
	Max,
};

class Player;
class Item
{
private:
	std::string name;
	int price;
	std::string info;
	int count;

public:
	Item()
	{
		price = 0;
		count = 0;
	}
	Item(std::string name, int price, std::string info);
	virtual ~Item() = default;

	virtual EItemType GetType() = 0;
	virtual void use(Player* target) = 0;

	void addCount(int inCount)
	{
		count = inCount;
	}

	int getCount() const
	{
		return count;
	}

	const std::string  getName() const;
	int getPrice() const;
	const std::string& getinfo() const;
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

	EItemType GetType() override {
		return EItemType::EWeapon;
	}
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

	EItemType GetType() override {
		return EItemType::EArmor;
	}
	void use(Player* target) override;
};

class PotionHealAmount : public Item {
public:
	int healAmount;
	PotionHealAmount()
	{
		healAmount = 100;
	}
	PotionHealAmount(std::string name, int price, std::string info, int inHealAmount)
		: Item(name, price, info), healAmount(inHealAmount)
	{
	}
	EItemType GetType() override {
		return EItemType::HealAmount;
	}
	void use(Player* target);
};

class PotionHealRatio : public Item {
public:
	float healRatio;
	PotionHealRatio()
	{
		healRatio = 1;
	}
	PotionHealRatio(std::string name, int price, std::string info, float inHealRatio)
		: Item(name, price, info), healRatio(inHealRatio)
	{
	}
	EItemType GetType() override {
		return EItemType::HealRatio;
	}
	void use(Player* target);
};

