#include "Character.h"

Character::Character(Datas data) : data(data)
{
}

Character::~Character()
{
}

void Character::AttackTarget(Character* target)
{
	SetData(target, Hp, -GetData().attackPower);
}


void Character::Fight(Character* target)
{
	AttackTarget(target);
	printf("공격 성공! %s의 남은 체력: %d", target->GetData().name, target->GetData().hp);
}

bool Character::IsDead(Character* target)
{
	if (target->GetData().hp <= 0)
		return true;
	return false;
}
