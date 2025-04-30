#pragma once
#include "Framework.h"

class Hero :public Character
{
	Hero(Datas data);
	virtual bool Skill(Character* target) {};
	virtual string JobFunction() {};
	virtual void Promote(string job) {};
	void Fight(Character* target) override;



private:
	Datas data;


};