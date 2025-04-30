#include "Store.h"

GameState Store::VisitStore(Hero* player)
{
	printf("=========상점=========\n");
	printf("   1. 체력 포션 : 30\n");
	printf("   2. 마나 포션 : 20\n");
	printf("   3. 공격력 포션 : 40\n");
	printf("   4. 전직\n");
	printf("   0. 종료\n");
	printf("======================\n");

	while (true)
	{
		cout << "보유코인 : " << player->GetData().coin << endl;
		cout << "버튼 입력 : ";
		int num = 0;
		cin >> num;
		switch (num)
		{
		case 1:
			if (player->GetData().coin < 30) {
				cout << "돈이없습니다. 다시골라주세요" << endl;
				break;
			}
			AddHpPotion(player);
			
			break;
		case 2:
			if (player->GetData().coin < 20) {
				cout << "돈이없습니다. 다시골라주세요" << endl;
				break;
			}
			AddManaPotion(player);
			
			break;
		case 3:
			if (player->GetData().coin < 40) {
				cout << "돈이없습니다. 다시골라주세요" << endl;
				break;
			}
			AddAttackPotion(player);
			
			break;
		case 4:
			
			break;
		default:
			cout << "상점을 종료합니다." << endl;
			return ChoiceDungeon;
			break;
		}
	}
	return ChoiceDungeon;
}

void Store::AddHpPotion(Hero* player)
{
	player->SetData(player, Hp, player->GetData().hp + hPPotion);
	player->SetData(player, Coin, player->GetData().coin - 30);
	cout << "당신의 체력 : " << player->GetData().hp<<endl;
}

void Store::AddManaPotion(Hero* player)
{
	player->SetData(player, Mp, player->GetData().mp + manaPotion);
	player->SetData(player, Coin, player->GetData().coin - 20);
	cout << "당신의 마나 : " << player->GetData().mp<<endl;
}

void Store::AddAttackPotion(Hero* player)
{
	player->SetData(player, AttackPower, player->GetData().attackPower + attackPotion);
	player->SetData(player, Coin, player->GetData().coin - 40);
	cout << "당신의 공격력 : " << player->GetData().attackPower<<endl;

}
