#include "stdafx.h"
#include "FieldGS.h"
#include "MonsterGO.h"
#include "PlayerGO.h"
#include "PlayerActionComponent.h"
#include "MonsterActionComponent.h"
#include "StorageComponent.h"

CFieldGS::CFieldGS(CPlayerGO* _cPlayer)
{
	cout << "\n1. 슬라임   2. 스켈레톤   3. 머쉬맘   4. 김태원   5. 전 단계\n";
	CreateMonster(CheckInputRange(1, 5));
	m_cPlayer = _cPlayer;
	m_cPlayerAction = static_cast<CPlayerActionComponent*>(m_cPlayer->GetComponent(typeid(CPlayerActionComponent)));
	m_cMonsterAction = static_cast<CMonsterActionComponent*>(m_cMonster->GetComponent(typeid(CMonsterActionComponent)));
	m_cPlayerStorage = static_cast<CStorageComponent*>(m_cPlayer->GetComponent(typeid(CStorageComponent)));
}

void CFieldGS::CreateMonster(int _iCase)
{
	switch (_iCase)
	{
	case 1:
		m_cMonster = new CMonsterGO(MONSTER::슬라임);
		//m_vecMonster.push_back(new CMonsterGO(MONSTER::슬라임));
		break;
	case 2:
		m_cMonster = new CMonsterGO(MONSTER::스켈레톤);
		break;
	case 3:
		m_cMonster = new CMonsterGO(MONSTER::머쉬맘);
		break;
	case 4:
		m_cMonster = new CMonsterGO(MONSTER::김태원);
		break;
	case 5:
		break;
	}
}

void CFieldGS::Update()
{
	int iInput = 0;
	while (true)
	{
		// GameManager 클래스에서 플레이어의 LOCATION과 STATE를 변경하면서 CFieldGS::Update()나 이런저런 함수 호출하도록 하는건 어떨까
		// 여기도 굳이 CField::Update()가 아니라 GameManager에서 통째로 관리하도록 하고,
		// 게임 매니저는 필드에 플레이어를 매개변수로 전달, 매니저의 Update를 전역함수로 호출. 즉, GameManager를 싱글턴으로.
		// 싱글턴 만들기 전에 우선 Update()를 GameManager()로 옮겨놔야함.
		// 다시 말해 CField::Update()에서는 GameManager::Update()를 호출하고 생성된 몬스터와 플레이어간 상호작용 주우우욱
		// CreateMonster도 GameManager로 옮길 수 있는데, 한번 생각해보자.
		if (m_cPlayer->GetState() == STATE::DEAD)
		{
			m_cPlayerAction->Lose();
			break;
		}
		if (m_cMonster->GetState() == STATE::DEAD)
		{
			m_cPlayerAction->Win(m_cMonster);
			break;
		}

		cout << "1. 전투   2. 인벤토리   3. 도망";
		if (m_cMonster->GetHp() <= 0.1f * m_cMonster->GetMaxHp())
		{
		/*	cout << "   4. 길들이기(아직 미구현): \n";
			CheckInputRange(1, 4);
		}
		else
		{*/
			iInput = CheckInputRange(1, 3);
		}
		switch (iInput)
		{
		case 1:
			m_cPlayerAction->Attack(m_cMonster);
			m_cMonsterAction->Attack(m_cPlayer);
			break;
		case 2:
			m_cPlayerStorage->RenderStorage();
			break;
		case 3:
			return;
		}
		// 여기 페이지 좀 더 만져보고 고치거나 해나가자
		// 
	}
}