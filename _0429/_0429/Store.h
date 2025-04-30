#pragma once
#include "Framework.h"
#include "ClassHeader.h"

class Store
{
public:
	Store() {}
	~Store() {}

	GameState VisitStore(Hero* player);
	void JobUpgrade(Hero* player);
	void AddHpPotion(Hero* player);
	void AddManaPotion(Hero* player);
	void AddAttackPotion(Hero* player);

private:
	int hPPotion = 30;
	int manaPotion = 30;
	int attackPotion = 30;
};