#include "stdafx.h"
#include "Creature.h"

CCreature::CCreature() : m_iMaxHp(0), m_iHp(0), m_iDps(0), m_iDef(0), m_isDead(false)
{
	//szClass;
}

CCreature::CCreature(const char* _class, int _maxHp, int _dps, int _def, bool _dead)
	: m_iMaxHp(_maxHp), m_iHp(_maxHp), m_iDps(_dps), m_iDef(_def), m_isDead(_dead)
{
	strcpy_s(m_szName, sizeof(char) * 10, _class);
}

CCreature::CCreature(const CCreature& rhs) : m_iMaxHp(rhs.m_iMaxHp), m_iHp(rhs.m_iHp), m_iDps(rhs.m_iDps), m_iDef(rhs.m_iDef), m_isDead(rhs.m_isDead)
{
	memcpy(m_szName, rhs.m_szName, sizeof(m_szName));
}

//void CCreature::AddObserver(CObserver* observer)
//{
//	cObserver = observer;
//}
//
//void CCreature::RemoveObserver()
//{
//	SAFE_DELETE(cObserver);
//}
//
//void CCreature::NotifyObserver()
//{
//	cObserver->Update(this);
//}

void CCreature::Attack(CCreature* _enemy)
{
	_enemy->Hit(m_iDps - _enemy->GetDef());
}

void CCreature::Hit(int _damage)
{
	m_iHp -= _damage;
	if (m_iHp <= 0)
	{
		m_iHp = 0;
		m_isDead = true;
	}
}

const char* CCreature::GetName() const
{
	return m_szName;
}

int CCreature::GetMaxHp() const
{
	return m_iMaxHp;
}

int CCreature::GetHp() const
{
	return m_iHp;
}

int CCreature::GetDps() const
{
	return m_iDps;
}

int CCreature::GetDef() const
{
	return m_iDef;
}

void CCreature::SetName(const char* _name)
{
	strcpy_s(m_szName, sizeof(char) * 10, _name);
}

void CCreature::SetMaxHp(int _maxhp)
{
	m_iMaxHp = _maxhp;
}

void CCreature::SetHp(int _hp)
{
	m_iHp = _hp;
	if (_hp <= 0)
		m_isDead = true;
}

void CCreature::SetDps(int _dps)
{
	m_iDps = _dps;
}

void CCreature::SetDef(int _def)
{
	m_iDef = _def;
}

void CCreature::SetIsDead(bool _isDead)
{
	m_isDead = _isDead;
}

bool CCreature::GetIsDead() const
{
	return m_isDead;
}

void CCreature::Render() const
{
	cout << "\n이름 : " << GetName() << '\n' << "체력 : " << GetHp() << "\t" << "공격력 : " << GetDps();
	cout << "\n==========================================================";
}