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
	AddItem("�Ҹ�ǰ1", 10, 1);
	AddItem("�Ҹ�ǰ2", 20, 2);
	AddItem("�Ҹ�ǰ3", 30, 3);
	AddItem("�Ҹ�ǰ4", 40, 4);
	AddItem("�Ҹ�ǰ5", 50, 5);
	AddItem("�Ҹ�ǰ6", 60, 6);
	AddItem("�Ҹ�ǰ7", 70, 7);
	AddItem("�Ҹ�ǰ8", 80, 8);
	AddItem("�Ҹ�ǰ9", 90, 9);
	AddItem("�Ҹ�ǰ10", 100, 10);
}

const void CConsumShop::ShowItems() const
{
	for (int i = 0; i < GetNumOfItems(); i++)
		cout << '[' << i + 1 << ']' << " ���� :" << GetItem(i)->GetPrice() << "\t������ �̸� : "
		<< GetItem(i)->GetItemName() << "\tȿ�� : " << GetItem(i)->GetProperty() << '\n';
}
