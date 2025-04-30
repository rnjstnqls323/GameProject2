#pragma once
enum GameState
{
	ChoiceJob,
	VisitStore,
	ChoiceDungeon,
	GameOver,
	GameClear
};
enum PlayerState
{
	Live,
	Dead
};
enum DungeonLevel
{
	Level1=1,
	Level2=2,
	Level3=3,
	Boss=4
};

enum Item 
{
	HPPotion,
	ManaPotion,
	APPotion
};
enum StatType
{
	Hp,
	AttackPower,
	Exp,
	Coin,
	Level,
	Mp,
	Name,
	SkillName,
	SkillDamage
};