#pragma once
#include <iostream>
#include <string>

class item;
class Player {
private:
    std::string Name;
    int Level;
    int Health;
    int maxHP;
    int Attack;
    int Gold;
    int Exp;


public:
    Player();
    Player(std::string nickname, int level, int health, int attack, int gold, int exp, int maxHP);

    void levelUp();
    void printPlayerStatus() const;
    void takeDamage(int Damage);
    void openInventory();
    void useItem();
    void heal(int amount);
    void powerUp(int amount);
    void addmaxHP(int amount);
    int getmaxHP();
    int getHealth();
    int getAttack();
    int getGold();
    static Player& getinstance();
    string getName();
    string setName(string nickname);
};
