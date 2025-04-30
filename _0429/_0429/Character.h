#pragma once
#include "Framework.h"

template <typename T>
class Character{
public:
    Character(Datas data);
    ~Character();
    Datas GetData() { return data; }

    void SetData(Character* target, StatType type, T value)
    {
        switch (type)
        {
        case StatType::Hp:          target->data.hp += value; break;
        case StatType::AttackPower: target->data.attackPower += value; break;
        case StatType::Exp:         target->data.exp += value; break;
        case StatType::Coin:        target->data.coin += value; break;
        case StatType::Mp:        target->data.mp += value; break;
        case StatType::Name:       target->data.name = value; break;
        }
    }
    {
        Datas datatable = LoadData("paladin");
        SetData(this, Mp, -30);
    }
    virtual void Fight(Character* target);
    void AttackTarget(Character* target); //∆Ú≈∏
    bool IsDead(Character* target);

    
protected:
    Datas data;
};