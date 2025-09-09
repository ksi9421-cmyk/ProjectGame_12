#pragma once
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Bag;
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

    Player();
    
public:
    void levelUp();
    void takeDamage(int Damage);
    void openInventory();
    void useItem();
    void heal(int amount);
    void powerUp(int amount);
    void addmaxHP(int amount);
    int getmaxHP();
    int getHealth();
    int getAttack();

    string getName();
    string setName(const string& nickname);
};
