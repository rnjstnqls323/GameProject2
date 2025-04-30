#pragma once
#include "Framework.h"

class Character{
public:
    Character(Datas data);
    ~Character();
    Datas GetData() { return data; }

    void SetData(Character* target, StatType type, int value)
    {
        switch (type)
        {
        case StatType::Hp:          target->data.hp += value; break;
        case StatType::Speed:       target->data.speed += value; break;
        case StatType::AttackPower: target->data.attackPower += value; break;
        case StatType::Exp:         target->data.exp += value; break;
        case StatType::Coin:        target->data.coin += value; break;
        }
    }

    virtual void Fight(Character* target);
    void AttackTarget(Character* target); //∆Ú≈∏
    bool IsDead(Character* target);

    
protected:
    Datas data;
};