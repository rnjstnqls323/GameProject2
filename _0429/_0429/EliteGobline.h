#pragma once
#include "Monster.h"

class EliteGobline : public Monster
{
public:
	EliteGobline(Datas data);
	~EliteGobline();

	void HammerSmash(EliteGobline* gobline, Character* target);

	void ThiefsInstinct(EliteGobline* gobline, Character* target);

private:

};
