#pragma once
#include "RenderComponent.h"

class CPlayerGO;
class CPlayerRenderComponent : public CRenderComponent
{
public:
	CPlayerRenderComponent(CPlayerGO* _cPlayer);
	void Init(CPlayerGO* _cPlayer);
	//virtual void Update() override;

	virtual void Render() override;

private:
	CPlayerGO* m_cPlayer;
};