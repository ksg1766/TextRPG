#include "stdafx.h"
#include "ArmorShop.h"
#include "Armor.h"
#include "PlayerGO.h"
#include "StorageComponent.h"

CArmorShop::CArmorShop(CPlayerGO* _cPlayer) : CShop(_cPlayer)
{
	m_cShopStorage->AddItem(new CArmor("规绢备1", 10, 1));
	m_cShopStorage->AddItem(new CArmor("规绢备2", 20, 2));
	m_cShopStorage->AddItem(new CArmor("规绢备3", 30, 3));
	m_cShopStorage->AddItem(new CArmor("规绢备4", 40, 4));
	m_cShopStorage->AddItem(new CArmor("规绢备5", 50, 5));
	m_cShopStorage->AddItem(new CArmor("规绢备6", 60, 6));
	m_cShopStorage->AddItem(new CArmor("规绢备7", 70, 7));
	m_cShopStorage->AddItem(new CArmor("规绢备8", 80, 8));
}