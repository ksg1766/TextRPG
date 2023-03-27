#pragma once
#include "ActionComponent.h"

class CMonsterGO;
class CMonsterActionComponent : public CActionComponent
{
public:
	void Init(CCreatureGO* m_cMonster) override;
	void Attack(CCreatureGO* _cTarget) override;

private:
	CMonsterGO* m_cMonster;
};

