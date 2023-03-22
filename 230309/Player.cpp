#include "stdafx.h"
#include "Player.h"
#include "Pet.h"
#include "Inventory.h"
#include "Item.h"

//CPlayer* CPlayer::cInstance = nullptr;

//CPlayer& CPlayer::GetInstance(const char* _class, int _hp, int _dps, int _def, const int _state, bool _isDead)
//{
//	// �ν��Ͻ��� ���� �������� �ʾҴٸ� ���� ����
//	if (cInstance == nullptr)
//		cInstance = new CPlayer(_class, _hp, _dps, _def);
//	// �ν��Ͻ��� �̹� �����Ǿ� �ִٸ� ���� �ν��Ͻ� ��ȯ
//	return *cInstance;
//}

CPlayer::CPlayer() : CCreature(), m_iState(STATE::����), m_iNumOfItems(0), cInventory(nullptr), cPet(nullptr)
{
	for (int i = 0; i < 20; i++)
		m_cItemList[i] = nullptr;
}

CPlayer::CPlayer(const char* _class, int _hp, int _dps, int _def, const int _state, bool _isDead)
	:CCreature(_class, _hp, _dps, _def, _isDead), m_iState(_state), m_iNumOfItems(0), cInventory(nullptr), cPet(nullptr)
{
	for (int i = 0; i < 20; i++)
		m_cItemList[i] = nullptr;
}

CPlayer::CPlayer(const CPlayer& rhs)
	: CCreature(rhs.GetName(), rhs.GetHp(), rhs.GetDps(), rhs.GetDef(), false),
		m_iState(rhs.m_iState), m_iNumOfItems(rhs.m_iNumOfItems), cInventory(rhs.cInventory), cPet(rhs.cPet) , cObserver(nullptr)
{
	for (int i = 0; i < 20; i++)
		m_cItemList[i] = new CItem(*rhs.m_cItemList[i]);
}

void CPlayer::AddObserver(CObserver* observer)
{
	cObserver = observer;
}

//void CPlayer::RemoveObserver()
//{
//	SAFE_DELETE(cObserver);
//}

void CPlayer::NotifyObserver()
{
	cObserver->Update(this);
}

void CPlayer::NotifyObserver(CBaseCreature* _monster)
{
	cObserver->Update(this, _monster);
}

void CPlayer::Fight(CCreature* _monster)
{
	cout << "1. ����   2. ��� ������\n";
	int iInput = CheckInputRange(1, 2);
	if (iInput == 1)
		Attack(_monster);
	else
		MiniAttack(_monster);

	if (_monster->GetHp() > 0)
	{
		if (_monster->GetDps() > GetDef())
			_monster->Attack(this);

		if (!strcmp(_monster->GetName(), "���"))
		{
			if (GetState() == STATE::�ߵ�)
				Hit(0.05f * static_cast<int>(GetMaxHp()));
			else
				SetState(STATE::�ߵ�);
		}
		if (GetHp() <= 0)
		{
			SetHp(0);
			return;
		}
	}
	else
	{
		//AddItem("ȸ����", 1);
		AddItem(new CItem("ȸ����", 50, 30));
		cout << "ȸ������ ȹ���Ͽ����ϴ�.\n\n";
		cout << "�¸�\n";
		system("pause");
		return;
	}
}

void CPlayer::MiniAttack(CCreature* _enemy)
{
	_enemy->Hit(1);
}

void CPlayer::SetState(const int& _state)
{
	m_iState = _state;
}
int CPlayer::GetState() const
{
	return m_iState;
}

void CPlayer::SetPet(CCreature* _monster)
{
	if (cPet)
		delete cPet;
	cPet = new CPet(_monster, this);
	cPet->SetName("������");
}

CPet& CPlayer::GetPet()
{
	return *cPet;
}

CInventory* CPlayer::LoadInventory()
{
	cInventory = new CInventory(this);
	return cInventory;
}

void CPlayer::CloseInventory()
{
	SAFE_DELETE(cInventory);
}

void CPlayer::SetItemCount(int i)
{
	m_iNumOfItems = i;
}

int CPlayer::GetItemCount() const
{
	return m_iNumOfItems;
}

//void CPlayer::AddItem(const char* _szItemName, int i)
//{
//	strcpy_s(m_cItems[m_iItemCount], 10, _szItemName);
//	m_iItemCount += i;
//}

void CPlayer::AddItem(CItem* _cItem)
{
	m_cItemList[m_iNumOfItems] = _cItem;
	++m_iNumOfItems;
}

void CPlayer::SubItem(int _iIndex)
{
	SAFE_DELETE(m_cItemList[_iIndex])
	for (int i = _iIndex; i < m_iNumOfItems - 1; ++i)
		m_cItemList[i] = m_cItemList[i + 1];
	--m_iNumOfItems;
}

const CItem* CPlayer::GetItems(int i) const
{
	return m_cItemList[i];
}

void CPlayer::Render() const
{
	cout << "==========================================================";
	cout << "\n�̸� : " << GetName() << '\n' << "ü�� : " << GetHp() << "\t���ݷ� : " << GetDps() << "\t���� : " << GetDef();

	if (GetState() == STATE::�ߵ�)
		cout << "\n!!!�ߵ� �����Դϴ�!!!";
	cout << "\n==========================================================";
}