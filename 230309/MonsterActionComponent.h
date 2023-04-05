#pragma once
#include "ActionComponent.h"

class CMonsterGO;
class CMonsterActionComponent : public CActionComponent
{
public:
	CMonsterActionComponent(CCreatureGO* _cMonster);
	void Init(CCreatureGO* m_cMonster) override;

	typedef void (*PMECH)(CCreatureGO*, CCreatureGO*);
	void SetMech(PMECH _pmech) { m_pMech = _pmech; };

	void Attack(CCreatureGO* _cTarget) override;
	//void Attack(CCreatureGO* _cTarget, void (*_pmech)(CCreatureGO*, CCreatureGO*));
	//void Attack(CCreatureGO* _cTarget);

private:
	CMonsterGO* m_cMonster;
	PMECH m_pMech;
};

