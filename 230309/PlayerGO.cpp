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
	case JOB::����:
	{ SetName("����"); m_iHp = 120; m_iDps = 10; m_iDef = 5; m_state = STATE::NORMAL; m_location = LOCATION::LOBBY; }; break;
	case JOB::������:
	{ SetName("������"); m_iHp = 90; m_iDps = 15; m_iDef = 0; m_state = STATE::NORMAL; m_location = LOCATION::LOBBY; }; break;
	case JOB::����:
	{ SetName("����"); m_iHp = 100; m_iDps = 12; m_iDef = 1; m_state = STATE::NORMAL; m_location = LOCATION::LOBBY; }; break;
	}

	AddComponent(new CStorageComponent);
	AddComponent(new CPlayerActionComponent);
	AddComponent(new CPlayerRenderComponent);
}

void CPlayerGO::Update()
{
	// if (m_state == STATE::���)	// �ʵ忡�� if (player == ���) �κ�� ��������
	// Player�� LOCATION�� ���� �ٸ� ������Ʈ ��� ȣ���ϵ��� ����
	// �������� �����ؾ��� ��
	if (m_location == LOCATION::DUNGEON)
	{
		// CPlayerActionComponent* pComponent = GetComponent(typeid(CPlayerActionComponent*));
		// Field�� Update���� CPlayerActionComponent�� ȣ���� ��
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