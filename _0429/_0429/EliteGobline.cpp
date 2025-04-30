#include "Framework.h"
#include "Class.h"

EliteGobline::EliteGobline(Datas data) : Monster(data)
{

}

EliteGobline::~EliteGobline()
{

}

void EliteGobline::HammerSmash(EliteGobline* gobline, Character* target)
{
	cout << "[스킬 : 해머 내려찍기] " << target << "에게" << 3 * gobline->GetData().attackPower << "데미지!" << endl;
	SetData(target, Hp, (-3) * gobline->GetData().attackPower);
}

void EliteGobline::ThiefsInstinct(EliteGobline* gobline, Character* target)
{
	cout << "[패시브 : 도벽] " << target << "에게서" << 0.5f * gobline->GetData().attackPower << "골드를 뺏습니다." << endl;
	SetData(target, Coin, (-0.5f) * gobline->GetData().attackPower);
}
