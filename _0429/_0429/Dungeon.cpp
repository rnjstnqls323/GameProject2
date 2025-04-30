#include "Dungeon.h"
#include "Enums.h"

PlayerState Dungeon(const int &level , Hero* player) //던전 입장 구현
{
	DungeonLevel dungeonLevel = static_cast<DungeonLevel>(level);
	vector<Monster> monsters;
	Monster* boss;
	int number = 3;

	switch (dungeonLevel) 
	{
	case Level1:
		CreateMonsters(monsters,"slime",number);
		FightMonster(player,monsters);
		
		break;

	case Level2:
		CreateMonsters(monsters, "skelleton", number);
		FightMonster(player,monsters);
		break;

	case Level3:
		CreateMonsters(monsters, "Goblin", number);
		FightMonster(player,monsters);
		break;

	case Boss:

		break;

	default:
		break;
	}
	//임시 반환
	return Dead;
}

void CreateMonsters(vector<Monster>& monsters, string name, const int& number)
{
	for (int i = 0; i < number; i++)
	{
		monsters.push_back(LoadDatas(name));
	}
	
}

void CreateBoss(Monster*& boss, BossName name)
{
	switch (name)
	{
	default:
		break;
	}
	boss = new Monster(); //보스 클래스로 변경할 것. + switch문으로 알맞는 보스 생성
}

void RemoveMonsters(vector<Monster>& monsters, const int& number)
{
	for (int i = 0; i < number; i++)
	{
		monsters.erase(monsters.begin());
	}
}

void RemoveBoss(Monster*& boss)
{
	delete boss;
}

int FightMonster(Hero* &player,vector<Monster> &monsters)
{
	//싸우는거 구현 
	//player는 skill안쓰면 하나씩 공격가능
	//while문으로 무한으로 돌기 / player.hp <=0 이거나 monsters의 피가 모두 닳으면 종료
	//player사망시 return 0; 
	//monsters 모두 사망시 return 1;
	return 0;
}

int FightBoss(Hero*& player, vector<Monster>& monsters, Monster*& boss)
{
	// 보스전투구현할 것
	return 0;
}


