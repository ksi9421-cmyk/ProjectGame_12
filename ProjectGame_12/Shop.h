#pragma once

#include <string>
#include <vector>
#include "Gold.h"

using namespace std;

struct Item // �����͹���
{
	string name; // �� �̸�
	int price; // �� ����
};

class Shop
{
private:
	vector<Item> Itemlist; // �����ǸŸ��


public:

	Shop();
	void buyItem(); // ��� Ŭ���� �����ؼ� ����
};