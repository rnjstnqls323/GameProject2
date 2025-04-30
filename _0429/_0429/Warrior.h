#pragma once
#include "Framework.h"
#include "ExelTable.h"
#include "Character.h"
#include "Hero.h"

enum class WarriorJobType
{
	Normal,
	Paladine,
	Darknight
};

class Warrior
{
public:
	Warrior(HeroDatas data); int warrioroneSkill;
	~Warrior();

	HeroDatas GatData() { return data; }
	void AttackTarget(Warrior* target);
	bool isDead() const;

	void warriorSkill(Warrior* target);
	void jobFunction();
	WarriorJobType GetJobType() const { return jobType; }

protected:
	HeroDatas data;
	WarriorJobType jobType;

	void promotePaladine();
	void promoteDarknight();
	void paladskill();// 팔라딘 전직 스킬 체력증가
	void darknightskill(Warrior* targets[], int targetCount);//다크나이트 전직 스킬 다중공격


};
