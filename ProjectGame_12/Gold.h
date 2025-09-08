#pragma once

using namespace std;

class Gold
{
private:
	int amount;
public:
	Gold(int startAount = 0);
	void add();
	bool spend(int value); // 골드사용함수 참이면 소비하고 거짓이면 실패
	int getAmount() const;
};

