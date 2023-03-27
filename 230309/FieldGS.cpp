#include "stdafx.h"
#include "FieldGS.h"
#include "MonsterGO.h"
#include "PlayerGO.h"
#include "PlayerActionComponent.h"
#include "MonsterActionComponent.h"
#include "StorageComponent.h"

CFieldGS::CFieldGS(CPlayerGO* _cPlayer)
{
	cout << "\n1. ������   2. ���̷���   3. �ӽ���   4. ���¿�   5. �� �ܰ�\n";
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
		m_cMonster = new CMonsterGO(MONSTER::������);
		//m_vecMonster.push_back(new CMonsterGO(MONSTER::������));
		break;
	case 2:
		m_cMonster = new CMonsterGO(MONSTER::���̷���);
		break;
	case 3:
		m_cMonster = new CMonsterGO(MONSTER::�ӽ���);
		break;
	case 4:
		m_cMonster = new CMonsterGO(MONSTER::���¿�);
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
		// GameManager Ŭ�������� �÷��̾��� LOCATION�� STATE�� �����ϸ鼭 CFieldGS::Update()�� �̷����� �Լ� ȣ���ϵ��� �ϴ°� ���
		// ���⵵ ���� CField::Update()�� �ƴ϶� GameManager���� ��°�� �����ϵ��� �ϰ�,
		// ���� �Ŵ����� �ʵ忡 �÷��̾ �Ű������� ����, �Ŵ����� Update�� �����Լ��� ȣ��. ��, GameManager�� �̱�������.
		// �̱��� ����� ���� �켱 Update()�� GameManager()�� �Űܳ�����.
		// �ٽ� ���� CField::Update()������ GameManager::Update()�� ȣ���ϰ� ������ ���Ϳ� �÷��̾ ��ȣ�ۿ� �ֿ���
		// CreateMonster�� GameManager�� �ű� �� �ִµ�, �ѹ� �����غ���.
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

		cout << "1. ����   2. �κ��丮   3. ����";
		if (m_cMonster->GetHp() <= 0.1f * m_cMonster->GetMaxHp())
		{
		/*	cout << "   4. ����̱�(���� �̱���): \n";
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
		// ���� ������ �� �� �������� ��ġ�ų� �س�����
		// 
	}
}