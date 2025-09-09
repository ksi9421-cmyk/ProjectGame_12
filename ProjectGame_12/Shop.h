#pragma once

#include <string>
#include <vector>
#include "Gold.h"

using namespace std;

struct Item // 데이터묶음
{
	string name; // 템 이름
	int price; // 템 가격
};

class Shop
{
private:
	vector<Item> Itemlist; // 상점판매목록


public:

	Shop();
	void buyItem(); // 골드 클래스 참조해서 차감
};