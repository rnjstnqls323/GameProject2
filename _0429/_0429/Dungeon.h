#pragma once
#include "Framework.h"
#include "ClassHeader.h"

class Dungeon
{
public:
	Dungeon();
	~Dungeon();

	GameState StartDungeon(Hero* player);
	void RemoveMonsters(vector<Monster>& monsters, const int& number);
	void RemoveBoss(Monster*& boss);
	int FightMonster(Hero*& player, Monster*& monster, Monster*& monsterKing);
    
	int FightBoss(Hero*& player, vector<Monster>& monsters, Monster*& boss);

private:

};
