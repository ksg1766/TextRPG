#pragma once
#include "GameObject.h"
class CCreatureGO : public GameObject
{
public:
	CCreatureGO() : GameObject(), m_iHp(0), m_iDps(0), m_iDef(0), m_state(STATE::정상) {}
	CCreatureGO(const char* _szName) : GameObject(_szName), m_iHp(0), m_iDps(0), m_iDef(0), m_state(STATE::정상) {}
	
	virtual void Update() = 0;

	void SetHp(int _iHp);
	void SetDps(int _iDps);
	void SetDef(int _iDef);
	void SetState(STATE _state);

	const int GetHp() const { return m_iHp; }
	const int GetDps() const { return m_iDps; }
	const int GetDef() const { return m_iDef; }
	const STATE GetState() const { return m_state; }

protected:
	int m_iHp;
	int m_iDps;
	int m_iDef;
	STATE m_state;
};

