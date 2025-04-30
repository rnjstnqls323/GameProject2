#pragma once
#include "Framework.h"




class Warrior : public Hero
{
public:
	Warrior(Datas data);
	~Warrior();



	bool Skill(Character* target) override;
	string JobFunction() override;
	void Promote(string job) override;
protected:
	Datas data;


};