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
	m_cShopStorage->AddItem(new CConsumable("�Ҹ�ǰ1", 10, 1));
	m_cShopStorage->AddItem(new CConsumable("�Ҹ�ǰ2", 20, 2));
	m_cShopStorage->AddItem(new CConsumable("�Ҹ�ǰ3", 30, 3));
	m_cShopStorage->AddItem(new CConsumable("�Ҹ�ǰ4", 40, 4));
	m_cShopStorage->AddItem(new CConsumable("�Ҹ�ǰ5", 50, 5));
	m_cShopStorage->AddItem(new CConsumable("�Ҹ�ǰ6", 60, 6));
	m_cShopStorage->AddItem(new CConsumable("�Ҹ�ǰ7", 70, 7));
	m_cShopStorage->AddItem(new CConsumable("�Ҹ�ǰ8", 80, 8));
}