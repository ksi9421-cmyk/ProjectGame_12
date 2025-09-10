#pragma once

#include <string>
#include <vector>
#include "Gold.h"
#include "Player.h"

using namespace std;

struct ShopItem // 데이터묶음
{
	string name; // 템 이름
	int price; // 템 가격
	EItemType type;
};

class Shop
{
private:
	vector<ShopItem> Itemlist; // 상점판매목록


public:

	Shop();
	void buyItem(Player* player); 
	

};