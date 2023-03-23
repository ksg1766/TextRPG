#pragma once
#include "Component.h"
class CObserverComponent : public Component
{
public:
	virtual void Update() = 0;
};