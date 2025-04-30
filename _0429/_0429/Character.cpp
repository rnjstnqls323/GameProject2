#include "Character.h"

Character::Character(Datas data) : data(data)
{
}

Character::~Character()
{
}

void Character::AttackTarget(Character* target)
{
	target->data.hp = target->GetData().hp - GetData().attackPower;
}


bool Character::IsDead(Character* target)
{
	if (target->GetData().hp <= 0)
		return true;
	return false;
}
