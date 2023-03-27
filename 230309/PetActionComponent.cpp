#include "stdafx.h"
#include "PetActionComponent.h"

void CPetActionComponent::Init(CCreatureGO* _cPet)
{
	m_cPet = static_cast<CPetGO*>(_cPet);
}

void CPetActionComponent::Attack(CCreatureGO* _cTarget)
{
	cout << m_cPet->GetName() << "ÀÇ °ø°Ý!\n";

	_cTarget->SetHp(_cTarget->GetHp() - (m_cPet->GetDps() - _cTarget->GetDef()));

	if (0 > _cTarget->GetHp())
		m_cPet->SetHp(0);
	system("pause");
}
