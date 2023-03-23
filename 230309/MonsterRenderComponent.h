#pragma once
#include "RenderComponent.h"

class CMonsterGO;
class CMonsterRenderComponent : public CRenderComponent
{
public:
	void Init(CMonsterGO* _cPlayer);

	virtual void Render() override;

private:
	CMonsterGO* m_cMonster;
};

