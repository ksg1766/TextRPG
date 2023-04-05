#include "stdafx.h"
#include "ArmorShop.h"
#include "Armor.h"
#include "PlayerGO.h"
#include "StorageComponent.h"

CArmorShop::CArmorShop(CPlayerGO* _cPlayer) : CShop(_cPlayer)
{
	m_cShopStorage->AddItem(new CArmor("��1", 10, 1));
	m_cShopStorage->AddItem(new CArmor("��2", 20, 2));
	m_cShopStorage->AddItem(new CArmor("��3", 30, 3));
	m_cShopStorage->AddItem(new CArmor("��4", 40, 4));
	m_cShopStorage->AddItem(new CArmor("��5", 50, 5));
	m_cShopStorage->AddItem(new CArmor("��6", 60, 6));
	m_cShopStorage->AddItem(new CArmor("��7", 70, 7));
	m_cShopStorage->AddItem(new CArmor("��8", 80, 8));
}