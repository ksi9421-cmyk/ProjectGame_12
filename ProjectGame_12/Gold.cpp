#include "Gold.h"
#include <iostream>
#include <random>

using namespace std;

Gold::Gold() : amount(0) {}  //기본 돈 0원

Gold::Gold(int startAmount) : amount(startAmount) {} // 원하는 시작 금액으로 초기화

Gold& Gold::getinstance()
{
	static Gold instance;
	return instance;
}

void Gold::add() 
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> goldDist(10, 20); // 10~20골드 랜덤 추가

	int bonus = goldDist(gen);
	amount += bonus;

	cout << bonus << " Gold 보너스를 추가로 얻었습니다!" << endl;
}

bool Gold::spend(int value) 
{
	if (amount >= value) // 골드가 충분하면
	{
		amount -= value; // 차감
		
		return true; // 구입
	}
	else
	{
		cout << "Gold가 충분하지 않습니다." << endl;
		return false; //실패
	}
}

int Gold::getAmount() const
{
	return amount; // 가진 돈 반환
}