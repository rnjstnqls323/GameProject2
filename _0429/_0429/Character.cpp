#include "Character.h"

Character::Character(Datas data) : data(data)
{
}

Character::~Character()
{
}

void Character::AttackTarget(Character* target)
{
	SetData(target, Hp, target->GetData().hp - GetData().attackPower);
}


void Character::Fight(Character* target)
{
	AttackTarget(target);
	cout << "공격 성공! " << target->GetData().name<<"의 남은 체력:"<< target->GetData().hp<<endl;
}

bool Character::IsDead() // 수정하기
{
	if (GetData().hp <= 0)
		return true;
	return false;
}