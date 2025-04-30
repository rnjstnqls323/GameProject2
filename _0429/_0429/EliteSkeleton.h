#pragma once
#include "Monster.h"

class EliteSkeleton : public Monster
{
public:
	EliteSkeleton(Datas data);
	~EliteSkeleton();

	void DeathArrow(EliteSkeleton* skeleton, Character* target);

	void UndyingWill(EliteSkeleton* skeleton);

private:

};
