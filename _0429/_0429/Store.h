#pragma once
#include "Framework.h"
#include "ClassHeader.h"

class Store
{
public:
	Store() {}
	~Store() {}

	void AddHpPotion(Character* player);
	void AddManaPotion(Character* player);
	void AddAttackPotion(Character* player);

private:
	int hPPotion = 30;
	int manaPotion = 30;
	int attackPotion = 30;
};