#include "Gold.h"
#include <iostream>

using namespace std;

Gold::Gold(int startAmount) : amount(startAmount) {} //기본돈0원

void Gold::add(int value) 
{
	amount += value; 
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