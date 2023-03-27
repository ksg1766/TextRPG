#include "stdafx.h"
#include "PetRenderComponent.h"
#include "PetGO.h"

void CPetRenderComponent::Init(CPetGO* _cPet)
{
	m_cPet = _cPet;
}

void CPetRenderComponent::Render()
{
	cout << "==========================================================\n";
	cout << "�̸� : " << m_cPet->GetName() << '\n' << "ü�� : " << m_cPet->GetHp() << "\t���ݷ� : " << m_cPet->GetDps() << "\t���� : " << m_cPet->GetDef() << '\n';

	if (m_cPet->GetCondition() == STATE::����)
		cout << "!!!���� �����Դϴ�!!!\n";
	cout << "==========================================================\n";
}
