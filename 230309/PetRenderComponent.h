#pragma once
#include "RenderComponent.h"

class CPet;
class CPetRenderComponent : public CRenderComponent
{
public:
	void Init(CPetGO* _cPet);
	//virtual void Update() override;

	virtual void Render() override;

private:
	CPetGO* m_cPet;
};

