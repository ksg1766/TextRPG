#pragma once
#include "Component.h"

class CCreatureGO;
class CActionComponent : public Component
{
public:
	//virtual void Update();
	virtual void Init() = 0;
	virtual void Attack() = 0;
	// void Hit();
};