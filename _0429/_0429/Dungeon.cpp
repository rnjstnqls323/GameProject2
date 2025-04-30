#include "Framework.h"
#include "Dungeon.h"

Dungeon::Dungeon()
{

}

Dungeon::~Dungeon()
{

}

GameState Dungeon::StartDungeon(Hero* player) //던전 입장 구현
{
    int level = 0;
    cout << "던전을 선택해주세요." << endl;
    cout << "1. 슬라임 던전, 2. 스켈레톤 던전, 3. 고블린 던전, 4. 보스 던전" << endl;
    cin >> level;
    DungeonLevel dungeonLevel = static_cast<DungeonLevel>(level);
    vector<Monster> monsters;
    Monster* boss;
    int deathNum = 0;
    Monster* monster = nullptr;
    Monster* monsterKing = nullptr;

    switch (dungeonLevel)
    {
    case Level1:
        cout << "슬라임 던전에 입장하셨습니다." << endl;
        monster = new Monster(LoadDatas("슬라임", "monster"));
        monsterKing = new Monster(LoadDatas("슬라임킹", "monster"));
        cout << "슬라임 1마리, 슬라임킹 1마리가 소환되었습니다." << endl;
        deathNum = FightMonster(player, monster, monsterKing);
        if (deathNum == 1)
        {
            return GameOver;
        }
        else if (deathNum == 2)
        {
            cout << "던전 클리어!" << endl;
            return VisitStore;
        }
    case Level2:
        cout << "스켈레톤 던전에 입장하셨습니다." << endl;
        monster = new Monster(LoadDatas("스켈레톤", "monster"));
        monsterKing = new Monster(LoadDatas("스켈레톤킹", "monster"));
        cout << "스켈레톤 1마리, 스켈레톤킹 1마리가 소환되었습니다." << endl;
        deathNum = FightMonster(player, monster, monsterKing);
        if (deathNum == 1)
        {
            return GameOver;
        }
        else if (deathNum == 2)
        {
            cout << "던전 클리어!" << endl;
            return VisitStore;
        }
    case Level3:
        cout << "고블린 던전에 입장하셨습니다." << endl;
        monster = new Monster(LoadDatas("고블린", "monster"));
        monsterKing = new Monster(LoadDatas("고블린킹", "monster"));
        cout << "고블린 1마리, 고블린킹 1마리가 소환되었습니다." << endl;
        deathNum = FightMonster(player, monster, monsterKing);
        if (deathNum == 1)
        {
            return GameOver;
        }
        else if (deathNum == 2)
        {
            cout << "던전 클리어!" << endl;
            return VisitStore;
        }
    case Boss:

        break;

    default:
        break;
    }
}

//void Dungeon::CreateBoss(Monster*& boss, BossName name)
//{
//   switch (name)
//   {
//   default:
//      break;
//   }
//   boss = new Monster(); //보스 클래스로 변경할 것. + switch문으로 알맞는 보스 생성
//}

void Dungeon::RemoveMonsters(vector<Monster>& monsters, const int& number)
{
    for (int i = 0; i < number; i++)
    {
        monsters.erase(monsters.begin());
    }
}

void Dungeon::RemoveBoss(Monster*& boss)
{
    delete boss;
}

int Dungeon::FightMonster(Hero*& player, Monster*& monster, Monster*& monsterKing)
{
    while (true)
    {
        if (monster->IsDead(monster) == false)
        {
            player->Fight(monster);
        }
        else if (monster->IsDead(monster) == true)
        {
            if (monsterKing->IsDead(monsterKing) == true)
            {
                return 2;
            }
            player->Fight(monsterKing);
        }
        monster->Fight(player);
        monsterKing->Fight(player);

        if (player->IsDead(player) == true)
        {
            return 1;
        }
    }
}

int Dungeon::FightBoss(Hero*& player, vector<Monster>& monsters, Monster*& boss)
{
    // 보스전투구현할 것
    return 0;
}
