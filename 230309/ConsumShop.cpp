#include "stdafx.h"
#include "ConsumShop.h"
#include "Consumable.h"
#include "Player.h"

CConsumShop::CConsumShop() : CShop()
{
}

CConsumShop::CConsumShop(const CConsumShop& rhs)
{
}

CConsumShop::CConsumShop(CCreature* _creature) : CShop(_creature)
{
	AddItem("家葛前1", 10, 1);
	AddItem("家葛前2", 20, 2);
	AddItem("家葛前3", 30, 3);
	AddItem("家葛前4", 40, 4);
	AddItem("家葛前5", 50, 5);
	AddItem("家葛前6", 60, 6);
	AddItem("家葛前7", 70, 7);
	AddItem("家葛前8", 80, 8);
	AddItem("家葛前9", 90, 9);
	AddItem("家葛前10", 100, 10);
}

const void CConsumShop::ShowItems() const
{
	for (int i = 0; i < GetNumOfItems(); i++)
		cout << '[' << i + 1 << ']' << " 啊拜 :" << GetItem(i)->GetPrice() << "\t酒捞袍 捞抚 : "
		<< GetItem(i)->GetItemName() << "\t瓤苞 : " << GetItem(i)->GetProperty() << '\n';
}
