#include "stdafx.h"
#include "ConsumShop.h"
#include "Potion.h"
#include "PlayerGO.h"
#include "StorageComponent.h"

CConsumShop::CConsumShop(CPlayerGO* _cPlayer) : CShop(_cPlayer)
{
	m_cShopStorage->AddItem(new CPotion("회복약1", 10, 10));
	m_cShopStorage->AddItem(new CPotion("회복약2", 20, 20));
	m_cShopStorage->AddItem(new CPotion("회복약3", 30, 30));
	m_cShopStorage->AddItem(new CPotion("회복약4", 40, 40));
	m_cShopStorage->AddItem(new CPotion("회복약5", 50, 50));
	m_cShopStorage->AddItem(new CPotion("회복약6", 60, 60));
	m_cShopStorage->AddItem(new CPotion("회복약7", 70, 70));
	m_cShopStorage->AddItem(new CPotion("회복약8", 80, 80));
}