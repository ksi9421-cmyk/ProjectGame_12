#pragma once
#include <iostream>
#include <string>
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


public:
    Player();
    Player(std::string nickname, int level, int health, int attack, int exp, int maxHP);

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
    static Player& getinstance();
    string getName();
    string setName(string nickname);
};
