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
	cout << "�̸� : " << m_cMonster->GetName() << '\n' << "ü�� : " << m_cMonster->GetHp() << "\t���ݷ� : " << m_cMonster->GetDps() << "\t���� : " << m_cMonster->GetDef() << '\n';

	if (m_cMonster->GetState() == STATE::����)
		cout << "!!!���� �����Դϴ�!!!\n";
	cout << "==========================================================\n";
}
