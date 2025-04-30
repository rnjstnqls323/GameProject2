#pragma once
#include "archer.h"
#include "ExelTable.h"
#include "Hero.h"

archer::archer(HeroDatas data)
	: jobType(archerJobType::Normal)
{
	this->data = data;
	this->data.hp = 200;
	this->data.mp = 100;
}

archer::~archer()
{
}

void Character::AttackTarget(Character* target)
{
	if (!target || target->isDead()) return;

	int damage = data.attack - target->data.defense;
	if (damage < 0) damage = 8;

	target->data.hp -= damage;
	cout << "공격! 대상에게" << damage << "의 일반 데미지를 입혔습니다\n";

	if (target->isDead())
		cout << "대상이 사망했습니다.\n";
}

bool archer::isDead() const
{
	return data.hp <= 0;
}

// 기본 스킬: 활쏘기
void archer::archerSkill(archer* target)
{
	const int mana = 20;
	if (data.mp < mana)
	{
		cout << "[실패] 마나가 부족합니다. (필요: " << mana << ", 현재: " << data.mp << ")\n";
		return;
	}
	data.mp -= mana;

	if (!target || target->isDead()) return;

	const int skillDamage = 40;
	target->data.hp -= skillDamage;

	cout << "[스킬: 활쏘기] 마나 " << mana << " 소모. 고정 피해 " << skillDamage << " 입힘!\n";

	if (target->isDead())
		cout << "활쏘기로 대상이 사망했습니다.\n";
}

// 전직 기능
void archer::jobFunction()
{
	if (data.level < 10)
	{
		cout << "레벨이 부족하여 전직할 수 없습니다.\n";
		return;
	}

	int choice = 0;
	while (true)
	{
		cout << "전직할 직업을 선택하세요:\n";
		cout << "1. 스나이퍼 (공격력 +20)\n";
		cout << "2. 레인저 (스피드 +10)\n";
		cout << "입력 (1 또는 2): ";
		cin >> choice;

		if (choice == 1)
		{
			promoteSniper();
			break;
		}
		else if (choice == 2)
		{
			promoteRanger();
			break;
		}
		else
		{
			cout << "잘못된 입력입니다. 다시 입력하세요.\n\n";
		}
	}
}

// 스나이퍼 전직
void archer::promoteSniper()
{
	jobType = archerJobType::Sniper;
	data.attack += 20;
	data.hp = 300;
	data.mp = 200;
	cout << "전직 완료! [스나이퍼] 공격력 +20, 체력 300, 마나 200\n";
}

// 레인저 전직
void archer::promoteRanger()
{
	jobType = archerJobType::Ranger;
	data.speed += 10;
	data.hp = 350;
	data.mp = 230;
	cout << "전직 완료! [레인저] 스피드 +10, 체력 350, 마나 230\n";
}

// 스나이퍼 스킬: 헤드샷
void archer::sniperSkill(archer* target)
{
	const int mana = 90;
	if (jobType != archerJobType::Sniper)
	{
		cout << "[오류] 스나이퍼만 사용할 수 있는 스킬입니다.\n";
		return;
	}
	if (data.mp < mana)
	{
		cout << "[실패] 마나가 부족합니다. (필요: " << mana << ", 현재: " << data.mp << ")\n";
		return;
	}
	data.mp -= mana;

	const int damage = 120;
	target->data.hp -= damage;

	cout << "[스킬: 헤드샷] 마나 " << mana << " 소모. 피해 " << damage << "\n";

	if (target->isDead())
		cout << "헤드샷으로 대상이 사망했습니다.\n";
}

// 레인저 스킬: 백발백중 (3명)
void archer::rangerSkill(archer* targets[], int targetCount)
{
	const int mana = 80;
	if (jobType != archerJobType::Ranger)
	{
		cout << "[오류] 레인저만 사용할 수 있는 스킬입니다.\n";
		return;
	}
	if (data.mp < mana)
	{
		cout << "[실패] 마나가 부족합니다. (필요: " << mana << ", 현재: " << data.mp << ")\n";
		return;
	}
	data.mp -= mana;

	const int damage = 90;
	int count = (targetCount > 3) ? 3 : targetCount;

	cout << "[스킬: 백발백중] 마나 " << mana << " 소모. 3명의 적에게 각각 " << damage << " 데미지!\n";

	for (int i = 0; i < count; ++i)
	{
		if (targets[i] && !targets[i]->isDead())
		{
			targets[i]->data.hp -= damage;
			cout << "- 대상 " << (i + 1) << "에게 " << damage << " 데미지!\n";

			if (targets[i]->isDead())
				cout << "  대상 " << (i + 1) << "이(가) 사망했습니다.\n";
		}
	}
}
