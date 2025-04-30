#pragma once
#include "Monster.h"

class EliteSlime : public Monster
{
public:
	EliteSlime(Datas data);
	~EliteSlime();

	void AcidSpray(EliteSlime* slime, Character* target);

	void Acid(Character* target);

	void Split();

private:

};
