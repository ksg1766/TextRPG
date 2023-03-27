#pragma once
#include "Component.h"

class CCreatureGO;
class CActionComponent : public Component
{
public:
	//virtual void Update();
	virtual void Init(CCreatureGO*) = 0;
	virtual void Attack(CCreatureGO*) = 0;
	// void Hit();
};