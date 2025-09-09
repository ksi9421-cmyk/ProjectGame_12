#pragma once
#include <iostream>
#include <string>

class item;
class Player {
private:
    std::string Name;
    int Level;
    int Health;
    int Attack;
    int Gold;
    int Exp;


public:
    Player(std::string nickname, int level, int health, int attack, int gold, int exp);

    void levelUp();
    void printPlayerStatus() const;
    void takeDamage(int Damage);
    void openInventory();
    void useItem();
    void heal(int amount);
    void powerUp(int amount);
    int getHealth();
    int getAttack();
    int getGold();

};
