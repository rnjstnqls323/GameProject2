#pragma once
#include "Framework.h"
#include "Character.h"


class Hero :public Character
{
public:
	Hero(Datas data);
	~Hero();
	virtual void Skill(Character* target) {};
	virtual string JobFunction() { return "½ÇÆÐ"; }; //
	virtual void Promote() {};
	void Fight(Character* target) override;



private:
	Datas data;


};