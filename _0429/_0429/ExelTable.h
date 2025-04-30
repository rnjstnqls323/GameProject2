#pragma once
#include "Framework.h"

struct Datas {
	string name;
	int hp;
	int attackPower;
	int exp;
	int coin;
	int level;
	string skill;
	int skillDamage;
	int mp;
};

Datas LoadDatas(string name,string type);


