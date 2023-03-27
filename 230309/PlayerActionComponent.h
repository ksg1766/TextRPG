#pragma once
#include "ActionComponent.h"

class CCreatureGO;
class CPlayerGO;
class CPlayerActionComponent : public CActionComponent
{
public:
	void Init(CCreatureGO* _cPlayer) override;
	void Attack(CCreatureGO* _cTarget) override;
	void Win(CCreatureGO* _cTarget);
	void Lose();

private:
	CPlayerGO* m_cPlayer;
};

