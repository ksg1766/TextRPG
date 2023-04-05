#include "stdafx.h"
#include "ConsumShop.h"
#include "Potion.h"
#include "PlayerGO.h"
#include "StorageComponent.h"

CConsumShop::CConsumShop(CPlayerGO* _cPlayer) : CShop(_cPlayer)
{
	m_cShopStorage->AddItem(new CPotion("ȸ����1", 10, 10));
	m_cShopStorage->AddItem(new CPotion("ȸ����2", 20, 20));
	m_cShopStorage->AddItem(new CPotion("ȸ����3", 30, 30));
	m_cShopStorage->AddItem(new CPotion("ȸ����4", 40, 40));
	m_cShopStorage->AddItem(new CPotion("ȸ����5", 50, 50));
	m_cShopStorage->AddItem(new CPotion("ȸ����6", 60, 60));
	m_cShopStorage->AddItem(new CPotion("ȸ����7", 70, 70));
	m_cShopStorage->AddItem(new CPotion("ȸ����8", 80, 80));
}