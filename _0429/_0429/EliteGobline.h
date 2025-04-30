#pragma once
#include "Monster.h"

class EliteGobline : public Monster
{
public:
	EliteGobline(Datas data);
	~EliteGobline();

	void MonsterSkill(Character* target) override;

	//void ThiefsInstinct(EliteGobline* gobline, Character* target);

private:

};
