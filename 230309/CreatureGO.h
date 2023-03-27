#pragma once
#include "GameObject.h"
class CCreatureGO : public GameObject
{
public:
	CCreatureGO() : GameObject(), m_iMaxHp(0), m_iHp(0), m_iDps(0), m_iDef(0), m_state(STATE::NORMAL) {}
	CCreatureGO(const char* _szName) : GameObject(_szName), m_iMaxHp(0), m_iHp(0), m_iDps(0), m_iDef(0), m_state(STATE::NORMAL) {}
	
	virtual void Update() = 0;

#pragma region Set
	void SetHp(int _iHp) { if (0 >= _iHp) { m_iHp = 0; m_state = STATE::DEAD; } else m_iHp = _iHp; }
	void SetMaxHp(int _iMaxHp) { m_iMaxHp = _iMaxHp; }
	void SetDps(int _iDps) { m_iDps = _iDps; }
	void SetDef(int _iDef) { m_iDef = _iDef; }
	void SetState(STATE _state) { m_state = _state; }
#pragma endregion Set

#pragma region Get
	const int GetMaxHp() const { return m_iMaxHp; }
	const int GetHp() const { return m_iHp; }
	const int GetDps() const { return m_iDps; }
	const int GetDef() const { return m_iDef; }
	const STATE GetState() const { return m_state; }
#pragma endregion Get
protected:
	int m_iMaxHp;
	int m_iHp;
	int m_iDps;
	int m_iDef;
	STATE m_state;
};

