#pragma once
#include "Framework.h"




class Warrior : public Hero
{
public:
	Warrior(Datas data);
	~Warrior();



	void Skill(Character* target) override;
	string JobFunction() override;
	void Promote() override;
protected:
	Datas data;


};