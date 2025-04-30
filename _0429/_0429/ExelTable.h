#pragma once
#include "Framework.h"

struct Datas {
	string name;
	int hp;
	int speed;
	int attackPower;
	int exp;
	int coin;
};
struct StrongDatas {
	string name;
	int hp;
	int speed;
	int attackPower;
	int exp;
	int coin;
	int level;
	string skill;
	int damage;
	int mp;
};

Datas LoadDatas(string name);
StrongDatas LoadStrongDatas(string name, string status);
