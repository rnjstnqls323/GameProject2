#include "Warrior.h"
#include "ExelTable.h"


Warrior::Warrior(HeroDatas data)
	: jobType(WarriorJobType::Normal)
{
	this->data = data;
	this->data.hp = 200;
	this->data.mp = 100;
}

Warrior::~Warrior()
{
}
void Character::AttackTarget(Character* target)
{
	if (!target || target->isDead()) return;

	int damage = data.attackPower - target->data.defense;
	if (damage < 0) damage = 5;

	target->data.hp -= damage;
	cout << "공격! 대상에게" << damage << "의 일반 데미지를 입혔습니다\n";

	if (target->isDead())
		cout << "대상이 사망했습니다.\n";

}

bool Warrior::isDead() const
{
	return data.hp <= 0;
}
void Warrior::warriorSkill(Warrior* target)
{
	const int mana = 30;
	if (data.mp < mana)
	{
		cout << "[실패] 마나가 부족합니다. (필요: " << mana << ", 현재: " << data.mp << ")\n";
		return;
	}
	data.mp -= mana;
	if (!target || target->isDead()) return;

	const int skillDamage = 30;
	target->data.hp -= skillDamage;

	cout << "[스킬: 내려찍기] 마나 " << mana << " 소모. 고정 피해 " << skillDamage << " 입힘!\n";

	if (target->isDead())
		cout << "내려찍기로 대상이 사망했습니다.\n";
}
//전직기능
void Warrior::jobFunction()
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
		cout << "1. 팔라딘 (방어력 +10)\n";
		cout << "2. 다크나이트 (공격력 +10)\n";
		cout << "입력 (1 또는 2): ";
		cin >> choice;

		if (choice == 1)
		{
			promotePaladine();
			break;
		}
		else if (choice == 2)
		{
			promoteDarknight();
			break;
		}
		else
		{
			cout << "잘못된 입력입니다. 다시 입력하세요.\n\n";
		}
	}
}
void Warrior::promotePaladine()
{
	jobType = WarriorJobType::Paladine;
	data.defense += 10;
	data.hp = 400;   // 체력 설정
	data.mp = 150;   // 마나 설정
	cout << "전직 완료! [팔라딘] 방어력 +10, 체력 400, 마나 150\n";
}
void Warrior::promoteDarknight()
{
	jobType = WarriorJobType::Darknight;
	data.attack += 10;
	data.hp = 350;   // 체력 설정
	data.mp = 200;   // 마나 설정
	cout << "전직 완료! [다크나이트] 공격력 +10, 체력 350, 마나 200\n";
}
void Warrior::paladskill()
{
	const int mana = 60;
	if (jobType != WarriorJobType::Paladine)
	{
		cout << "[오류] 팔라딘만 사용할 수 있는 스킬입니다.\n";
		return;
	}
	if (data.mp < mana)
	{
		cout << "[실패] 마나가 부족합니다. (필요: " << mana << ", 현재: " << data.mp << ")\n";
		return;
	}
	data.mp -= mana;
	data.hp += 100;

	data.hp += 100;
	cout << "[스킬: 체력증가] 체력을 100 회복했습니다! 현재 HP: " << data.hp << "\n";
}
void Warrior::darknightskill(Warrior* targets[], int targetCount)
{
	const int mana = 70;
	if (jobType != WarriorJobType::Darknight)
	{
		cout << "[오류] 다크나이트만 사용할 수 있는 스킬입니다.\n";
		return;
	}
	if (data.mp < mana)
	{
		cout << "[실패] 마나가 부족합니다. (필요: " << mana << ", 현재: " << data.mp << ")\n";
		return;
	}
	data.mp -= mana;

	const int damage = 80;
	int count = (targetCount > 3) ? 3 : targetCount;

	cout << "[스킬: 연속 찌르기] 마나 " << mana << " 소모. 3명의 적에게 각각 " << damage << " 데미지!\n";

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
