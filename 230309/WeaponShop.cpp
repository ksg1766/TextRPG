#include "stdafx.h"
#include "WeaponShop.h"
#include "Weapon.h"
#include "PlayerGO.h"
#include "StorageComponent.h"

CWeaponShop::CWeaponShop(CPlayerGO* _cPlayer) : CShop(_cPlayer)
{
	m_cShopStorage->AddItem(new CWeapon("公扁1", 10, 1));
	m_cShopStorage->AddItem(new CWeapon("公扁2", 20, 2));
	m_cShopStorage->AddItem(new CWeapon("公扁3", 30, 3));
	m_cShopStorage->AddItem(new CWeapon("公扁4", 40, 4));
	m_cShopStorage->AddItem(new CWeapon("公扁5", 50, 5));
	m_cShopStorage->AddItem(new CWeapon("公扁6", 60, 6));
	m_cShopStorage->AddItem(new CWeapon("公扁7", 70, 7));
	m_cShopStorage->AddItem(new CWeapon("公扁8", 80, 8));
}