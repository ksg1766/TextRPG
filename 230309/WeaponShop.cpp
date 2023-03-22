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
	AddItem("����1", 10, 1);
	AddItem("����2", 20, 2);
	AddItem("����3", 30, 3);
	AddItem("����4", 40, 4);
	AddItem("����5", 50, 5);
	AddItem("����6", 60, 6);
	AddItem("����7", 70, 7);
	AddItem("����8", 80, 8);
	AddItem("����9", 90, 9);
	AddItem("����10", 100, 10);
}

CWeaponShop::~CWeaponShop()
{

}

const void CWeaponShop::ShowItems() const
{
	for (int i = 0; i < GetNumOfItems(); ++i)
		cout << '[' << i + 1 << ']' << " ���� :" << GetItem(i)->GetPrice() << "\t������ �̸� : "
			<< GetItem(i)->GetItemName() << "\t���ݷ� : " << GetItem(i)->GetProperty() << '\n';
}