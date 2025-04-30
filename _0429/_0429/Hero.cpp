#include "Hero.h"
#include "Framework.h"
#include "ExelTable.h"



//

Hero::Hero(Datas data) : Character(data)
{

}

Hero::~Hero()
{

}

void Hero::Fight(Character* target)

{
    int num;
    cout << "1.스킬 사용, 2.기본 공격 " << endl;
    cin >> num;
    if (num == 1)
    {
        if (GetData().mp < 30)
        {
            cout << "마나가 부족합니다. 기본 공격 실행!" << endl;
            Character::Fight(target);
            return;
        }

        SetData(this, Mp, -30);
        cout << "[내려찍기] 사용을 했습니다" << endl;
        return;
    }
    
    else if (num == 2)
    {
        Character::Fight(target);  
        return;
}

