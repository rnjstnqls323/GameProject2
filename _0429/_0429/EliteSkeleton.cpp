#include "Framework.h"
#include "Class.h"

EliteSkeleton::EliteSkeleton(Datas data) : Monster(data)
{

}

EliteSkeleton::~EliteSkeleton()
{

}

void EliteSkeleton::DeathArrow(EliteSkeleton* skeleton, Character* target)
{
	cout << "[스킬 : 어둠 화살] " << target << "에게" << 2 * skeleton->GetData().attackPower << "데미지!" << endl;
	SetData(target, Hp, (-2) * skeleton->GetData().attackPower);
	cout << target << "의 공격력이 " << 30 << "감소합니다." << endl;
	SetData(target, AttackPower, -30);
}

void EliteSkeleton::UndyingWill(EliteSkeleton* skeleton)
{
	cout << "[패시브 : 불멸의 의지] " << skeleton << "이 " << 100 << "의 체력으로 부활합니다." << endl;
	SetData(skeleton, Hp, 100);
}
