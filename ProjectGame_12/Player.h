#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Bag.h"


using namespace std;


class item;
class Player {
private:
    std::string Name;
    int Level;
    int Health;
    int maxHP;
    int Attack;
    int Exp;
    std::unique_ptr<Bag> bag;

public:
    Player();

    void levelUp();
    void takeDamage(int Damage);
    void openInventory();
    bool useItem(EItemType ItemType);
    void heal(int amount);
    void powerUp(int amount);
    void addmaxHP(int amount);
    int getmaxHP();
    int getHealth();
    int getAttack();

    string getName();
    void setName(const string& nickname);
    int getExp();
    void setExp();
    Bag* getBag() const;
   
};