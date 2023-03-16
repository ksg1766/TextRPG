#include "stdafx.h"
#include "Player.h"
#include "Pet.h"
#include "Inventory.h"

//CPlayer* CPlayer::cInstance = nullptr;

//CPlayer& CPlayer::GetInstance(const char* _class, int _hp, int _dps, int _def, const int _state, bool _isDead)
//{
//	// 인스턴스가 아직 생성되지 않았다면 새로 생성
//	if (cInstance == nullptr)
//		cInstance = new CPlayer(_class, _hp, _dps, _def);
//	// 인스턴스가 이미 생성되어 있다면 기존 인스턴스 반환
//	return *cInstance;
//}

CPlayer::CPlayer() : CCreature(), m_iState(STATE::정상), m_iItemCount(0), cInventory(nullptr), cPet(nullptr)
{
	::memset(m_cItems, 0, sizeof(char) * 100);
}

CPlayer::CPlayer(const char* _class, int _hp, int _dps, int _def, const int _state, bool _isDead)
	:CCreature(_class, _hp, _dps, _def, _isDead), m_iState(_state), m_iItemCount(0), cInventory(nullptr), cPet(nullptr)
{
	::memset(m_cItems, 0, sizeof(char) * 100);
}

CPlayer::CPlayer(const CPlayer& rhs)
	: CCreature(rhs.GetName(), rhs.GetHp(), rhs.GetDps(), rhs.GetDef(), false),
		m_iState(rhs.m_iState), m_iItemCount(rhs.m_iItemCount), cInventory(rhs.cInventory), cPet(rhs.cPet) {}

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
	cout << "1. 공격   2. 살살 때리기\n";
	int iInput = CheckInputRange(1, 2);
	if (iInput == 1)
		Attack(_monster);
	else
		MiniAttack(_monster);

	if (_monster->GetHp() > 0)
	{
		if (_monster->GetDps() > GetDef())
			_monster->Attack(this);

		if (!strcmp(_monster->GetName(), "고급"))
		{
			if (GetState() == STATE::중독)
				Hit(0.05f * GetMaxHp());
			else
				SetState(STATE::중독);
		}
		if (GetHp() <= 0)
		{
			SetHp(0);
			return;
		}
	}
	else
	{
		AddItems("회복약", 1);
		cout << "회복약을 획득하였습니다.\n\n";
		cout << "승리\n";
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
	cPet->SetName("딸래미");
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
	m_iItemCount = i;
}

int CPlayer::GetItemCount() const
{
	return m_iItemCount;
}

void CPlayer::AddItems(const char* _szItemName, int i)
{
	strcpy_s(m_cItems[m_iItemCount], 10, _szItemName);
	m_iItemCount += i;
}

const char* CPlayer::GetItems(int i) const
{
	return m_cItems[i];
}

void CPlayer::Render() const
{
	cout << "==========================================================";
	cout << "\n이름 : " << GetName() << '\n' << "체력 : " << GetHp() << "\t공격력 : " << GetDps() << "\t방어력 : " << GetDef();

	if (GetState() == STATE::중독)
		cout << "\n!!!중독 상태입니다!!!";
	cout << "\n==========================================================";
}