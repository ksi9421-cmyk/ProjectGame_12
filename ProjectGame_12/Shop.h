#pragma once

#include <string>
#include <vector>
#include "Gold.h"
#include "Player.h"

using namespace std;

struct ShopItem // �����͹���
{
	string name; // �� �̸�
	int price; // �� ����
	EItemType type;
};

class Shop
{
private:
	vector<ShopItem> Itemlist; // �����ǸŸ��


public:

	Shop();
	void buyItem(Player* player); 
	

};