#include "Store.h"

void Store::AddHpPotion(Character* player)
{
	player->SetData(player, Hp, player->GetData().hp + hPPotion);
}

void Store::AddManaPotion(Character* player)
{
	player->SetData(player, Mp, player->GetData().mp + manaPotion);
}

void Store::AddAttackPotion(Character* player)
{
	player->SetData(player, AttackPower, player->GetData().attackPower + attackPotion);
}
