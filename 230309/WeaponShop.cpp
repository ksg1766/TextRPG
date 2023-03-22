#include "stdafx.h"
#include "WeaponShop.h"
//#include "Creature.h"
//#include "Item.h"
#include "Weapon.h"
#include "Player.h"

CWeaponShop::CWeaponShop() : CShop()
{
}

CWeaponShop::CWeaponShop(const CWeaponShop& rhs)
{

}

CWeaponShop::CWeaponShop(CCreature* _creature) : CShop(_creature)
{
	AddItem("무기1", 10, 1);
	AddItem("무기2", 20, 2);
	AddItem("무기3", 30, 3);
	AddItem("무기4", 40, 4);
	AddItem("무기5", 50, 5);
	AddItem("무기6", 60, 6);
	AddItem("무기7", 70, 7);
	AddItem("무기8", 80, 8);
	AddItem("무기9", 90, 9);
	AddItem("무기10", 100, 10);
}

CWeaponShop::~CWeaponShop()
{

}

const void CWeaponShop::ShowItems() const
{
	for (int i = 0; i < GetNumOfItems(); ++i)
		cout << '[' << i + 1 << ']' << " 가격 :" << GetItem(i)->GetPrice() << "\t아이템 이름 : "
			<< GetItem(i)->GetItemName() << "\t공격력 : " << GetItem(i)->GetProperty() << '\n';
}