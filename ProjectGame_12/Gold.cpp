#include "Gold.h"
#include <iostream>

using namespace std;

Gold::Gold(int startAmount) : amount(startAmount) {} //�⺻��0��

void Gold::add(int value) 
{
	amount += value; 
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