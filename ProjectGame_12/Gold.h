#pragma once

using namespace std;

class Gold
{
private:
	int amount;
public:
	Gold(int startAmount);
	void add();
	bool spend(int value); // ������Լ� ���̸� �Һ��ϰ� �����̸� ����
	int getAmount() const;
};

