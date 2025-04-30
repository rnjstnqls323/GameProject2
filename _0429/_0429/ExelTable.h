#pragma once
#include "Framework.h"

struct Datas {
	string name; //->ÆÈ¶óµò
	int hp;
	int attackPower;
	int exp;
	int coin;
	int level;
	string skill; // ½ºÅ³¸í -> ÆÈ¶óµò½ºÅ³
	int skillDamage; // ½ºÅ³µ¥¹ÌÁö
	int mp; //->30
};

Datas LoadDatas(string name,string type);


