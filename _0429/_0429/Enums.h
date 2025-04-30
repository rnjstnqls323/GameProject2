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
enum HeroJob
{
	Warrior,
	Archer,
	Wizard,
	Thief
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
	Mp,
	Name,
	SkillName,
	SkillDamage
};