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
	int HPBoost;
	float HPBoostRatio;
	Armor();
	Armor(std::string name, int price, std::string info, int HPBoostRatio);
	~Armor() override;
		void use(Player& target) override;
};
class Potion : public Item {
public:
	int healAmount;
	float healRatio;
	bool isPercent;
	Potion();
	Potion(std::string name, int price, std::string info, int healAmount);
	Potion(std::string name, int price, std::string info, float healRatio);

	~Potion() override;

	void use(Player& target) override;
};