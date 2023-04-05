#include "stdafx.h"
#include "PetGO.h"
#include "MonsterGO.h"
#include "PlayerGO.h"
#include "PetRenderComponent.h"
#include "PetActionComponent.h"

CPetGO::CPetGO() :CCreatureGO(), m_cTamer(nullptr)
{}

CPetGO::CPetGO(const char* _szName, CPlayerGO* _cPlayer): CCreatureGO(), m_cTamer(_cPlayer)
{
	//

	AddComponent(new CPetActionComponent(this));
	AddComponent(new CPetRenderComponent(this));
}

CPetGO::CPetGO(CMonsterGO* _cTarget, CPlayerGO* _cPlayer) : m_cTamer(_cPlayer)
{
	SetName("µþ·¡¹Ì");
	SetMaxHp(_cTarget->GetMaxHp() / 2);
	SetHp(GetMaxHp());
	SetDps(_cTarget->GetDps());
	SetDef(_cTarget->GetDef());
	SetState(STATE::NORMAL);

	AddComponent(new CPetActionComponent(this));
	AddComponent(new CPetRenderComponent(this));
}

CPetGO::~CPetGO()
{
	//for (CItem* c : m_vecItemList)
	//	Safe_Delete(c);
}
