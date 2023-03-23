#pragma once
#include "RenderComponent.h"

class CPlayerGO;
class CPlayerRenderComponent : public CRenderComponent
{
public:
	void Init(CPlayerGO* _cPlayer);
	//virtual void Update() override;

	virtual void Render() override;

private:
	CPlayerGO* m_cPlayer;
};