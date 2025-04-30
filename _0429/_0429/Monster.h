#pragma once
//#include "Framework.h"
#include "ExelTable.h"
#include "Character.h"

class Monster : public Character
{
public:
	Monster(Datas data);
	~Monster();

	void Fight(Character* target) override;

	virtual void MonsterSkill(Character* target) { AttackTarget(target); }

private:

};