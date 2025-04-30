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
    Monster* monster = nullptr;
    Monster* monsterKing = nullptr;
    int num = 0;

    switch (dungeonLevel)
    {
    case Level1:
        cout << "슬라임 던전에 입장하셨습니다." << endl;
        monster = new Monster(LoadDatas("슬라임", "monster"));
       // monsterKing = new EliteSlime(LoadDatas("슬라임킹", "monster"));
        cout << "슬라임 1마리, 슬라임킹 1마리가 소환되었습니다." << endl;
        num = FightMonster(player, monster, monsterKing);
       switch (num)
       {
       case 1:
           return GameOver;
           break;
       case 2:
           cout << "던전 클리어!" << endl;
           return VisitStore;
           break;
       default:
           return GameOver;
           break;
       }
    case Level2:
        if (player->GetData().level<5)
        {
            cout << "5레벨 이하는 입장이 제한됩니다."<< endl;
            return ChoiceDungeon;
        }
        cout << "스켈레톤 던전에 입장하셨습니다." << endl;
        monster = new Monster(LoadDatas("스켈레톤", "monster"));
       // monsterKing = new EliteSkeleton(LoadDatas("스켈레톤킹", "monster"));
        cout << "스켈레톤 1마리, 스켈레톤킹 1마리가 소환되었습니다." << endl;
        num = FightMonster(player, monster, monsterKing);
        switch (num)
        {
        case 1:
            return GameOver;
            break;
        case 2:
            cout << "던전 클리어!" << endl;
            return VisitStore;
            break;
        default:
            return GameOver;
            break;
        }
    case Level3:
        /*if (player->GetData().level < 10)
        {
            cout << "10레벨 이하는 입장이 제한됩니다."<< endl;
            return ChoiceDungeon;
        }*/
        cout << "고블린 던전에 입장하셨습니다." << endl;
        monster = new Monster(LoadDatas("고블린", "monster"));
        monsterKing = new EliteGobline(LoadDatas("고블린킹", "monster"));
        cout << "고블린 1마리, 고블린킹 1마리가 소환되었습니다." << endl;
        num = FightMonster(player, monster, monsterKing);
        switch (num)
        {
        case 1:
            return GameOver;
            break;
        case 2:
            cout << "던전 클리어!" << endl;
            return VisitStore;
            break;
        default:
            return GameOver;
            break;
        }
    case Boss:
        if (player->GetData().level < 15)
        {
            cout << "15레벨 이하는 입장이 제한됩니다."<<endl;
            return ChoiceDungeon;
        }

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
        // 1. 플레이어가 죽었는지 확인
        if (player->IsDead())
            return 1; // 패배

        // 2. 일반 몬스터가 살아있는 경우
        if (!monster->IsDead())
        {
            player->Fight(monster);

            if (monster->IsDead())
            {
                // 경험치 보상 & 레벨업 처리
                int exp = monster->GetData().exp + player->GetData().exp;
                int level = exp / 10;
                player->SetData(player, Level, level + player->GetData().level);
                player->SetData(player, Exp, exp % 10);
                player->SetData(player, Coin, monsterKing->GetData().coin + player->GetData().coin);
                continue; // 다음 루프에서 monsterKing과 싸움 시작
            }

            monster->Fight(player);
            monsterKing->Fight(player);// 몬스터가 반격
        }

        // 3. 일반 몬스터가 죽은 경우 → 보스전 시작
        else
        {
            player->Fight(monsterKing);

            if (monsterKing->IsDead())
            {
                // 경험치 보상 & 레벨업 처리
                int exp = monsterKing->GetData().exp + player->GetData().exp;
                int level = exp / 10;
                player->SetData(player, Level, level + player->GetData().level);
                player->SetData(player, Exp, exp % 10);
                player->SetData(player, Coin, monsterKing->GetData().coin + player->GetData().coin);
                return 2; // 다음 루프에서 monsterKing과 싸움 시작
            }

            monsterKing->Fight(player);
        }
    }
}


int Dungeon::FightBoss(Hero*& player, vector<Monster>& monsters, Monster*& boss)
{
    // 보스전투구현할 것
    return 0;
}
