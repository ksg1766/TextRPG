#pragma once
#include "RenderComponent.h"

class CPetGO;
class CPetRenderComponent : public CRenderComponent
{
public:
	CPetRenderComponent(CPetGO* _cPet);
	void Init(CPetGO* _cPet);
	//virtual void Update() override;

	virtual void Render() override;

private:
	CPetGO* m_cPet;
};

