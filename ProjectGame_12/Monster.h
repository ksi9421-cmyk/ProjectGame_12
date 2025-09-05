#pragma once
#include <string>
using namespace std;


class Monster           //순수 가상함수로 기능할것
{
protected:
	string name;
	int HP;
	int Power;
	int Lev;

public:
	Monster(string name);


};

