#pragma once
#include "define.h"
#include "BaseCreature.h"
#include <vector>

class CObserver;
class CCreature : public CBaseCreature
{
public:
	explicit CCreature();
	explicit CCreature(const char* _class, int _maxHp, int _dps, int _def, bool _dead = false);
	CCreature(const CCreature& rhs);

	/*void AddObserver(CObserver* observer) override;
	void RemoveObserver() override;
	void NotifyObserver() override;*/
	// void RemoveObserver(CObserver* observer) override;
	// void NotifyObserver(CObserver* observer) override;

	void Attack(CCreature* _enemy);
	void Hit(int _damage);

	const char* GetName() const;
	int GetMaxHp() const;
	int GetHp() const;
	int GetDps() const;
	int GetDef() const;
	bool GetIsDead() const;

	void SetName(const char* _name);
	void SetMaxHp(int _maxhp);
	void SetHp(int _hp);
	void SetDps(int _dps);
	void SetDef(int _def);
	void SetIsDead(bool _isDead);

	void Render() const override;

	~CCreature(){}

private:
	//vector<Observer*> observers;
	CObserver* cObserver;
	char m_szName[10];
	int m_iMaxHp;
	int m_iHp;
	int m_iDps;
	int m_iDef;
	bool m_isDead;
};

