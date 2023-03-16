#include "stdafx.h"
#include "Inventory.h"
#include "Player.h"

CInventory::CInventory(const CInventory& rhs)
{
	player = rhs.player;
}

void CInventory::ShowPlayerItems() const
{
	if (!(player->GetItemCount()))
		cout << "�������� �������� �����ϴ�.\n";
	for (int i = 0; i < player->GetItemCount(); i++)
		cout << i + 1 << ". " << player->GetItems(i) << '\n';
}