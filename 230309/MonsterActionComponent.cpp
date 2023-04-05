#include "stdafx.h"
#include "MonsterActionComponent.h"
#include "MonsterGO.h"
#include "StorageComponent.h"
#include "Mech.h"

CMonsterActionComponent::CMonsterActionComponent(CCreatureGO* _cMonster)
{
	m_cMonster = static_cast<CMonsterGO*>(_cMonster);
}

void CMonsterActionComponent::Init(CCreatureGO* _cMonster)
{
	m_cMonster = static_cast<CMonsterGO*>(_cMonster);
}

void CMonsterActionComponent::Attack(CCreatureGO* _cTarget)
{
	m_pMech(m_cMonster, _cTarget);
}