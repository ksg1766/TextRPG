#include "stdafx.h"
#include "MonsterActionComponent.h"
#include "MonsterGO.h"
#include "StorageComponent.h"

void CMonsterActionComponent::Init(CCreatureGO* _cMonster)
{
	m_cMonster = static_cast<CMonsterGO*>(_cMonster);
}

void CMonsterActionComponent::Attack(CCreatureGO* _cTarget)
{
	cout << m_cMonster->GetName() << "ÀÇ °ø°Ý!\n";

	_cTarget->SetHp(_cTarget->GetHp() - (m_cMonster->GetDps() - _cTarget->GetDef()));

	if (0 > _cTarget->GetHp())
		_cTarget->SetHp(0);
	system("pause");
}
