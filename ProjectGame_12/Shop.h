#pragma once

#include <string>
#include <vector>
#include "Gold.h"

using namespace std;

struct ShopItem // �����͹���
{
	string name; // �� �̸�
	int price; // �� ����
};

class Shop
{
private:
	vector<ShopItem> Itemlist; // �����ǸŸ��


public:

	Shop();
	void buyItem(Gold &playerGold); // �÷��̾� �� �����ؼ� ����
};