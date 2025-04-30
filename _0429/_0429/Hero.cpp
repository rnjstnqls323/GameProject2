#include "Hero.h"
#include "Framework.h"
#include "ExelTable.h"


Hero::Hero(Datas data) : Character(data)
{

}

Hero::~Hero()
{

}
//전사 공통 스킬
void Hero::Fight(Character* target)
{
    int num;

    cout << "1. 스킬 사용 2. 평타"<< endl;
    cin >> num;

    if (num == 1)
    {
        if (GetData().mp >= 30)
        {
            Skill(target);

        }
        else
        {
            cout << "마나가 부족합니다. 평타가 나갑니다." << endl;
            Character::Fight(target);
        }
    }
    else  
    {
        Character::Fight(target);
    }
};


 