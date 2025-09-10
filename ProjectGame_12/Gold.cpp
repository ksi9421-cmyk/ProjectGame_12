#include "Gold.h"
#include <iostream>
#include <random>

using namespace std;

Gold::Gold() : amount(0) {}  //�⺻ �� 0��

Gold::Gold(int startAmount) : amount(startAmount) {} // ���ϴ� ���� �ݾ����� �ʱ�ȭ

Gold& Gold::getinstance()
{
	static Gold instance;
	return instance;
}

void Gold::add() 
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> goldDist(10, 20); // 10~20��� ���� �߰�

	int bonus = goldDist(gen);
	amount += bonus;

	cout << bonus << " Gold ���ʽ��� �߰��� ������ϴ�!" << endl;
}

bool Gold::spend(int value) 
{
	if (amount >= value) // ��尡 ����ϸ�
	{
		amount -= value; // ����
		
		return true; // ����
	}
	else
	{
		cout << "Gold�� ������� �ʽ��ϴ�." << endl;
		return false; //����
	}
}

int Gold::getAmount() const
{
	return amount; // ���� �� ��ȯ
}