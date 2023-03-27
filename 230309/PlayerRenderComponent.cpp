#include "stdafx.h"
#include "PlayerRenderComponent.h"
#include "PlayerGO.h"

void CPlayerRenderComponent::Init(CPlayerGO* _cPlayer)
{
	m_cPlayer = _cPlayer;
}

void CPlayerRenderComponent::Render()
{
	cout << "==========================================================\n";
	cout << "이름 : " << m_cPlayer->GetName() << '\n' << "체력 : " << m_cPlayer->GetHp() << "\t공격력 : " << m_cPlayer->GetDps() << "\t방어력 : " << m_cPlayer->GetDef() << '\n';

	if (m_cPlayer->GetCondition() == STATE::출혈)
		cout << "!!!출혈 상태입니다!!!\n";
	cout << "==========================================================\n";
}