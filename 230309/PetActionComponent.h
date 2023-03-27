#pragma once
#include "ActionComponent.h"
#include "PetGO.h"

class CCreatureGO;
class CPetGO;
class CPetActionComponent : public CActionComponent
{
public:
	void Init(CCreatureGO* _cPet) override;
	void Attack(CCreatureGO* _cTarget) override;

private:
	CPetGO* m_cPet;
};

