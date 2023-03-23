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
	m_cShopStorage->AddItem(new CWeapon("����1", 10, 1));
	m_cShopStorage->AddItem(new CWeapon("����2", 20, 2));
	m_cShopStorage->AddItem(new CWeapon("����3", 30, 3));
	m_cShopStorage->AddItem(new CWeapon("����4", 40, 4));
	m_cShopStorage->AddItem(new CWeapon("����5", 50, 5));
	m_cShopStorage->AddItem(new CWeapon("����6", 60, 6));
	m_cShopStorage->AddItem(new CWeapon("����7", 70, 7));
	m_cShopStorage->AddItem(new CWeapon("����8", 80, 8));
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