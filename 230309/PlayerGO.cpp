#include "stdafx.h"
#include "PlayerGO.h"
#include "PlayerRenderComponent.h"
#include "ActionComponent.h"
#include "StorageComponent.h"
#include "ObserverComponent.h"

inline CPlayerGO::CPlayerGO(const char* _szName) :CCreatureGO(_szName), m_cPet(nullptr)
{
	m_iHp = 100;
	m_iDps = 10;
	m_iDef = 0;
	m_state = STATE::Á¤»ó;

	AddComponent(new CStorageComponent);
	AddComponent(new CActionComponent);
	AddComponent(new CPlayerRenderComponent);
	//AddComponent(new CObserverComponent);
}