#include "stdafx.h"
#include "PetRenderComponent.h"
#include "PetGO.h"

CPetRenderComponent::CPetRenderComponent(CPetGO* _cPet)
{
	m_cPet = _cPet;
}

void CPetRenderComponent::Init(CPetGO* _cPet)
{
	m_cPet = _cPet;
}

void CPetRenderComponent::Render()
{
	cout << "==========================================================\n";
	cout << "이름 : " << m_cPet->GetName() << '\n' << "체력 : " << m_cPet->GetHp() << "\t공격력 : " << m_cPet->GetDps() << "\t방어력 : " << m_cPet->GetDef() << '\n';

	if (m_cPet->GetState() == STATE::BLEEDING)
		cout << "!!!출혈 상태입니다!!!\n";
	cout << "==========================================================\n";
}