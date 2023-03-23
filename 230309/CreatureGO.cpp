#include "stdafx.h"
#include "CreatureGO.h"

void CCreatureGO::SetHp(int _iHp)
{
	m_iHp = _iHp;
}

void CCreatureGO::SetDps(int _iDps)
{
	m_iDps = _iDps;
}

void CCreatureGO::SetDef(int _iDef)
{
	m_iDef = _iDef;
}

void CCreatureGO::SetState(STATE _state)
{
	m_state = _state;
}

int CCreatureGO::GetHp()
{
	return m_iHp;
}

int CCreatureGO::GetDps()
{
	return m_iDps;
}

int CCreatureGO::GetDef()
{
	return m_iDef;
}
