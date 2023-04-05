#include "stdafx.h"
#include "PlayerRenderComponent.h"
#include "PlayerGO.h"

CPlayerRenderComponent::CPlayerRenderComponent(CPlayerGO* _cPlayer)
{
	m_cPlayer = _cPlayer;
}

void CPlayerRenderComponent::Init(CPlayerGO* _cPlayer)
{
	m_cPlayer = _cPlayer;
}

void CPlayerRenderComponent::Render()
{
	cout << "==========================================================\n";
	cout << "�̸� : " << m_cPlayer->GetName() << '\n' << "ü�� : " << m_cPlayer->GetHp() << "\t���ݷ� : " << m_cPlayer->GetDps() << "\t���� : " << m_cPlayer->GetDef() << '\n';

	if (m_cPlayer->GetState() == STATE::BLEEDING)
		cout << "!!!���� �����Դϴ�!!!\n";
	cout << "==========================================================\n";
}