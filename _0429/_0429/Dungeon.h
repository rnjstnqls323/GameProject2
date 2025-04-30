#pragma once
#include "Framework.h"
#include "Class.h"



PlayerState Dungeon(const int &dungeonLevel, Hero* player);
void CreateMonsters(vector<Monster>&monsters,string name,const int &number);
void CreateBoss(Monster* &boss,BossName name);
void RemoveMonsters(vector<Monster>& monsters, const int& number);
void RemoveBoss(Monster*& boss);
int FightMonster(Hero* &player, vector<Monster> &monsters);
int FightBoss(Hero* &player, vector<Monster>&monsters, Monster* &boss);
