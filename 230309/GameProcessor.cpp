#include "stdafx.h"
#include "GameProcessor.h"
#include "FieldGS.h"
#include "StorageComponent.h"
#include "WeaponShop.h"
#include "ArmorShop.h"
#include "ConsumShop.h"
#include "PlayerRenderComponent.h"
#include "PetRenderComponent.h"
#include "PetGo.h"

bool GameProcessor::InitGame()
{
	cout << "������ �����ϼ���(1. ���ε�   2. �Ҽ�����   3. ��ī����   4. ����) : ";
	int iInput;
	cin >> iInput;
	if (4 == iInput) { m_cPlayer = nullptr; return false; }
	m_cPlayer = new CPlayerGO(static_cast<JOB>(iInput));
	return true;
	// FieldScene ���� ���߿� �߰�
}

void GameProcessor::Update()
{
	CPlayerRenderComponent* cPlayerRenderComponent = static_cast<CPlayerRenderComponent*>(m_cPlayer->GetComponent(typeid(CPlayerRenderComponent)));
	CPetRenderComponent* cPetRenderComponent = nullptr;
	// ���� �ȵ�. ������� �ٽ� �� ��.

	int iInput;
	CStorageComponent* cPlayerStorage = nullptr;
	CShop* cShop = nullptr;

	while (true)
	{
		system("cls");
		if (!m_cPlayer) exit(1);
		if (m_cPlayer->GetState() == STATE::DEAD) { cout << "�� �� ���غ��� �׷����. ��� �����Ͱ� �ʱ�ȭ �˴ϴ٤�.\n"; system("pause"); break; }

		cPlayerRenderComponent->Render();
		if (m_cPlayer->GetPet() != nullptr)
		{
			if (nullptr == cPetRenderComponent)
				cPetRenderComponent = static_cast<CPetRenderComponent*>(m_cPlayer->GetPet()->GetComponent(typeid(CPetRenderComponent)));
			cPetRenderComponent->Render();
		}

		cout << "1. �ʵ�� �̵�   2. �κ��丮   3. ����   4. �� �ܰ�\n";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			m_cField = new CFieldGS();
			if (!(m_cField->InitField(m_cPlayer)))
				break;
			m_cField->Update();

			Safe_Delete(m_cField);
			break;
		case 2:
			cPlayerStorage = static_cast<CStorageComponent*>(m_cPlayer->GetComponent(typeid(CStorageComponent)));
			cPlayerStorage->RenderStorage();
			cPlayerStorage->Use();
			break;
		case 3:
			cout << "1. ���� ����(�̿ϼ�)   2. �� ����(�̿ϼ�)   3. �Ҹ�ǰ ����(ȸ���� ����)   4. �� �ܰ�\n";
			cin >> iInput;
			if (iInput == 4)
				break;
			else if (iInput == 1)
				cShop = new CWeaponShop(m_cPlayer);
			else if (iInput == 2)
				cShop = new CArmorShop(m_cPlayer);
			else if (iInput == 3)
				cShop = new CConsumShop(m_cPlayer);

			cShop->Update();
			break;
		case 4:
			cout << "�Ϻη� �˷����� �ʾҴµ�, ����ų �� ���� �����̱���. ��� �����Ͱ� �ʱ�ȭ �˴ϴ٤�.\n";
			Safe_Delete(m_cPlayer);
			return;
		}
	}
}