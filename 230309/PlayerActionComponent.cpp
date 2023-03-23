#include "stdafx.h"
#include "PlayerActionComponent.h"
#include "PlayerGO.h"

void CPlayerActionComponent::Attack(CCreatureGO* _cTarget)
{
	_cTarget->SetHp(_cTarget->GetHp() - (m_cPlayer->GetDps() - _cTarget->GetDef()));

	if (0 > _cTarget->GetHp())
		m_cPlayer->SetHp(0);
}

void CPlayerActionComponent::Init(CPlayerGO* _cPlayer)
{
	m_cPlayer = _cPlayer;
}
