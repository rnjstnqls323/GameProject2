#include "Warrior.h"
#include "ExelTable.h"


Warrior::Warrior(Datas data) : Hero(data)
{

}

Warrior::~Warrior()
{

}

//스킬명,타겟 한테 데미지 출력
//전사 스킬
void Warrior::Skill(Character* target)
{
	int damage = GetData().skillDamage;

	SetData(target, Hp, target -> GetData().hp - damage);
	SetData(this, Mp, GetData().mp - 30);

	cout << GetData().skill << "을 사용했습니다. "
		<< damage << "의 피해를 입혔습니다." << endl;
}
//
//전직기능
string Warrior::JobFunction()
{
	if (GetData().level <= 10)
	{
		cout << "레벨이 부족하여 전직할 수 없습니다.\n";
		return "실패";
	}

	int choice = 0;
	if (GetData().name != "전사") {
		cout << "이미 전직을 하였습니다."<<endl;
		return "실패";
	}
	while (true)
	{
		cout << "전직할 직업을 선택하세요:\n";
		cout << "1. 팔라딘\n";
		cout << "2. 다크나이트\n";
		cout << "입력 (1 또는 2): ";
		cin >> choice;

		if (choice == 1)
		{
			return "팔라딘";
		}
		else if (choice == 2)
		{
			return "다크나이트";
		}
		else
		{
			cout << "잘못된 입력입니다. 다시 입력하세요.\n\n";
		}
	}
}
//Set Data 넣어서 name, hp -> 체력이 올라간다 , 공격력 증가, 스킬명 변경, 스킬 데미지 mp증가
//증가 ex) Datas jobData = LoadDatas(job,"player");
//SetData(this, Hp, GetData().hp + jobDatas.hp)
void Warrior::Promote()
{
	string job = JobFunction(); //리턴된값을 넣겠다 직업을 가져옴
	if (job == "실패") {
		return;
	}
	Datas jobData = LoadDatas(job, "player");
	//직업 이름 변경
	SetStringData(this, Name, job);
	//체력증가
	SetData(this, Hp, GetData().hp + jobData.hp);
	//공격력증가
	SetData(this, AttackPower, GetData().attackPower + jobData. attackPower);
	//스킬명 변경
	SetStringData(this, SkillName, jobData.skill);
	//스킬 데미지 증가
	SetData(this, SkillDamage, GetData().skillDamage + jobData. skillDamage);
	//MP증가
	SetData(this, Mp, GetData().mp + jobData. mp);

}
