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
	cout << "상대할 몬스터를 선택하세요\n";
	cout << "\n1. 발탄   2. 비아키스   3. 쿠크세이튼   4. 김태원   5. 전 단계\n선택 : ";
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
	cout << "상대할 몬스터를 선택하세요\n";
	cout << "\n1. 발탄   2. 비아키스   3. 쿠크세이튼   4. 김태원   5. 전 단계\n선택 : ";
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
		m_cMonster = new CMonsterGO(MONSTER::발탄);
		//m_vecMonster.push_back(new CMonsterGO(MONSTER::슬라임));
		break;
	case 2:
		m_cMonster = new CMonsterGO(MONSTER::비아키스);
		break;
	case 3:
		m_cMonster = new CMonsterGO(MONSTER::쿠크세이튼);
		break;
	case 4:
		m_cMonster = new CMonsterGO(MONSTER::김태원);
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
		// GameManager 클래스에서 플레이어의 LOCATION과 STATE를 변경하면서 CFieldGS::Update()나 이런저런 함수 호출하도록 하는건 어떨까
		// 여기도 굳이 CField::Update()가 아니라 GameManager에서 통째로 관리하도록 하고,
		// 게임 매니저는 필드에 플레이어를 매개변수로 전달, 매니저의 Update를 전역함수로 호출. 즉, GameManager를 싱글턴으로.
		// 싱글턴 만들기 전에 우선 Update()를 GameManager()로 옮겨놔야함.
		// 다시 말해 CField::Update()에서는 GameManager::Update()를 호출하고 생성된 몬스터와 플레이어간 상호작용 주우우욱
		// CreateMonster도 GameManager로 옮길 수 있는데, 한번 생각해보자.

		cout << "1. 공격   2. 인벤토리   3. 도망\n";
		if (m_cMonster->GetHp() <= 0.1f * m_cMonster->GetMaxHp())
		{
			cout << "   4. 길들이기(아직 미구현): \n";
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
			cout << "1. 공격   2. 살살 때리기\n";
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
			cout << "이걸 런을 친다고?   1. 네   2. 아니오 : ";
			cin >> iInput;
			if (1 == iInput)
			{
				cout << "ㅌㅌ\n";
				system("pause");
				return;
			}
			else
			{
				cout << "ㄲㄲ";
				system("pause");
				break;
			}
		case 4:
			if (m_cMonster->GetHp() <= 0.1f * m_cMonster->GetMaxHp())
			{
				m_cPlayer->SetPet(m_cMonster);
				cout << "길들이기 성공!\n";
				m_cMonster->SetState(STATE::DEAD);
			}
			else
				cout << "아직 길들일 수 없습니다.\n";
			system("pause");
			break;
		}
	}
}