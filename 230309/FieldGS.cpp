#include "stdafx.h"
#include "FieldGS.h"
#include "MonsterGO.h"
#include "PlayerGO.h"
#include "PetGO.h"
#include "PlayerActionComponent.h"
#include "MonsterActionComponent.h"
#include "MonsterRenderComponent.h"
#include "StorageComponent.h"
#include "PlayerRenderComponent.h"
#include "PetRenderComponent.h"

CFieldGS::CFieldGS() {}

CFieldGS::CFieldGS(CPlayerGO* _cPlayer)
{
	int iInput;
	cout << "����� ���͸� �����ϼ���\n";
	cout << "\n1. ��ź   2. ���Ű��   3. ��ũ����ư   4. ���¿�   5. �� �ܰ�\n���� : ";
	cin >> iInput;
	CreateMonster(iInput);
	if (m_cMonster == nullptr) return;
	m_cPlayer = _cPlayer;
	m_cPlayerAction = static_cast<CPlayerActionComponent*>(m_cPlayer->GetComponent(typeid(CPlayerActionComponent)));
	m_cMonsterAction = static_cast<CMonsterActionComponent*>(m_cMonster->GetComponent(typeid(CMonsterActionComponent)));
	m_cPlayerStorage = static_cast<CStorageComponent*>(m_cPlayer->GetComponent(typeid(CStorageComponent)));
}

bool CFieldGS::InitField(CPlayerGO* _cPlayer)
{
	int iInput;
	cout << "����� ���͸� �����ϼ���\n";
	cout << "\n1. ��ź   2. ���Ű��   3. ��ũ����ư   4. ���¿�   5. �� �ܰ�\n���� : ";
	cin >> iInput;
	if (5 == iInput) return false;
	CreateMonster(iInput);
	m_cPlayer = _cPlayer;
	m_cPlayerAction = static_cast<CPlayerActionComponent*>(m_cPlayer->GetComponent(typeid(CPlayerActionComponent)));
	m_cMonsterAction = static_cast<CMonsterActionComponent*>(m_cMonster->GetComponent(typeid(CMonsterActionComponent)));
	m_cPlayerStorage = static_cast<CStorageComponent*>(m_cPlayer->GetComponent(typeid(CStorageComponent)));
	return true;
}

void CFieldGS::CreateMonster(int _iCase)
{
	switch (_iCase)
	{
	case 1:
		m_cMonster = new CMonsterGO(MONSTER::��ź);
		//m_vecMonster.push_back(new CMonsterGO(MONSTER::������));
		break;
	case 2:
		m_cMonster = new CMonsterGO(MONSTER::���Ű��);
		break;
	case 3:
		m_cMonster = new CMonsterGO(MONSTER::��ũ����ư);
		break;
	case 4:
		m_cMonster = new CMonsterGO(MONSTER::���¿�);
		break;
	}
}

void CFieldGS::Update()
{
	CPlayerRenderComponent* cPlayerRenderComponent = static_cast<CPlayerRenderComponent*>(m_cPlayer->GetComponent(typeid(CPlayerRenderComponent)));
	CMonsterRenderComponent* cMonsterRenderComponent = static_cast<CMonsterRenderComponent*>(m_cMonster->GetComponent(typeid(CMonsterRenderComponent)));
	CPetRenderComponent* cPetRenderComponent = nullptr;
	int iInput = 0;
	while (true)
	{
		system("cls");
		if (m_cMonster == nullptr) return;
		if (m_cMonster->GetState() == STATE::DEAD)
		{
			m_cPlayerAction->Win(m_cMonster);
			Safe_Delete(m_cMonster);
			return;
		}

		if (m_cPlayer->GetState() == STATE::BLEEDING)
			m_cPlayer->SetHp(m_cPlayer->GetHp() - 5);

		if (m_cPlayer->GetState() == STATE::DEAD)
		{
			m_cPlayerAction->Lose();
			break;
		}

		cPlayerRenderComponent->Render();
		if (m_cPlayer->GetPet() != nullptr)
		{
			if (nullptr == cPetRenderComponent)
				cPetRenderComponent = static_cast<CPetRenderComponent*>(m_cPlayer->GetPet()->GetComponent(typeid(CPetRenderComponent)));
			cPetRenderComponent->Render();
		}
		cMonsterRenderComponent->Render();
		// GameManager Ŭ�������� �÷��̾��� LOCATION�� STATE�� �����ϸ鼭 CFieldGS::Update()�� �̷����� �Լ� ȣ���ϵ��� �ϴ°� ���
		// ���⵵ ���� CField::Update()�� �ƴ϶� GameManager���� ��°�� �����ϵ��� �ϰ�,
		// ���� �Ŵ����� �ʵ忡 �÷��̾ �Ű������� ����, �Ŵ����� Update�� �����Լ��� ȣ��. ��, GameManager�� �̱�������.
		// �̱��� ����� ���� �켱 Update()�� GameManager()�� �Űܳ�����.
		// �ٽ� ���� CField::Update()������ GameManager::Update()�� ȣ���ϰ� ������ ���Ϳ� �÷��̾ ��ȣ�ۿ� �ֿ���
		// CreateMonster�� GameManager�� �ű� �� �ִµ�, �ѹ� �����غ���.

		cout << "1. ����   2. �κ��丮   3. ����\n";
		if (m_cMonster->GetHp() <= 0.1f * m_cMonster->GetMaxHp())
		{
			cout << "   4. ����̱�(���� �̱���): \n";
			cin >> iInput;
		}
		else
		{
			cout << '\n';
			cin >> iInput;
		}

		switch (iInput)
		{
		case 1:
			cout << "1. ����   2. ��� ������\n";
			cin >> iInput;
			switch (iInput)
			{
			case 1:
				m_cPlayerAction->Attack(m_cMonster);
				break;
			case 2:
				m_cPlayerAction->MiniAttack(m_cMonster);
				break;
			}
			m_cMonsterAction->Attack(m_cPlayer);
			break;
		case 2:
			m_cPlayerStorage->RenderStorage();
			break;
		case 3:
			cout << "�̰� ���� ģ�ٰ�?   1. ��   2. �ƴϿ� : ";
			cin >> iInput;
			if (1 == iInput)
			{
				cout << "����\n";
				system("pause");
				return;
			}
			else
			{
				cout << "����";
				system("pause");
				break;
			}
		case 4:
			if (m_cMonster->GetHp() <= 0.1f * m_cMonster->GetMaxHp())
			{
				m_cPlayer->SetPet(m_cMonster);
				cout << "����̱� ����!\n";
				m_cMonster->SetState(STATE::DEAD);
			}
			else
				cout << "���� ����� �� �����ϴ�.\n";
			system("pause");
			break;
		}
	}
}