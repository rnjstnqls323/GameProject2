#include "Framework.h"


LichKing::LichKing(Datas data) : Monster(data)
{

}

LichKing::~LichKing()
{

}

void LichKing::CallOfTheDead()
{
	cout << "[스킬 : 망자의 부름] 스켈레톤 3마리를 소환합니다." << endl;
	//일반 스켈레톤 3마리 소환
	deathCount += 3;
}

void LichKing::SoulHarvest(LichKing* lich, Character* target)
{
	cout << "[스킬 : 영혼 수확] " << target << " 및 아군 스켈레톤 들의 체력을 50씩 흡수!" << endl;
	//플레이어 및 아군 스켈레톤의 체력을 50만큼 흡수해서 회복
	deathCount += 3;
}

void LichKing::DeathBurst(Character* target)
{
	int count = 3;
	cout << "[스킬 : 죽음의 폭발] 스켈레톤 " << count << "마리 폭발!" << target << "에게" << count * 100 << "데미지!" << endl;
	//아군 스켈레톤들을 전부 폭발시키고 폭발시킨 갯수만큼 데미지
	deathCount += 3;
}

void LichKing::DeathSickle(LichKing* lich, int deathCount, Character* target)
{
	cout << "[스킬 : 죽음의 낫] " << target << "에게 " << 3 * lich->data.attackPower + deathCount * 5 << "데미지!" << endl;
	SetData(target, Hp, (-3) * lich->data.attackPower + deathCount * 5);
}

void LichKing::Necromancer(LichKing* lich, int deathCount)
{
	lich->data.attackPower += deathCount * 5;
}
