#pragma once
enum GameState
{
	ChoiceJob,
	VisitStore,
	ChoiceDungeon,
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
enum HeroJob
{
	Warrior,
	Archer,
	Wizard,
	Thief
};
enum BossName
{
	고블린킹,
	
};
enum Item 
{
	HPPotion,
	SpeedPotion,
	APPotion
};
enum StatType
{
	Hp,
	Speed,
	AttackPower,
	Exp,
	Coin
};