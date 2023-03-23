#include "stdafx.h"
#include "WeaponShop.h"
#include "Weapon.h"
#include "PlayerGO.h"
#include "StorageComponent.h"

CWeaponShop::CWeaponShop() : CShop()
{
}

CWeaponShop::CWeaponShop(const CWeaponShop& rhs)
{

}

CWeaponShop::CWeaponShop(CPlayerGO* _cPlayer) : CShop(_cPlayer)
{
	m_cShopStorage->AddItem(new CWeapon("무기1", 10, 1));
	m_cShopStorage->AddItem(new CWeapon("무기2", 20, 2));
	m_cShopStorage->AddItem(new CWeapon("무기3", 30, 3));
	m_cShopStorage->AddItem(new CWeapon("무기4", 40, 4));
	m_cShopStorage->AddItem(new CWeapon("무기5", 50, 5));
	m_cShopStorage->AddItem(new CWeapon("무기6", 60, 6));
	m_cShopStorage->AddItem(new CWeapon("무기7", 70, 7));
	m_cShopStorage->AddItem(new CWeapon("무기8", 80, 8));
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