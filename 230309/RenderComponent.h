#pragma once
#include "Component.h"

class CRenderComponent : public Component
{
public:
	//virtual void Update() = 0;
	virtual void Render() = 0;
};