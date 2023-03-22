#include "stdafx.h"
#include "ArmorShop.h"
#include "Creature.h"
#include "Armor.h"

CArmorShop::CArmorShop() : CShop()
{
}

CArmorShop::CArmorShop(const CArmorShop& rhs)
{
}

CArmorShop::CArmorShop(CCreature* _creature) : CShop(_creature)
{
	AddItem("规绢备1", 10, 1);
	AddItem("规绢备2", 20, 2);
	AddItem("规绢备3", 30, 3);
	AddItem("规绢备4", 40, 4);
	AddItem("规绢备5", 50, 5);
	AddItem("规绢备6", 60, 6);
	AddItem("规绢备7", 70, 7);
	AddItem("规绢备8", 80, 8);
	AddItem("规绢备9", 90, 9);
	AddItem("规绢备10", 100, 10);
}

const void CArmorShop::ShowItems() const
{
	for (int i = 0; i < GetNumOfItems(); i++)
		cout << '[' << i + 1 << ']' << " 啊拜 :" << GetItem(i)->GetPrice() << "\t酒捞袍 捞抚 : "
		<< GetItem(i)->GetItemName() << "\t规绢仿 : " << GetItem(i)->GetProperty() << '\n';
} 