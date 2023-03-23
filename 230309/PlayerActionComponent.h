#pragma once
#include "ActionComponent.h"

class CCreatureGO;
class CPlayerGO;
class CPlayerActionComponent : public CActionComponent
{
public:
	void Init(CPlayerGO* _cPlayer);
	void Attack(CCreatureGO* _cTarget);

private:
	CPlayerGO* m_cPlayer;
};

