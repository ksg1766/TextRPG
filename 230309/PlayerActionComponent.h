#pragma once
#include "ActionComponent.h"

class CCreatureGO;
class CPlayerGO;
class CPlayerActionComponent : public CActionComponent
{
public:
	CPlayerActionComponent(CCreatureGO* _cPlayer);
	void Init(CCreatureGO* _cPlayer) override;
	void Attack(CCreatureGO* _cTarget) override;
	void MiniAttack(CCreatureGO* _cTarget);
	void Win(CCreatureGO* _cTarget);
	void Lose();

private:
	CPlayerGO* m_cPlayer;
};

