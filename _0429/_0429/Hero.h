#pragma once
#include "Framework.h"


class Hero :public Character
{
	Hero(Datas data);
	virtual void Skill(Character* target) {};
	virtual string JobFunction() {}; //
	virtual void Promote() {};
	void Fight(Character* target) override;



private:
	Datas data;


};