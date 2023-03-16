#include "stdafx.h"
#include "Pet.h"
#include "Player.h"

void CPet::Heal(CCreature* _object)
{
	_object->SetHp(_object->GetHp() + 10);
	cout << GetName() << "�� ġ�� ��ų�� ü���� 10 ȸ���Ͽ����ϴ�.\n";
}

void CPet::Reviving()
{
	if (m_ReviveCount == 0)	// �һ� ���� Ƚ�� Ȯ��
	{
		cout << "�һ� ��ų ��� Ƚ�� ����\n";
		return;
	}

	bool isTamerDead = cTamer->GetIsDead();	// �÷��̾� ���� Ȯ��
	if (isTamerDead)
	{
		cTamer->SetIsDead(isTamerDead);
		--m_ReviveCount;
	}
	else
		cout << "�÷��̾ ���� ����ֽ��ϴ�\n";
}

void CPet::Render() const
{
	cout << "\n==============================================================================";
	cout << "\n�� �̸� : " << GetName() << '\n' << "ü�� : " << GetHp() << "\t���ݷ� : " << GetDps() << "\t���� : " << GetDef() << "\t���� �һ� ��ų Ƚ��: " << GetRevive();

	if (GetState() == STATE::�ߵ�)
		cout << "\n!!!�ߵ� �����Դϴ�!!!";
	cout << "\n==============================================================================";
}

CPet::CPet(const CPet& rhs) 
	: CCreature(rhs.GetName(), rhs.GetHp(), rhs.GetDps(), rhs.GetDef(), false),
		m_iState(rhs.m_iState), m_ReviveCount(rhs.m_ReviveCount), cTamer(rhs.cTamer) {}

void CPet::AddObserver(CObserver* observer)
{
	cObserver = observer;
}

//void CPet::RemoveObserver()
//{
//	SAFE_DELETE(cObserver);
//}

void CPet::NotifyObserver()
{
	cObserver->Update(this);
}

void CPet::NotifyObserver(CBaseCreature* _monster)
{
	cObserver->Update(&GetTamer(), _monster);
}

void CPet::PetSkill(CCreature* _monster)
{
	cout << "1. �� ����   2. �÷��̾� ü�� ȸ��   3. �� ü�� ȸ��\n";
	int iInput = CheckInputRange(1, 3);
	NotifyObserver(_monster);
	if (iInput == 1)
		Fight(_monster);
	else if (iInput == 2)
		Heal(cTamer);
	else
		Heal(this);
	//NotifyObserver(_monster);
}

void CPet::Fight(CCreature* _monster)
{
	Attack(_monster);

	cout << "�� ����!\n";
	if (_monster->GetHp() > 0)							// ���Ͱ� ����ִٸ� ����
	{
		if (_monster->GetDps() > GetDef())
			_monster->Attack(this);					// ������ ������ ���ݷº��� ���ٸ� ü���� ȸ���� �� �����Ƿ� �ǳʶٱ�

		if (!strcmp(_monster->GetName(), "���"))		// ��� �ʵ��� �ǰ� �� �ߵ����� �ο�
		{
			if (GetState() == STATE::�ߵ�)
				Hit(5);
			else
				SetState(STATE::�ߵ�);			// ù �� ���� ���� ü�� �ϴ� 5�� ����
		}

		if (GetHp() <= 0)						// ���ʹ� ����ִµ� ���� �׾��ٸ�
		{
			SetHp(0);							// �� ü�� 0���� ����
			return;
		}
	}
	else										// ���ʹ� �װ� ���� ����ִٸ� �¸� �� ����� ����
	{
		cTamer->AddItems("ȸ����", 1);
		cout << "ȸ������ ȹ���Ͽ����ϴ�.\n\n";
		cout << "�¸�\n";
		system("pause");
		return;
	}
}

void CPet::SetState(const int& _state)
{
	m_iState = _state;
}

int CPet::GetState() const
{
	return m_iState;
}

int CPet::GetRevive() const
{
	return m_ReviveCount;
}

CPlayer& CPet::GetTamer()
{
	return *cTamer;
}
