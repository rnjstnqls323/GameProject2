#pragma once
#include "Monster.h"

class LichKing : public Monster
{
public:
	LichKing(Datas data);
	~LichKing();

	void CallOfTheDead();

	void SoulHarvest(LichKing* lich, Character* target);

	void DeathBurst(Character* target);

	void DeathSickle(LichKing* lich, int deathCount, Character* target);

	void Necromancer(LichKing* lich, int deathCount);

private:
	int deathCount = 0;
};
