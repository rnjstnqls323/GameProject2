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
    if (num == 1) {
        data.mp -= 30;
        return;
    }
    else
        Character::Fight;

}
