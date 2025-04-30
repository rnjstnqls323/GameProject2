#include "Framework.h"
#include "ClassHeader.h"

Monster::Monster(Datas data) : Character(data)
{

}

Monster::~Monster()
{

}

void Monster::Fight(Character* target)
{
    if (rand() % 3 == 0)
    {
        MonsterSkill(target);
    }
    else
    {
        Character::Fight(target);
    }
}
