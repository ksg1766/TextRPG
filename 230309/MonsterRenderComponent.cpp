#include "stdafx.h"
#include "MonsterRenderComponent.h"
#include "MonsterGO.h"

void CMonsterRenderComponent::Init(CMonsterGO* _cMonster)
{
	m_cMonster = _cMonster;
}

void CMonsterRenderComponent::Render()
{
	cout << "==========================================================\n";
	cout << "이름 : " << m_cMonster->GetName() << '\n' << "체력 : " << m_cMonster->GetHp() << "\t공격력 : " << m_cMonster->GetDps() << "\t방어력 : " << m_cMonster->GetDef() << '\n';

	if (m_cMonster->GetState() == STATE::출혈)
		cout << "!!!출혈 상태입니다!!!\n";
	cout << "==========================================================\n";
}
