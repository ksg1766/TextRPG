#include "stdafx.h"
#include "ConsumShop.h"
#include "Consumable.h"
#include "PlayerGO.h"
#include "StorageComponent.h"

CConsumShop::CConsumShop() : CShop()
{
}

CConsumShop::CConsumShop(const CConsumShop& rhs)
{
}

CConsumShop::CConsumShop(CPlayerGO* _cPlayer) : CShop(_cPlayer)
{
	m_cShopStorage->AddItem(new CConsumable("家葛前1", 10, 1));
	m_cShopStorage->AddItem(new CConsumable("家葛前2", 20, 2));
	m_cShopStorage->AddItem(new CConsumable("家葛前3", 30, 3));
	m_cShopStorage->AddItem(new CConsumable("家葛前4", 40, 4));
	m_cShopStorage->AddItem(new CConsumable("家葛前5", 50, 5));
	m_cShopStorage->AddItem(new CConsumable("家葛前6", 60, 6));
	m_cShopStorage->AddItem(new CConsumable("家葛前7", 70, 7));
	m_cShopStorage->AddItem(new CConsumable("家葛前8", 80, 8));
}