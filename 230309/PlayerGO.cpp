#include "stdafx.h"
#include "PlayerGO.h"
#include "PetGO.h"
#include "PlayerRenderComponent.h"
#include "PlayerActionComponent.h"
#include "StorageComponent.h"
#include "ObserverComponent.h"

CPlayerGO::CPlayerGO(JOB _job)
{
	switch (_job)
	{
	case JOB::워로드:
	{ SetName("워로드"); m_iMaxHp = 120;  m_iHp = m_iMaxHp; m_iDps = 10; m_iDef = 5; m_state = STATE::NORMAL; m_cPet = nullptr; m_location = LOCATION::LOBBY; }; break;
	case JOB::소서리스:
	{ SetName("소서리스"); m_iMaxHp = 90;  m_iHp = m_iMaxHp; m_iDps = 15; m_iDef = 0; m_state = STATE::NORMAL; m_cPet = nullptr; m_location = LOCATION::LOBBY; }; break;
	case JOB::스카우터:
	{ SetName("스카우터"); m_iMaxHp = 100; m_iHp = m_iMaxHp; m_iDps = 12; m_iDef = 1; m_state = STATE::NORMAL; m_cPet = nullptr; m_location = LOCATION::LOBBY; }; break;
	}

	AddComponent(new CStorageComponent(this));
	AddComponent(new CPlayerActionComponent(this));
	AddComponent(new CPlayerRenderComponent(this));
}

CPlayerGO* CPlayerGO::InitPlayer(JOB _job)
{
	switch (_job)
	{
	case JOB::워로드:
	{ SetName("워로드"); m_iHp = 120; m_iDps = 10; m_iDef = 5; m_state = STATE::NORMAL; m_cPet = nullptr; m_location = LOCATION::LOBBY; }; break;
	case JOB::소서리스:
	{ SetName("소서리스"); m_iHp = 90; m_iDps = 15; m_iDef = 0; m_state = STATE::NORMAL; m_cPet = nullptr; m_location = LOCATION::LOBBY; }; break;
	case JOB::스카우터:
	{ SetName("스카우터"); m_iHp = 100; m_iDps = 12; m_iDef = 1; m_state = STATE::NORMAL; m_cPet = nullptr; m_location = LOCATION::LOBBY; }; break;
	}

	AddComponent(new CStorageComponent(this));
	AddComponent(new CPlayerActionComponent(this));
	AddComponent(new CPlayerRenderComponent(this));

	return this;
}

CPlayerGO::~CPlayerGO()
{
	Safe_Delete(m_cPet);
	for (CItem* c : m_vecItemList)
		Safe_Delete(c);
}

void CPlayerGO::SetPet(CMonsterGO* _cTarget)
{
	m_cPet = new CPetGO(_cTarget, this);
}

//void CPlayerGO::Update()
//{
//	if (m_location == LOCATION::DUNGEON)
//	{
//	}
//	else if (m_location == LOCATION::SHOP)
//	{
//		
//	}
//	else if (m_location == LOCATION::LOBBY)
//	{
//	}
//	else
//		cerr << "err: PlayerGO::Update\n";
//}

//inline CPlayerGO::CPlayerGO(const char* _szName) :CCreatureGO(_szName), m_cPet(nullptr)
//{
//	m_iHp = 100;
//	m_iDps = 10;
//	m_iDef = 0;
//	m_location = LOCATION::LOGIN;
//
//
//	AddComponent(new CStorageComponent);
//	AddComponent(new CPlayerActionComponent);
//	AddComponent(new CPlayerRenderComponent);
//	//AddComponent(new CObserverComponent);
//}