#include "stdafx.h"
#include "PlayerGO.h"
#include "PlayerRenderComponent.h"
#include "PlayerActionComponent.h"
#include "StorageComponent.h"
#include "ObserverComponent.h"

CPlayerGO::CPlayerGO() : CCreatureGO() {}

void CPlayerGO::InitPlayer(JOB _job)
{
	switch (_job)
	{
	case JOB::전사:
	{ SetName("전사"); m_iHp = 120; m_iDps = 10; m_iDef = 5; m_state = STATE::NORMAL; m_location = LOCATION::LOBBY; }; break;
	case JOB::마법사:
	{ SetName("마법사"); m_iHp = 90; m_iDps = 15; m_iDef = 0; m_state = STATE::NORMAL; m_location = LOCATION::LOBBY; }; break;
	case JOB::도적:
	{ SetName("도적"); m_iHp = 100; m_iDps = 12; m_iDef = 1; m_state = STATE::NORMAL; m_location = LOCATION::LOBBY; }; break;
	}

	AddComponent(new CStorageComponent);
	AddComponent(new CPlayerActionComponent);
	AddComponent(new CPlayerRenderComponent);
}

void CPlayerGO::Update()
{
	// if (m_state == STATE::사망)	// 필드에서 if (player == 사망) 로비로 나가도록
	// Player의 LOCATION에 따라 다른 컴포넌트 멤버 호출하도록 구현
	// 위에꺼는 무시해야할 듯
	if (m_location == LOCATION::DUNGEON)
	{
		// CPlayerActionComponent* pComponent = GetComponent(typeid(CPlayerActionComponent*));
		// Field의 Update에서 CPlayerActionComponent를 호출할 것
		// Field() 
	}
	else if (m_location == LOCATION::SHOP)
	{
		
	}
	else if (m_location == LOCATION::LOBBY)
	{
	}
	else
		cerr << "err: PlayerGO::Update\n";
}

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